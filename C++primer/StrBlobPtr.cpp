#include "stdafx.h"
#include "StrBlobPtr.h"

std::string & StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

std::string * StrBlobPtr::operator->() const
{
	return & this->operator*();
}

std::string & StrBlobPtr::deref() const
{
	auto p = check(curr, "derefrence pass end");
	return (*p)[curr];
}

std::string & StrBlobPtr::deref(int off) const
{
	auto p = check(curr + off, "derefernce pass end");
	return (*p)[curr + off];
}

StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment pass end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr & StrBlobPtr::decr()
{
	--curr;
	check(-1, "curr is 0 ");
	return *this;
}

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(size_t i, const std::string &msg) const
{
	auto ret = wptr.lock();//检查 vector还在不在
	if (!ret)
		throw std::runtime_error("unbound StrBlobPtr");
	if (i >= ret->size())
		throw std::out_of_range(msg);
	return ret;
}
inline
bool eq(const StrBlobPtr &lhs, const StrBlobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}
