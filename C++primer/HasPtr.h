#ifndef HASPTR_H
#define HASPTR_H
#include <iostream>
#include <string>
class HasPtr {
	friend void swap(HasPtr &lhs, HasPtr &rhs);
public:
	HasPtr(const std::string &s = std::string())
		:ps(new std::string(s)), i(0) {	}
	HasPtr(const HasPtr &hp)
		:ps(new std::string(*hp.ps)), i(hp.i) {	}
	HasPtr& operator=(const HasPtr &hp)
	{
		auto *newptr = new std::string(*hp.ps);
		delete ps;
		ps = newptr;
		i = hp.i;
		return *this;
	}
	~HasPtr() { delete ps; }
	std::string& show() {
		return *ps;
	}
	bool operator<(const HasPtr& hp)const {
		return *ps > *hp.ps;
	}
private:
	std::string *ps;
	int i;

};
inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
	using std::swap;
	std::cout << "exchange " << *lhs.ps << "and " << *rhs.ps << std::endl;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}

#endif // HASPTR_H

