/**
 *file: main.h 
 * brief: Function declarations
 * 
 * author: Richard T Swierk
 * assignment: Final
 * date: 12/9/2020
 * 
 */

#ifndef MAIN_H
#define MAIN_H
#include <string>
using namespace std;
/**
 * Function: isAlive
 * brief: Takes the ip address entered and checks if it can be pinged
 */
bool isAlive(string ip);

/**
 * Function: isOpen
 * Brief: Checks if the given port is open on the given ip address
 */
void isOpen(string ip, int pStart, int pEnd, string filename);

/**
 * Function: badIp
 * Brief: used when ip entered is not vaild
 */
void errorOut(int num);

/**
 * Function: ipCheck
 * Brief: Checks if the IP address entered by the user is a valid IP address
 */
bool ipCheck(string ip);

/**
 * Function: isInt
 * Brief: Checks if a substring can be converted to an int
 */
bool isInt(string ip);

/**
 * Function: portCheck
 * Brief: Checks if the user entered a valid port or port range
 */
bool portCheck(string port);

/**
 * Function: delTemp
 * Brief: Deletes the temp file that is made
 */
void delTmp(string filename);

/**
 * Function: fileSize
 * Brief: Get number of lines in a file
 */
int fileSize(string filename);

#endif