#include <string>
#include <queue>
#include <iostream>
#include <set>
#include "Entity.h"
#include "Buyer.h"
#include "Seller.h"
#include "Product.h"
#include "Inventory.h"
#include "Order.h"
#include "Retailer.h"

	Seller::Seller(const std::string&  n,const std::string& i, double b)
	:Entity(n,i,b)
	{}

//	Seller::~Seller()
//	{}	
	
	void Seller::addBuyer(Buyer* b)
	{
	Buyers.push_back(b);
	}

	std::vector<Buyer*> Seller::getBuyers() const
	{
	return Buyers;
	}

	void Seller::setInventory(Inventory* I)
	{
	 inventory = I;
	}
	
	Inventory* Seller::getInventory()
	{
		return inventory;
	}	

	void Seller::list()
	{
	Entity::list();
	std::cout << "Inventory:" << std::endl;
	inventory->showInventory();
	std::cout << "and the following buyers:" << std::endl;
	int bSize = Buyers.size();
	for(int i = 0; i < bSize; i++)
		{
		std::cout << (Buyers.at(i))->getName() << std::endl;	
		}
	

	}
	void Seller::step()
	{
		std::set<Product*> inventory_ = inventory->Inventory::getInventory();
		for(std::set<Product*>::iterator in = inventory_.begin(); in != inventory_.end(); ++in)
		{
			Product* p = *in;
			if((p->getQuantity()) < (p->getTargetQuantity()))
			{
				double expense = ((p->getTargetQuantity() * p->getQuantity()) * (p->getPrice() * .5));
				if(expense < getBalance())
				{
				p->setQuantity(p->getTargetQuantity());
				
				double tempBal = getBalance() - expense;
				setBalance(tempBal);
				}
			}
		}

 
	}


	double Seller::fillOrder(Order* o)
	{
		
		double sale = 0;
		std::vector<Product*> proList = o->getProductList();
		int oSize = proList.size();
		
		for(int i =0; i< oSize; i++)
		{
			Product* cp = proList.at(i);
			std::string cpSKU = cp->getSKU();
			//std::set<Product*> inventory_ = inventory->Inventory::getInventory();
			Product* invProd = inventory->Inventory::getProductBySku(cpSKU);

			if(invProd != NULL)
				{
					
					int orderQuan = cp->getQuantity();
					int invenQuan = invProd->getQuantity();
					if(orderQuan <= invenQuan)
					{
						sale = sale + (cp->getPrice() * orderQuan);
						invProd->setQuantity(invenQuan - orderQuan);
						cp->setQuantity(0);
					}
					else{
						sale = sale + (cp->getPrice() * invenQuan);
						invProd->setQuantity(0);
						cp->setQuantity(orderQuan - invenQuan);
					    }
					}
		}

	setBalance(getBalance() + sale);
	
	return sale;

	}

