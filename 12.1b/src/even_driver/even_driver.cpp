/**
 *file: even_driver.cpp
 * brief: Even Library Driver
 * 
 * author: Richard T Swierk
 * credit: https://www.fayewilliams.com/2015/07/07/creating-a-shared-library/
 * assignment: Lab 12.1
 * date: 11/30/2020
 * 
 */

#include "even.h"
#include <iostream>
 
using namespace std;
 
int main()
{
    while (1)
    {
        int num;
        cout << "Enter integar: ";
        cin >> num;
        
        if(isEven(num))
        {
            cout << "Number is even" << endl;
        }else{
            cout << "Number is odd" << endl;
        }
    }
    return 0;
}