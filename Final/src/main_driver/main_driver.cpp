/**
 *file: main_driver.cpp
 * brief: Main Library Driver
 * 
 * author: Richard T Swierk
 * assignment: Final
 * date: 12/9/2020
 * 
 */

#include "main.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
 
int main()
{
    //Setting Variables
    vector <string> scans;
    fstream tmpFile;
    string filename="tmp.txt";
    string ip, port;
    bool portGood=false;
    bool ipGood=false;
    cout << "Enter IP address: ";
    cin >> ip;
    cout << "Port range example: 22-56" << endl;
    cout << "Enter port number or range: ";
    cin >> port;
    
    /**
     * Brief: Check to make sure IP address entered is valid and if it can be pinged
     */
    if(ipCheck(ip)==true)
    {
        if(isAlive(ip)==true)
        {
            ipGood=true;
        }else{errorOut(2);}
    }else{errorOut(1);}


    /**
     * Brief: Check if port or port range entered is valid
     */
    if(portCheck(port)==true)
    {
        portGood=true;
    }else{errorOut(3);}

    /**
     * Brief: Checks if port on IP address is open
     */
    if(portGood==true && ipGood==true)
    {
        //Port scan IP address
        if(port.find("-")!=-1)
        {
            string start=port.substr(0,port.find("-"));
            string end=port.substr(port.find("-")+1,port.length());
            int pStart=std::stoi(start);
            int pEnd=std::stoi(end);
            isOpen(ip, pStart, pEnd, filename);
        }else{
            int pStart=std::stoi(port);
            int pEnd=std::stoi(port);
            isOpen(ip, pStart, pEnd, filename);
        }
        //Gets the output from the ports scanned
        tmpFile.open(filename,ios::in);
        if(tmpFile.is_open())
        {
            string info;
            while(getline(tmpFile, info))
            {
                scans.push_back(info);
            }
        }
        tmpFile.close();
        if(fileSize(filename)!=0)
        {
            cout<<"IP: "<<ip<<endl;
            for(string x : scans)
            {
                cout<<x<<endl;
            }
        }else{errorOut(4);}
        delTmp(filename);
        
    }

    return 0;
}