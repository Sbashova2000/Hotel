#pragma once

#include <iostream>

class Date
{
public:
	
	Date();                                //default constructor
	Date(size_t, size_t, size_t);		  //constructor with parameters
	//~Date();                             //destructor
	void Print() const;                    //print the data(yy-mm-dd)
	size_t getYear() const;                //return year
	size_t getMonth() const;               //return month
	size_t getDay() const;                 //return day

	
	friend std::istream& operator>>(std::istream& in, Date& date);
	friend std::ostream& operator<<(std::ostream& out, const Date& date);
	friend bool operator>(const Date&, const Date&);
	friend bool operator<(const Date&, const Date&);
	bool operator==(const Date& p) const;
	
	
private:
	size_t year;
	size_t month;
	size_t day;
};