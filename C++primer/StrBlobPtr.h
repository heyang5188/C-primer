#ifndef STRBLOB_PTR_H
#define STRBLOB_PTR_H
#include "StrBlob.h"
#include <memory>
#include <vector>
#include <string>
class StrBlobPtr {
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
public:
	StrBlobPtr() :curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	StrBlobPtr(const StrBlob &a, size_t sz = 0) :wptr(a.data), curr(sz) {}
	std::string& operator* () const;
	std::string* operator->()const;
	std::string& deref()const;
	std::string& deref(int off)const;
	StrBlobPtr& incr();
	StrBlobPtr& decr();
private:
	std::shared_ptr<std::vector<std::string>>
		check(size_t, const std::string&)const  ;
	std::weak_ptr<std::vector<std::string>> wptr;
	size_t curr;
};
#endif // !STRBLOB_PTR_H


