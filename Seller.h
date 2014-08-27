#pragma once
#include <vector>
#include <string>

#include <queue>
#include "Buyer.h"
#include "Inventory.h"

class Buyer;
class Order;
class Product;
class Inventory;
class Seller: virtual public Entity
{
public:
	Seller(const std::string &, const std::string &, double);
	virtual ~Seller(){};
	void addBuyer(Buyer*);
	std::vector<Buyer*>  getBuyers() const;
	void setInventory(Inventory*);
	Inventory* getInventory();
	void list();
	void step();
	double fillOrder(Order*);
private: 
	std::vector<Buyer*> Buyers;
	Inventory* inventory;
	};

