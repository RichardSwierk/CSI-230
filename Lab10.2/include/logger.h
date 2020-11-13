/**
 * Author: Richard T Swierk
 * Date: 11/12/2020
 * Assingment: Lab10.2
 * Credit: Devin Paden
 * File: logger.h
 */

#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <fstream>

/**
 * brief: creates a discrete syslog message 
 * date: 11/12/2020
 * return: returns a boolean indicating the message was written ok
 * param msg: std:string containing syslog message
 * param programName: std:string containing the programName
 * param logFile: of stream reference, validation of this file is expected
 */
bool log(std::string msg, std::string programName, std::ofstream& logFile);

#endif