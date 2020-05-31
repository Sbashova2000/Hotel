#pragma once
#include <vector>
#include "Room.h"

class Hotel
{
public:
	Hotel(size_t);               
	//~Hotel();
	void checkIn(const Date& from, const Date& to, const string note);
	void checkIn(const Date& from, const Date& to, const string note,size_t guests);
	void availability(Date& date);
	void checkOut(size_t);
	void report(const Date& from, const Date& to);
	Room* find(size_t beds, const Date& from, const Date& to);
	void unavailable(size_t roomNum,const Date& from, const Date& to,string note);
	
	
	void open();
	void close();
	void save();
	void saveAs();
	void help();
	size_t getRoomsCount();
	size_t getDaysFromDate(const Date&);
	size_t getDaysBetweenDate(const Date&, const Date&);
	void initializeRooms(size_t);
	void freeUpRooms();
	
private:
	vector <Room*> rooms;
	
};