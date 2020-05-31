#include <iostream>
#include "Hotel.h"
#include "Customer.h"

using namespace std;

int main()
{
    Hotel hm(30);
    string command;


    cout << "********* WELCOME TO ***********\n";
    cout << "******** HOTEL SYSTEM **********\n";
    cout << "\n[1]. Open";
    cout << "\n[2]. Close";
    cout << "\n[3]. Save";
    cout << "\n[4]. Save as";
    cout << "\n[5]. Help";
    cout << "\n[6]. CheckIn Room";
    cout << "\n[7]. Available Room";
    cout << "\n[8]. CheckOut Room";
    cout << "\n[9]. Report";
    cout << "\n[10]. Find Room";
    cout << "\n[11]. Unavailable Room";
    cout << "\n[12]. Exit" << endl;

    cout << "****************************\n";
    cout << "   Please enter a command open! " << endl;
    cout << "****************************\n";
    
	while (cin >> command && command != "stop")
	{

        if (command == "open")
        {
            hm.open();
            cout << "Please enter a command" << endl;
        }
        else if (command == "close")
        {
            hm.close();
            cout << "Please enter a command" << endl;
        }
        else if (command == "save")
        {
            hm.save();
            cout << "Please enter a command" << endl;
        }
        else if (command == "save as")
        {
            hm.saveAs();
            cout << "Please enter a command" << endl;
        }
        else if (command == "help")
        {
            hm.help();
            cout << "Please enter a command" << endl;
        }
        else if (command == "checkin")
        {
            cout <<"The number of rooms is: "<< hm.getRoomsCount() << endl;
            Date from, to;
            string note;
            size_t guests;
            cout << "Please enter the period of your stay in the next way (from year|month|day  to year|month|day), a note and optional ( guests )" << endl;
            cout << "from(Date) \n"; 
            cin >> from;
            cout << "to(Date) \n";
            cin >> to;
            cin.ignore();
            cout << "note \n";
            getline(cin, note);
            cout << "guests \n";
            cin >> guests;
            if (guests > 0)
            {
                hm.checkIn(from, to, note, guests);
            }
            else
            {
                hm.checkIn(from, to, note);
            }
            cout << "end" << endl;
            cout << "Please enter a command" << endl;
        }
        else if (command == "checkout")
        {
            size_t roomNum;
            cout << "Please enter your roomNumber " << endl;
            cin >> roomNum;
            hm.checkOut(roomNum);
            cout << "Please enter a command" << endl;
        }
        else if (command == "available")
        {
            Date date;
            cout << "Please enter a date " << endl;
            cin >> date;
            hm.availability(date);
            cout << "Please enter a command" << endl;
        }
        else if (command == "report")
        {
            Date from, to;
            cout << "Please enter the period of your stay in the next way (from year|month|day  to year|month|day)" << endl;
            cout << "from \n";
            cin >> from;
            cout << "to \n";
            cin >> to;
            hm.report(from,to);
            cout << "Please enter a command" << endl;
        }
        else if (command == "find")
        {
            Date from, to;
            size_t beds;
            cout << "Please enter the period of your stay and the beds in your room!" << endl;
            cout << "beds: \n";
            cin >> beds;
            cout << "from \n";
            cin >> from;
            cout << "to \n";
            cin >> to;
            hm.find(beds,from,to);
            cout << "Please enter a command" << endl;
        }
        else if (command == "unavailable")
        {
            Date from, to;
            string note;
            size_t roomNum;
            cout << "Please enter values for the parameters(room number,date from-to and note) " << endl;
            cout << "roomNum \n";
            cin >> roomNum;
            cout << "from \n";
            cin >> from;
            cout << "to \n";
            cin >> to;
            cout << "note \n";
            cin >> note;
            hm.unavailable(roomNum,from,to,note);
            cout << "Please enter a command" << endl;
        }
        else if (command == "exit")
        {
            cout << "Exit";
            hm.freeUpRooms();
            break;
        }
	}
	return 0;
}



    






