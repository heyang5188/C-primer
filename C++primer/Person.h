#ifndef PERSON_H
#define PERSON_H
#include <iostream>
#include <string>
using namespace std;
class Person{
private:
	string strName;
	string strAddress;
public:
	string getName()const { return strName; }
	string getAddress()const { return strAddress; }
};

#endif // !PERSON_H
#pragma once
