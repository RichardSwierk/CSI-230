/**
 *file: even.cpp
 * brief: Even Library Implementation
 * 
 * author: Richard T Swierk
 * assignment: Lab 12.1
 * date: 11/30/2020
 * 
 */
#include "even.h"

bool isEven(int num)
{
  bool ret = true;
  if(num%2==0){ret=true;}else{ret=false;}
  return ret;
}