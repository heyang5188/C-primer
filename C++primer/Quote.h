#ifndef QUOTE_H
#define QUOTE_H
#include <string>
class Quote {
	friend double print_totle(std::ostream& os, const Quote &item, std::size_t t);
public :
	Quote() = default;
	Quote(const std::string &book, double sales_price):bookNo(book),price(sales_price){}
	std::string isbn() const { return bookNo; }
	Quote& operator=(const Quote&rhs); 
	//return sales_data
	virtual double net_price(std::size_t n) const
	{
		return n*price;
	}
	virtual void debug() const;
	virtual ~Quote() = default; //基类通常都需要定义一个析构函数，即使该函数不执行任何实际操作也是如此
private:
	std::string bookNo;
protected:
	double price = 0.0;
};
class Disc_quote :public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const std::string&, double, std::size_t, double);
	Disc_quote(const Disc_quote &rhs);
	Disc_quote& operator=(const Disc_quote&);
	double net_price(std::size_t) const = 0;
	
protected:
	std::size_t min_qty = 0;//使用最低折扣的最低数量
	double discount = 0.0;
};
class Bulk_quote : public Disc_quote {
public:
	using Disc_quote::Disc_quote;
	Bulk_quote() = default;
	Bulk_quote(const Bulk_quote &);
	Bulk_quote& operator=(const Bulk_quote&rhs);
	double net_price(std::size_t) const override;
	virtual void debug()const  override;


};
class half_quote : public Disc_quote {
public:
	half_quote() = default;
	half_quote(const std::string&, double, std::size_t, double);
	half_quote(const half_quote &rhs);
	half_quote& operator=(const half_quote&rhs);
	double net_price(std::size_t) const  override;
	virtual void debug()const  override;

};
#endif // !QUOTE_H

