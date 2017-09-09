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
		//����֪����ǰ��basket��������һ���ùؼ��ֵ�Ԫ��
		//��ӡ���鼮�еĶ�Ӧ��Ŀ
		sum += print_totle(os,**iter,items.count(*iter));
	}
	os << "Total Sales: " << sum << std::endl;
	return sum;
}
