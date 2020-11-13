/**
 * brief: Implements google earth file handling utilities
 * author: Richard T Swierk
 * assignment: Lab10.2
 * date: 11/13/2020
 * credit: Deven Paden
 */

#include "earth_utils.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int processCSV(std::ifstream& inFile, std::string kmlFileName)
{
    int recordCount{};
    string strCountry, strCapital, strLat, strLong;
    string strLine;

    if(inFile)
    {
        ofstream fKml;
        //create file
        fKml.open(kmlFileName, ios_base::app);
        fKml << "<?xml version=" << '"' << "1.0" << '"' << " encoding=" << '"' << "UTF-8" << '"' << "?>\n";//write kml header to file
        fKml << "<kml xmls=" << '"' << "http://www.opengis.net/kml/2.2" << '"' << ">\n" << "    <Document>\n";//write kml header to file
        getline(inFile, strLine);
        while(getline(inFile, strLine))
        {
            std::stringstream s_stream(strLine);
            std::getline(s_stream, strCountry, ',');
            std::getline(s_stream, strCapital, ',');
            std::getline(s_stream, strLat, ',');
            std::getline(s_stream, strLong, ',');
            //std::cout << strCountry << "~" << strCapital << "~" << strLat << "~" << strLong << std::endl;
            recordCount+=1;
            //write to the file
            fKml << "       <Placemark>\n" << "         <name>" << strCapital << ", " << strCountry << "</name>\n";
            fKml << "           <Point>\n" << "             <coordinates>" << strLong << "," << strLat << "</coordinates>\n" << "           </Point>\n" << "        </Placemark>\n";
        }
        fKml << "   </Document>\n" << "</kml>";
        fKml.close();
    }
    return recordCount;
}