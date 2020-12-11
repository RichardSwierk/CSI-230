/**
 *file: main.cpp
 * brief: Main Library Implementation
 * 
 * author: Richard T Swierk
 * assignment: Final
 * date: 12/9/2020
 * 
 */
#include "main.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

/**
 * Function: fileSize
 * Brief: Get number of lines in a file
 */
int fileSize(string filename)
{
    fstream tmpFile;
    int count=0;
    tmpFile.open(filename,ios::in);
    if(tmpFile.is_open())
    {
        string info;
        while(getline(tmpFile, info))
        {
            count=+1;
        }
    }
    tmpFile.close();
    return count;
}

/**
 * Function: delTemp
 * Brief: Deletes the temp file that is made
 */
void delTmp(string filename)
{
    string str1="rm "+filename;
    const char *command1 =str1.c_str();
    system(command1);
}

/**
 * Function: isAlive
 * brief: Takes the ip address entered and checks if it can be pinged
 */
bool isAlive(string ip)
{
    bool isAlive=false;
    string str="ping -c2 -w2 "+ip+" > /dev/null 2>&1";
    const char *command =str.c_str();
    int x=system(command);
    if(x==0){isAlive=true;}
    return isAlive;
}

/**
 * Function: isOpen
 * Brief: Checks if the given port is open on the given ip address
 */
void isOpen(string ip, int pStart, int pEnd, string filename)
{
    string str;
    const char *command;
    for(int x=pStart;x<=pEnd;x++)
    {
        string p=to_string(x);
        str="nmap -p "+p+" "+ip+" | grep "+p+"/tcp >> "+filename;
        command=str.c_str();
        system(command);
    }
}

/**
 * Function: badIp
 * Brief: used when ip entered is not vaild
 */
void errorOut(int num)
{
    if(num==1)
    {
        cout << "IP address entered is not a vaild IP" << endl;
        exit(0);
    }else if(num==2){
        cout << "IP address did not respond to ping" << endl;
        exit(0);
    }else if(num==3){
        cout << "Invalid port range or port entered" << endl;
        exit(0);
    }else if(num==4){
        cout << "The IP is not allowing us to scan it's ports" << endl;
        exit(0);
    }
}

/**
 * Function: ipCheck
 * Brief: Checks if the IP address entered by the user is a valid IP address
 */
bool ipCheck(string ip)
{
    int first=0;
    int second=0;
    int third=0;

    bool ipGood=false;
    for(int x=0;x<3;x++)
    {
        if(first==0)
        {
            first=ip.find(".");
        }else if(second==0)
        {
            second=ip.find(".",first+1);
        }else if(third==0)
        {
            third=ip.find(".",second+1);
        }
    }

    string ipOne=ip.substr(0,first);
    string ipTwo=ip.substr(first+1, second-(first+1));
    string ipThree=ip.substr(second+1, third-(second+1));
    string ipFour=ip.substr(third+1,ip.length());

    if(first!=-1 && second!=-1 && third!=-1)
    {
        if(ip.length()>=7 && ip.length()<=15)
        {
            if(isInt(ipOne)==true && isInt(ipTwo)==true && isInt(ipThree)==true && isInt(ipFour)==true)
            {
                int ip1=std::stoi(ipOne);
                int ip2=std::stoi(ipTwo);
                int ip3=std::stoi(ipThree);
                int ip4=std::stoi(ipFour);
                if(ip1>0 && ip1<=255 && ip2>=0 && ip2<=255 && ip3>=0 && ip3<=255 && ip4>0 && ip4<=255)
                {
                    ipGood=true;
                }
            }
        }
    }

    return ipGood;
}

/**
 * Function: isInt
 * Brief: Checks if a substring can be converted to an int
 */
bool isInt(string ip)
{
    bool good;
    if(ip.empty() || (!isdigit(ip[0])) )
    {
        good=false;
    }else{
        good=true;
    }
    return good;
}

/**
 * Function: portCheck
 * Brief: Checks if the user entered a valid port or port range
 */
bool portCheck(string port)
{
    bool portGood=false;

    if(port.find("-")!=-1)
    {
        if(port.find("-")!=0 && port.find("-")!=port.length())
        {
            string start=port.substr(0,port.find("-"));
            string end=port.substr(port.find("-")+1,port.length());
            if(isInt(start)==true && isInt(end)==true)
            {
                int pStart=std::stoi(start);
                int pEnd=std::stoi(end);
                if(pStart<pEnd)
                {
                    portGood=true;
                }
            }
        }
    }else{
        if(isInt(port)==true)
        {
            portGood=true;
        }
    }
    return portGood;
}