/**
 * file: logger.cpp
 * author: Richard T Swierk
 * assignment: Lab 10.2
 * date: 11/12/2020
 * credit: Devin Paden
 */

#include "logger.h"
#include <string>
#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

bool log(std::string msg, std::string programName, std::ofstream& logFile)
{
    std::string strTime;

    //get the time
    time_t logTime=time(0);
    strTime=ctime(&logTime);

    //time off the newline
    int timeSize=strTime.size();
    if(timeSize)
    {
        strTime[timeSize-1]=' ';
    }
    //get the pid
    pid_t pid=getpid();
    //get hostname
    char hostname[HOST_NAME_MAX+1];
    gethostname(hostname, HOST_NAME_MAX+1);
    if(logFile)
    {
        //write the log
        logFile << strTime << hostname << " " << programName << "[" << pid << "]: " << msg << std::endl;
        return true;
    }
}