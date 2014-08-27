#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <set>
#include "Product.h"

class Inventory{

public:
 // Start with empty inventory
 Inventory(){}; 	

 // Add a product to inventory
 void addProduct(Product *p);	

 // Add a product from inventory
 void removeProduct(Product *p);	
 void incrementStock(const std::string & sku, int val);

 void showInventory() const;

 double getValue();

 // Find product by SKU
 Product * getProductBySku(const std::string & sku);

 std::set<Product*> getInventory();

private:

 // Find product by Description
 Product * getProductByDescription(const std::string & description);

 std::set<Product *> inventory_; 

};
#endif
