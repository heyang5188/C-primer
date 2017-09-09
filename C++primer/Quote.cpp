#include "stdafx.h"
#include "Quote.h"
#include "iostream"



Bulk_quote::Bulk_quote(const Bulk_quote &rhs):Disc_quote(rhs)
{
}

Bulk_quote& Bulk_quote::operator=(const Bulk_quote & rhs)
{

	std::cout << "Bulk_quote operator called" << std::endl;
	Disc_quote::operator=(rhs);
	return *this;
}

double Bulk_quote::net_price(std::size_t cnt) const
{
	std::cout << "called of Bulk_quote virturl function :" << std::endl;
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
	
}

void Bulk_quote::debug() const
{
	std::cout << "This is Bulk class's debug function" << std::endl;
	Quote::debug();
	std::cout << "called base debug" << min_qty << " discount is :" << discount << std::endl;
	std::cout << price << std::endl;
}


double print_totle(std::ostream & os, const Quote & item, std::size_t t) 
{
	double ret = item.net_price(t);
	os << "ISBN: " <<item.isbn()<<" number: " <<t << " total due:" << ret << std::endl;
	return ret;
	
}

half_quote::half_quote(const std::string &book, double p, std::size_t t, double d):Disc_quote(book,p,t,d)
{

}

half_quote::half_quote(const half_quote & rhs) :Disc_quote(rhs)
{
	
}

half_quote & half_quote::operator=(const half_quote & rhs)
{
	std::cout << "half_quote operator called" << std::endl;
	Disc_quote::operator=(rhs);
	return *this;
}

double half_quote::net_price(std::size_t t) const
{
	
	if (t >= min_qty)
		return t*price + (t - min_qty)*(1 - discount)*price;
	else
		return t*price;
}

void half_quote::debug() const
{
	std::cout << "This is half class's debug function" << std::endl;
	Quote::debug();
	std::cout << "called base debug" << min_qty << " discount is :" << discount << std::endl;
	std::cout << price << std::endl;
}

Quote & Quote::operator=(const Quote & rhs)
{
		std::cout << "Basc operator called" << std::endl;
		bookNo = rhs.bookNo;
		price = rhs.price;
		return *this;
}

void Quote::debug() const
{
	std::cout << "This is base class's debug function" << std::endl;
	std::cout << "bookNo is :" << bookNo << " price is :" << price << std::endl;
}

Disc_quote::Disc_quote(const std::string &book, double d, std::size_t t, double discount):Quote(book,d),min_qty(t),discount(discount)
{

}

Disc_quote::Disc_quote(const Disc_quote & rhs):Quote(rhs)
{
	min_qty = rhs.min_qty;
	discount = rhs.discount;
}

Disc_quote & Disc_quote::operator=(const Disc_quote &rhs)
{
	std::cout << "Disc_quote operator called" << std::endl;
	Quote::operator=(rhs);
	min_qty = rhs.min_qty;
	discount = rhs.discount;
	return *this;
}
