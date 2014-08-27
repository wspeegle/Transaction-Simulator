#pragma once
#include <string>
#include <queue>
#include "Entity.h"
#include "Order.h"
#include "Seller.h"

class Order;
class Product;
class Inventory;
class Seller;
class Buyer : virtual public Entity
{
public:
	Buyer(const std::string &,const std::string &, double);
	virtual ~Buyer(){};
	void addSeller(Seller *);
	std::queue<Seller*> getSellers() const;
	void addOrder(Order *);
	void list();
	void step();
private: 
	std::queue<Order*>  Orders;
	std::queue<Seller*> Sellers;
};

