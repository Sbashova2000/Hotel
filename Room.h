#pragma once
#include<string>
#include "Date.h"

using namespace std;

class Room
{
public:
	Room();																			//default consructor
	Room(const Date& from, const Date& to, const std::string note);					//constructor with parameters
	Room(const Date& from, const Date& to, const std::string note,size_t guests);  //constructor with parameters
	//~Room();																		//destructor


	//Geters

	size_t getRoomNumber() const;
	Date&  getDateFrom();
	Date& getDateTo();
	size_t getAvailableBeds() const;
	/*
	string getNote() const;
	size_t getGuests() const;
	*/
  
	// Help Functions

	void clearRoom();
	bool isAvailable();

	//Seters

	void setNote(string note);
	void setIsAvailable(bool isAvailable);
	void setDateFrom(const Date& from);
	void setDateTo(const Date& to);
	/*
	void setRoomNumber(size_t rno);
	void setGuests(size_t guests);
	void setAvailableBeds(size_t availableBeds);
	*/

	friend std::istream& operator>>(std::istream& in, Room& room);
	friend std::ostream& operator<<(std::ostream& out, const Room& room);
	
private:
	static size_t roomNumber;
	Date from;
	Date to;
	string note;
	size_t guests;                         //broi,nastaneni gosti
	size_t availableBeds;                     //broi legla w staqta
	bool available;	                      //1-available ,0-non-available
};
