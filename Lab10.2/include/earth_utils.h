/**
 * file: earth_utils.h
 * brief: handles parsing a lat/long csv file and conversion of that file to kml format
 * author: Richard T Swierk
 * assignment: Lab10.2
 * date: 11/13/2020
 * credit: Devin Paden
 */

#ifndef EARTH_UTILS_H
#define EARTH_UTILS_H
#include <string>
#include <fstream>

/**
 * brief: process a country captial csv file
 * date: 11/13/2020
 * return: returns the number of records processed
 * param inFile: ifstream to an opened and validated csv file
 * param kmlFileName: std:string containing the name of the kml file you wish to produce
 * param logFile: ofstream reference, validation of this file is expected
 */
int processCSV(std::ifstream& inFile, std::string kmlFileName);

#endif