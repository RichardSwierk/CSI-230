/**
 * lab10.1 
 * main.cpp
 * Author: Richard T Swierk
 * Data: 11/9/2020
 * 
 */ 

#include <iostream>
#include <vector>
#include <string>
#include "util.h"
using namespace std;

int main()
{
    vector <string> strVec; //create vector of strings defined as strVec
    strVec.push_back("first"); //add string object 1
    strVec.push_back("second"); //add string object 2
    strVec.push_back("third"); //add string object 3
    strVec.push_back("fourth"); //add string object 4
    strVec.push_back("fifth"); //add string object 5
    cout << "Dumping the Vector of 5 Elements: ";
    for(auto strObj : strVec) // loop through the strVec vector
    {
        cout << strObj << " ";
    }
    cout << endl;// end the output
    cout << "calling randomElement" << endl;
    cout << randomElement(strVec) << endl;//call the randomElement function with strVec vector as input

    cout << "Dumping the vector of doubles" << endl;
    vector <double> doubleVec; //create vector of doubles defined as doubleVec
    doubleVec.push_back(1.2); //add double value 1
    doubleVec.push_back(5.8); //add double value 2
    doubleVec.push_back(4.1); //add double value 3
    doubleVec.push_back(6.6); //add double value 4
    doubleVec.push_back(7.9); //add double value 5
    for(auto vecDoub : doubleVec)// loop through the doubleVec vector
    {
        cout << vecDoub << " ";
    }
    cout << endl;//end the output
    cout << "Sum:" << sum(doubleVec) << endl;//call the sum function
    cout << "Average:" << avg(doubleVec) << endl;// call the avg funtion
    cout << "Lowest:" << lowest(doubleVec) << endl;//call the lowest function

    string str{"This is my multi word string"}; // multi word string
    cout << "Calling camelCase with: " << str << endl;
    cout << "strMessage after camelCase: " << camelCase(str) << endl; // call the camelCase function and give it he str vector as input

    return EXIT_SUCCESS;
}