#include "Hotel.h"
#include <fstream>

Hotel::Hotel(size_t count)
{
	initializeRooms(count);
}

/*Hotel::~Hotel()
{

}*/

void Hotel::checkIn(const Date& from, const Date& to,const std::string note)
{
	for (int i = 0; i < this->rooms.size(); i++)
	{
		if (rooms[i]->isAvailable())
		{
			rooms[i]->setIsAvailable(false);
			rooms[i]->setNote(note);
			rooms[i]->setDateFrom(from);
			rooms[i]->setDateTo(to);
			return;
		}
	}
	cout << "No free room!" << endl;
}

void Hotel::checkIn(const Date& from, const Date& to, const std::string note, size_t guests)
{
	for (int i = 0; i < this->rooms.size(); i++)
	{
		if (rooms[i]->isAvailable())
		{
			if (rooms[i]->getAvailableBeds() >= guests)
			{
				rooms[i]->setIsAvailable(false);
				rooms[i]->setNote(note);
				rooms[i]->setDateFrom(from);
				rooms[i]->setDateTo(to);
				return;
			}
		}
	}
	cout << "No free room!" << endl;
}

void Hotel::availability(Date& date)
{
	for (int i = 0; i < this->rooms.size(); i++)
	{
		if (rooms[i]->getDateFrom() == date)

		{
			rooms[i]->getRoomNumber();
		}
	}
}

void Hotel::checkOut(size_t roomNum)
{
	for (int i = 0; i < this->rooms.size(); i++)
	{
		if (rooms[i]->getRoomNumber() == roomNum)
		{
			rooms[i]->clearRoom();
		}
	}
}

void Hotel::report(const Date& from,const Date& to)
{
	cout << "List of rooms: " << endl;
	for (int i = 0; i < this->rooms.size(); i++)
	{
		if (rooms[i]->getDateFrom()==from && rooms[i]->getDateTo() == to)
		{
			if (rooms[i]->isAvailable())
			{
				cout << "#" << rooms[i]->getRoomNumber() << " / " << 0 <<" days used /the room is available: "<<endl;
			}
			else
			{
				cout << "#" << rooms[i]->getRoomNumber() << " / " << getDaysBetweenDate(to, from) << " days used /the room is NOT available: " << endl;
			}
		}	
	}
}

size_t  Hotel::getDaysFromDate(const Date& date)
{
	size_t y = date.getYear();
	size_t m = date.getMonth();
	size_t d = date.getDay();
	m = (m + 9) % 12;
	y = y - m / 10;
	return 365 * y + y / 4 - y / 100 + y / 400 + (m * 306 + 5) / 10 + (d - 1);
}

size_t Hotel::getDaysBetweenDate(const Date& date1, const Date& date2)
{

	int result = getDaysFromDate(date1) - getDaysFromDate(date2);
	return abs(result);
}

size_t Hotel::getRoomsCount()
{
	return this->rooms.size();
}

Room* Hotel::find(size_t beds, const Date& from, const Date& to) 
{
	for (int i = 0; i < this->rooms.size(); i++)
	{
		if (rooms[i]->getAvailableBeds()==beds && rooms[i]->getDateFrom() == from && rooms[i]->getDateTo() == to)
		{
			return rooms[i]; 
		}
	} 
	return nullptr;
}

void Hotel::unavailable(size_t roomNum, const Date& from, const Date& to, string note)
{
	for (int i = 0; i < this->rooms.size(); i++)
	{
		if (rooms[i]->getRoomNumber() == roomNum && rooms[i]->getDateFrom() == from && rooms[i]->getDateTo() == to)
		{
			if (rooms[i]->isAvailable())
			{
				rooms[i]->setNote(note);
				rooms[i]->setIsAvailable(false);
			}
			else
			{
				cout << "The room is in use!" << endl;
			}
		}
		else
		{
			cout << "The room is NOT found!" << endl;
		}
	}
}

//Command functions

void Hotel::open()
{
	string fileName;
	cout << "Please input a file Name: " << endl;
	cin >> fileName;
	ifstream file;
	file.open(fileName);
	if (file.is_open())
	{
		Room obj;
		while (file >> obj)
		{
			rooms.push_back(&obj);
		}
		cout << "Successfully opened file" << endl;
	}
	file.close();
}

void Hotel::close()
{
	rooms.clear();
}

void Hotel::save()
{
	string fileName;
	cout << "Please input a file Name: " << endl;
	cin >> fileName;
	ofstream file;
	file.open(fileName);
	if (file.is_open())
	{
		for (int i = 0; i < this->rooms.size(); i++)
		{
			file << *rooms[i];
		}
		cout << "Successfully saved file" << endl;
	}
	file.close();
}

void Hotel::saveAs()
{
	string fileName;
	cout << "Please input a file Name: " << endl;
	cin >> fileName;
	ofstream file;
	file.open(fileName); 
	if (file.is_open())
	{
		for (int i = 0; i < this->rooms.size(); i++)
		{
			file << *rooms[i];
		}
		cout << "Successfully saved  another file" << endl;
	}
	file.close();
}

void Hotel::help()
{
	cout << "The following commands are supported: " << endl;
	cout << "open <file>      opens <file>" << endl;
	cout << "close            closes currently opened file" << endl;
	cout << "save             saves the currently open file" << endl;
	cout << "save as <file>   saves the currently open file in <file>" << endl;
	cout << "help             prints the information" << endl;
	cout << "exit             exists the program" << endl;
}

void Hotel::freeUpRooms()
{
	for (int i = 0; i < rooms.size(); i++)
	{
		rooms.clear();
	}
}

void Hotel::initializeRooms(size_t count)
{
	for (int i = 0; i < count; i++)       //count = number of rooms
	{
		Room* room = new Room;
		this->rooms.push_back(room);
	}
}



