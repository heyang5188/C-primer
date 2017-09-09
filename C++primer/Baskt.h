#ifndef BASKET_H
#define BASKET_H
#include <memory>
#include <set>
#include "Quote.h"
#include <iostream>
class Basket {
public:
	void add_item(const std::shared_ptr<Quote> &sale);

	double total_receipt(std::ostream&)const;

private:
	static bool compare(const std::shared_ptr<Quote> &lhs,
						const std::shared_ptr<Quote>&rhs);
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };

};

#endif // !BASKET_H
