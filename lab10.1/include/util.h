/**
 * lab10.1
 * util.h
 */
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>
using namespace std;
#include <vector>

string randomElement(vector<string> vec);//returns a random element of the vector input variable
double sum(vector<double> num); //returns the sum of doubles
double avg(vector<double> num); //returns the average of doubles
double lowest(vector<double> num); //returns the smallest doubles value
string camelCase(string str); // change the first letter of each word to the opposite case and delete spaces

#endif
