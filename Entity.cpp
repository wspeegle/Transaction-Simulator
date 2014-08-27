#include <iostream>
#include <string>
#include "Entity.h"

	Entity::Entity(const std::string& n, const std::string& i, double b)
	:
	name(n),
	id(i),
	balance(b)
	{};

	const std::string& Entity::getName()const {
	return name;
	}
	
	void Entity::setName(const std::string &n){
	name = n;
	}

	const std::string& Entity::getID() const {
	return id;
	}
	
	void Entity::setID(const std::string &i){
	id = i;
	}

	double Entity::getBalance() const{
	return balance;
	}
	
	void Entity::setBalance(double b){
	balance = b;
	}
	
	void Entity::list(){
	std::cout << getName() << " : " << getID() << " has $ " << getBalance() << std::endl;
	}

	//void virtual Entity::step() = 0;

