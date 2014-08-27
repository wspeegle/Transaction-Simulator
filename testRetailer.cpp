#include <iostream>
#include <set>
#include "Seller.h"
#include "Buyer.h"
#include "Retailer.h"
#include "Inventory.h"
using namespace std;

Inventory * stockInventory(int type);
Order * createOrder(int type);

int main()
{

 Seller *willieWonka;
 Retailer *momAndPop;
 Retailer *jackNjill;
 Buyer *cust1, *cust2, *cust3, *cust4;

 /* create a Supplier (i.e., Seller, Manufacturer)  */
 willieWonka = new Seller("Willie Wonka", "001", 1000000);

 /* create some Retailers */
 momAndPop = new Retailer("Mom's candy shop","002", 10000);
 jackNjill = new Retailer("J&J Sweets ", "003", 20000);

 /* create some Buyers (Customer) */
 cust1 = new Buyer("Charlie","004", 25.00);
 cust2 = new Buyer("Sally","005", 26.000);
 cust3 = new Buyer("Mary","006", 27.00);
 cust4 = new Buyer("Bob","007", 28.00);

 /* hook them up */

 willieWonka->addBuyer(momAndPop);
 willieWonka->addBuyer(jackNjill);
 momAndPop->addSeller(willieWonka);
 jackNjill->addSeller(willieWonka);

 momAndPop->addBuyer(cust1);
 cust1->addSeller(momAndPop);

 momAndPop->addBuyer(cust2);
 cust2->addSeller(momAndPop);

 jackNjill->addBuyer(cust3);
 cust3->addSeller(jackNjill);

 jackNjill->addBuyer(cust4);
 cust4->addSeller(jackNjill);

 /* provision the supplier and the retailers*/
 willieWonka->setInventory(stockInventory(1)); 
 momAndPop->setInventory(stockInventory(2)); 
 jackNjill->setInventory(stockInventory(3)); 

 /* demonstrate initial inventories */
 cout << willieWonka->getName() << " is starting the simulation with: " << endl;
 willieWonka->getInventory()->showInventory();
 cout << endl;

 cout << momAndPop->getName() << " is starting the simulation with: " << endl;
 momAndPop->getInventory()->showInventory();
 cout << endl;

 cout << jackNjill->getName() << " is starting the simulation with: " << endl;
 jackNjill->getInventory()->showInventory();
 cout << endl;

 /* initialize customer orders */
 cust1->addOrder(createOrder(1));
 cust2->addOrder(createOrder(2));
 cust3->addOrder(createOrder(3));
 cust4->addOrder(createOrder(4));

}
