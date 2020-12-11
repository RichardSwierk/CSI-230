/**
 *file: main_driver.cpp
 * brief: Main Library Driver
 * 
 * author: Richard T Swierk
 * assignment: Final
 * date: 12/9/2020
 * 
 */

//#include "main.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
int main()
{

    // string str="nmap -p 65 1.1.1.1 | grep 65 2>&1";
    // const char *command =str.c_str();
    // int x=system(command);
    // if(x==0)
    // {
    //     cout<<"open"<<endl;
    // }else{
    //     cout<<"closed"<<endl;
    // }
    
    string ip;
    string port;
    cout << "Enter IP address: ";
    cin >> ip;
    cout << "Port range example: 22-56" << endl;
    cout << "Enter port number or range: ";
    cin >> port;

    bool portGood=false;
    bool ipGood=false;
    
    /**
     * Brief: Check to make sure IP address entered is valid and if it can be pinged
     */
    if(ipCheck(ip)==true)
    {
        if(isAlive(ip)==true)
        {
            cout<<"Ping response"<<endl;
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
            for(int x=pStart;x<=pEnd;x++)
            {
                if(isOpen(ip, port)==true)
                {
                    cout<<ip<<":"<<port<<"     Open"<<endl;
                }else{
                    cout<<ip<<":"<<port<<"     Closed"<<endl;
                }
            }
        }else{
            if(isOpen(ip, port)==true)
            {
                cout<<ip<<":"<<port<<"     Open"<<endl;
            }else{
                cout<<ip<<":"<<port<<"     Closed"<<endl;
            }
        }
    }

    return 0;
}