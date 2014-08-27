#include <string>
#include <queue>
#include <iostream>

#include "Entity.h"
#include "Buyer.h"
#include "Seller.h"
#include "Product.h"
#include "Inventory.h"
#include "Order.h"
#include "Retailer.h"

	
	Retailer::Retailer(const std::string& n,const std::string& i, double b)
	:Entity(n,i,b),
	Buyer(n,i,b),
	 Seller(n,i,b)
	{}

	Retailer::~Retailer()
	{}

	void Retailer::list()
	{
	Entity::list();
	Buyer::list();
	Seller::list();	
	}

	void Retailer::step()
	{
	Buyer::step();
	Seller::step();
	}
	





