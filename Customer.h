#pragma once

#include<string>
using namespace std;

class Customer
{
public:
	Customer();
	~Customer();
	string getName() const;
	string getAddress() const;
	string getPhone() const;
	void setName(string name);
	void setAddress(string address);
	void setPhone(string );

	bool isValidPhone(string _phone);
private:
	string name;
	string address;
	string phone;
};
