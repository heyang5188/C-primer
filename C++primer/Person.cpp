#include "stdafx.h"
#include  <iostream>
#include "Person.h"

std::istream &read(std::istream &is, Person &per)
{
	is >> per.getName() >> per.getAddress();
	return is;
}
std::ostream &print(std::ostream &os, const Person &per)
{
	os << per.getName() << per.getAddress();
	return os;
}
