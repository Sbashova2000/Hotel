#include <iostream>
#include "Room.h"


//static variable

size_t Room::roomNumber = 0;

//Default constructor

Room::Room()
{
	this-> roomNumber++;
	this-> from = Date();
	this-> to = Date();
	this-> note = " ";
	this-> guests = 0;
	this->availableBeds = 3;
	this-> available = 1;
}

//Constructors with parameters

Room::Room(const Date& from, const Date& to, const std::string note)
{
	this->roomNumber++;
	this->from = from;
	this->to = to;
	this->note = note;
	this->availableBeds = 3;
	this->guests = availableBeds;
	this->available = 1;
}

Room::Room(const Date& from, const Date& to, const std::string note,size_t guests)
{
	this->roomNumber++;
	this->from = from;
	this->to = to;
	this->note = note;
	this->guests = guests;
	this->availableBeds = 3;
	this->available = 1;
}

//Destructor

/*Room::~Room()    
{

}*/


//Geters


size_t Room::getRoomNumber() const
{
	return this->roomNumber;
}

Date& Room::getDateFrom() 
{
	return this->from;
}

Date&  Room::getDateTo() 
{
	return this->to;
}

size_t  Room::getAvailableBeds() const
{
	return this->availableBeds;
}

/*
string Room::getNote() const
{
	return note;
}

size_t Room::getGuests() const
{
	return guests;
}
*/


//Functions

void Room::clearRoom()
{
	this->from = Date();
	this->to = Date();
	this->note = " ";
	this->guests = 0;
	this->availableBeds = 3;
	this->available = 1;
}

bool Room::isAvailable()
{
	if (availableBeds - guests > 0 && available)
	{
		return true;
	}
	return false;
}

//Seters

void  Room::setNote(string note)
{
	this->note = note;
}
void Room::setIsAvailable(bool available)
{
	this->available = available;
}

void Room::setDateFrom(const Date& from)
{
	this->from = from;
}
void Room::setDateTo(const Date& to)
{
	this->to = to;
}

/*
void Room::setRoomNumber(size_t rno)
{
	this->roomNumber = rno;
}


void Room::setGuests(size_t guests)
{
	this->guests = guests;
}
void  Room::setAvailableBeds(size_t availableBeds)
{
	this->availableBeds = availableBeds;
}
*/

// overloaded Operators

std::istream& operator>>(std::istream& in, Room& room)
{
	in >> room.roomNumber;
	in >> room.from;
	in >> room.to;
	in >> room.note;
	in >> room.availableBeds;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Room& room)
{
	out << room.roomNumber << " ";
	out << room.from << " ";
	out << room.to << " ";
	out << room.note << " ";
	out << room.guests << "\n";
	return out;
}