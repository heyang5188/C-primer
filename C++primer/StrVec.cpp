
#include "stdafx.h"
#include "StrVec.h"
#include <memory>
StrVec::StrVec(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}
StrVec::~StrVec()
{
	free();
}

StrVec & StrVec::operator=(const StrVec &s)
{
	auto newdata = alloc_n_copy(s.begin(), s.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	return *this;
}

StrVec & StrVec::operator=( StrVec &&vec)noexcept
{
	if (this != &vec) {
		free();
		elements = vec.elements;
		first_free = vec.first_free;
		cap = vec.cap;
		vec.elements = vec.cap = vec.first_free = nullptr;
	}
	return *this;
}

StrVec::StrVec(std::initializer_list<std::string> il)
{
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::StrVec(const StrVec &&vec)
{
	elements = vec.elements;
	first_free = vec.elements;
	cap = vec.cap;
}

void StrVec::push_back(const std::string &s)
{
	 cnk_n_alloc();
	 alloc.construct(first_free++, s);
}

std::pair<std::string*, std::string*> StrVec::alloc_n_copy(const std::string *begin, const std::string *end)
{
	//alloc the space to data
	auto data = alloc.allocate(end-begin);
	
	return std::pair<std::string*, std::string*>(data,std::uninitialized_copy(begin,end,data));
}

void StrVec::free()
{
	if (elements)
		for (auto p = first_free; p != elements;)
			alloc.destroy(--p);
	alloc.deallocate(elements, cap - elements);//�ͷſռ䡣
}

void StrVec::reallocate()
{
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i != size(); ++i)
		alloc.construct(dest++, std::move(*elem++));
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

bool operator==(const StrVec &lhs, const StrVec &rhs)
{
	bool x;
	if (lhs.size() == rhs.size()) {
			auto lbegin = lhs.begin();
			auto rbegin = rhs.begin();
			while (lbegin != lhs.end())
				if (*lbegin++ == *rbegin++){
					x = true;
				}
				else{
					return false;
				}

		}
	else
		x = false;

	return x;
}

bool operator!=(StrVec &lhs, StrVec &rhs)
{
	return !(lhs == rhs);
}
