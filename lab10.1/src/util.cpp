/**
 * lab10.1
 * util.cpp
 */

#include "util.h"
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

string randomElement(vector<string> vec)
{
    srand((int) time(0)); //without this then one does not get a random number
    int ran=rand() % vec.size();// Get a random number between 0 and the size of the vector vec
    return vec[ran];// return the string in the position picked by the random number
}

double sum(vector<double> num)
{
    double sumAll=0;
    for(int x=0;x<num.size();x++)// loop through the size of the vector num
    {
        sumAll=sumAll+num[x];//add the previous value of vector element to the current element
    }
    return sumAll;//return the sum of the doubles
}

double avg(vector<double> num)
{
    return sum(num)/num.size();// call the sum function to get the sum of all the numbers in the vector num and then divide that number by the size of the vector
}

double lowest(vector<double> num)// this function finds the lowest double in the vector of doubles
{
    double low=num[0];
    for(int x=0;x<num.size();x++)
    {
        if(low>num[x])
        {
            low=num[x];
        }
    }
    return low;
}

string camelCase(string str)//this function switches the case of the first letter in every word and removes all the spaces
{
    string camelCaseStr;
    for(int x=0;x<str.length();x++)
    {
        int loc=str.find(" ");
        if(islower(str[loc+1]))
        {
            str[0]=char(toupper(str[0]));
        }else{
            str[0]=char(tolower(str[0]));
        }
        if(loc!=0)
        {
            camelCaseStr+=str.substr(0,loc);
            str.erase(0,loc+1);
        }else{
            camelCaseStr+=str.substr(0,str.length());
            str.erase(0,str.length());
        }
    }
    return camelCaseStr;
}