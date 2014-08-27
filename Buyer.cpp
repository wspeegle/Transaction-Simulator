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

	Buyer::Buyer(const std::string &n ,const std::string &i, double b)
	:Entity(n,i,b)
	{}

	//virtual Buyer::~Buyer()
	//{
	//}

	void Buyer::addSeller(Seller* s)
	{
	Sellers.push(s);
	}
	
	std::queue<Seller*> Buyer::getSellers() const
	{
	return Sellers;
	}
	
	void Buyer::addOrder(Order* o)
	{
	Orders.push(o);
	}
		
	void Buyer::list()
	{
	Entity::list();
	int OrdSize = Orders.size();
	std::cout << "Orders:" << std::endl;
	for(int i = 0; i<OrdSize; i++)
	{
	Order* op = Orders.front();	
	op->display();
	Orders.pop();
	Orders.push(op);
	}
	
	
	int SelSize = Sellers.size();

	std::cout << "Sellers: " << std::endl;
	for(int i =0; i<SelSize; i++)
	{
	Seller* sp = Sellers.front();
	std::cout << sp->getName() << std::endl;
	Sellers.pop();
	Sellers.push(sp);
	}
	

	}

	void Buyer::step()
	{
		double expense = 0; 
		int oSize = Orders.size();

		if(oSize)
		{

			for(int i = 0; i< oSize; i++)
			{
				Order* cOrder = Orders.front();
				Orders.pop();
				if(Sellers.size())
				{
				int sSize = Sellers.size();

				for(int j = 0; j < sSize; j++)
				{
					Seller* cSeller = Sellers.front();
					Sellers.pop();
					double order = cSeller->fillOrder(cOrder);
					expense = expense + order;
					Sellers.push(cSeller);
				}
				
				Orders.push(cOrder);
			}
		}
		
		setBalance(getBalance() - expense);
		setBalance(getBalance() * 1.1);
		for(int i = 0; i< oSize; i++)
		{
			Order* cOrder = Orders.front();
			Orders.pop();
			std::vector<Product*> prodList = cOrder->getProductList();
			int pSize = prodList.size();
			for(int j=0; j< pSize; j++){
			Product* cp = prodList.at(j);
			cp->setQuantity(cp->getQuantity() + 4);
			}
			Orders.push(cOrder);
		}

	}
	}
