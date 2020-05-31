#include "Customer.h"

//Default constructor

Customer::Customer()
{
	string name = "";
	string address = "";
	string phone = "";
}

Customer::~Customer()
{

}

//geters

string Customer::getName() const
{
	return name;
}
string Customer::getAddress() const
{
	return address;
}
string Customer::getPhone() const
{
	return phone;
}

//seters

void Customer::setName(string name)
{
	this->name = name;
}
void Customer::setAddress(string address)
{
	this->address = address;
}
void Customer::setPhone(string _phone)
{
	if (isValidPhone(_phone))
	{
		this->phone = _phone;
	}
}

bool Customer::isValidPhone(string _phone)
{
	if (_phone[0] != '+')
	{
		return false;
	}
	for (size_t i = 1; i < _phone.size(); i++)
	{
		if (_phone[i] < '0' || _phone[i] > '9')
		{
			return false;
		}
	}
	return true;
}