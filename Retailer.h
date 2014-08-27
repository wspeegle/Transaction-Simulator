#pragma once
#include "Buyer.h"
#include "Seller.h"
#include "Entity.h"
#include "Product.h"
#include "Order.h"
#include "Inventory.h"

class Product;
class Order;
class Inventory;
class Entity;
class Buyer;
class Seller;
class Retailer :public Buyer,public Seller
{
public:
	Retailer(const std::string&,const std::string&, double);
	 ~Retailer();
	void list();
	void step();
};
