#ifndef STRBLOB_H
#define STRBLOB_H
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>
#include <stdexcept>
class StrBlobPtr;
class StrBlob {
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob() : data(std::make_shared<std::vector<std::string>>()) { }
	StrBlob(std::initializer_list<std::string>il);
	StrBlob(std::vector<std::string> *p);
	StrBlob(const StrBlob &);
	StrBlob& operator=(StrBlob&);
	size_type size() const { return data->size(); }
	bool empty()const { return data->empty(); }
	void push_back(const std::string&);
	void pop_back();
	//elements 访问
	std::string& front();
	const std::string& front()const;
	std::string& back();
	const std::string& back()const;
	//提供给strBlobPtr的接口

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string &msg)const;
	
};
#endif // !STRBLOB_H

