#include "stdafx.h"
#include "StrBlob.h"
#include <memory>



StrBlob::StrBlob(std::initializer_list<std::string>il) :data(std::make_shared <std::vector<std::string>>(il))
{

}
StrBlob::StrBlob(std::vector<std::string>* p):data(p)
{
	
}

StrBlob::StrBlob(const StrBlob &p):data(std::make_shared<std::vector<std::string>>(*data))
{
}

StrBlob & StrBlob::operator=(StrBlob &rhs)
{
	data = std::make_shared<std::vector<std::string>>(*rhs.data);
	return *this;
}

void StrBlob::push_back(const std::string &rhs)
{
	data->push_back(rhs);
}

void StrBlob::pop_back()
{
	check(0, "empty StrBlob");
	data->pop_back();
}

std::string & StrBlob::front()
{
	check(0, "empty StrBlob");
	return data->front();
}

const std::string & StrBlob::front() const
{
	check(0, "empty StrBlob");
	return data->front();
}

std::string & StrBlob::back()
{
	check(0, "empty StrBlob");
	return data->back();
}

const std::string & StrBlob::back() const
{
	check(0, "empty StrBlob");
	return data->back();
}

void StrBlob::check(size_type i, const std::string & msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}
