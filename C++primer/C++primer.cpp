#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include <deque>
#include <forward_list>
#include <stack>
#include <algorithm>
#include <functional>
#include <iterator>
#include <map>
#include <set>
#include <utility>
#include <memory>
#include "StrVec.h"
#include "String.h"
#include "Sales_data.h"
#include "StrBlob.h"
#include "StrBlobPtr.h"
#include "Quote.h"
using namespace std;
std::allocator<char> String::a;
std::allocator<std::string> StrVec::alloc;
void  debug( const Quote & item)
{
	item.debug();
}

int  main()
{
	vector<shared_ptr<Quote>> vec;
	Quote qu1("happy",100);
	Bulk_quote qu2("happd", 100, 10, 0.99);
	half_quote qu3("bsgoas", 100, 10, 0.1);
	Bulk_quote qu4("nimabsif", 100, 10, 0.7);
	half_quote qus("alsf", 100, 10, .2);
	vec.push_back(make_shared<Bulk_quote>(qu2));
	vec.push_back(make_shared<half_quote>(qu3));
	vec.push_back(make_shared<Quote>(qu4));
	vec.push_back(make_shared<half_quote>(qus));
	for (auto &m : vec){
		double sum = 0;
		sum += m->net_price(12);
		cout << sum << endl;
	}
		
	system("pause");
    return 0;
}

