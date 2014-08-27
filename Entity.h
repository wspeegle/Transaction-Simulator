#pragma once
#include <string>

//INCLUDE FILES NEEDED
//CLASS FILES NEEDED
class Entity
{
public:
	Entity(const std::string &, const std::string &, double);
	const std::string & getName() const;
	const std::string & getID() const;
	double getBalance() const;
	void setName(const std::string &);
	void setID(const std::string &);
	void setBalance(double);
	virtual void list();
	virtual void step() = 0;
private:
	std::string name;
	std::string id;
	double balance;
};
