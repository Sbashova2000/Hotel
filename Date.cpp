#include <iostream>
#include "Date.h"


//Constructors

Date::Date()
{
	year = 0;
	month = 0;
	day = 0;
}

Date::Date(size_t x, size_t y, size_t z)
{
	if (x < 9999 || y < 12 || z < 31) 
	{
		std::cout << "Invalid input, try again!" << std::endl;
		year = 1995;
		month = 1;
		day = 1;
	}
	else
	{
		year = x;
		month = y;;
		day = z;
	}
}

//Destructor

/*Date::~Date()
{

}*/


//Print data

void Date::Print() const
{
	std::cout << year << "-" << month << "-" << day << std::endl;
}

//geters

size_t Date::getYear() const
{
	return this->year;
}

size_t Date::getMonth() const
{
	return this->month;
}

size_t Date::getDay() const
{
	return this->day;
}

//Operators overloading

std::istream& operator>>(std::istream& in, Date& date)
{
	char delimeter = '|';
	in >> date.year >> delimeter >> date.month >> delimeter >> date.day;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Date& date)
{
	char delimeter = '|';
	out << date.year << delimeter << date.month << delimeter << date.day;
	return out;
}

bool  operator>(const Date& x, const Date& y) 
{
	return  x.year > y.year ||
			x.month > y.month ||
			x.day > y.day;
}
bool operator<(const Date& x, const Date& y)
{
	return  x.year < y.year ||
			x.month < y.month ||
			x.day  < y.day;
}	
bool Date::operator==(const Date& p) const
{
	return  p.year == this->year &&
			p.month == this->month &&
			p.day == this->day;
}



