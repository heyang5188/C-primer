#include "stdafx.h"
#include "Baskt.h"

void Basket::add_item(const std::shared_ptr<Quote>& sale)
{
	items.insert(sale);
}

double Basket::total_receipt(std::ostream & os) const
{
	double sum;
	for (auto iter = items.cbegin();
		iter != items.cend();
		iter = items.upper_bound(*iter)){ 
		//我们知道当前的basket中至少有一个该关键字的元素
		//打印该书籍中的对应项目
		sum += print_totle(os,**iter,items.count(*iter));
	}
	os << "Total Sales: " << sum << std::endl;
	return sum;
}
