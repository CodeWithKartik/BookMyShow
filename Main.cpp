//This project is created by Kartik Srivastava
//The flow of the code:
//Load all the databases first. Movie and cinema database in separate threads.User database in a separate thread. Rest of the flow in main thread
//Login Manager would seek the user type and user information and hold it temporarily on the UI side
//If the user is a member, then booking manager would launch
//Once user has selected cinema, movie and date, the booking manager would hold this information temporarily on the UI side
//Seat selection would be held temporarily on the UI side and once payment manager has confirmed payment the seat selection would be updated in the database
//If the user is an admin, then using the friend functions of it and databases to the movie, cinema and user; admin
//would modify the information for a movie, cinema or user



#include <iostream>
#include "User.h"
#include "UserDatabase.h"
#include "MovieDatabase.h"
#include "CinemaDatabase.h"
#include "Guest.h"
#include "Member.h"
#include "Admin.h"
#include "LoginMgr.h"
#include "BookingMgr.h"
#include "LinkedList.h"
#include "PersistentObjectUtility.h"
#include <vector>
#include <windows.h>

using namespace std;

struct PARAMS {
    UserDatabase *udatabase;
    vector<char> file_array;
};

DWORD WINAPI mythread(void *parameter)
{
    PARAMS* params = (PARAMS*)parameter;
    (params->udatabase)->PopulateDatabase(params->file_array);
	return 0;
}

int main() {
    //Loading databases
    static MovieDatabase mdb;
    static CinemaDatabase cdb;
    static UserDatabase udb;

    PersistentObjectUtility<UserDatabase> *utils = new PersistentObjectUtility<UserDatabase>(udb);
    vector<char> file_array;
    utils->ReadFromFile(file_array);
    PARAMS params;
    params.udatabase = &udb;
    params.file_array = file_array;

    HANDLE myhandle;
	DWORD mythreadid;
	myhandle = CreateThread(0, 0, mythread, &params, 0, &mythreadid);
    //udb.PopulateDatabase(file_array);
    //Sleep(100);
    //Databases loaded

    //Login procedure starts
    LoginMgr *lmgr = new LoginMgr(ADMIN, udb);
    Admin *curent_user = dynamic_cast<Admin*>(lmgr->GetNowLogged());
    utils->WriteToFile();
    delete utils;

    if (curent_user) {
        curent_user->UpdateMovieDatabase(0, mdb);
        cout<<mdb;
    }

    if (curent_user) {
        curent_user->UpdateCinemaDatabase(0, cdb);
        cout<<cdb;
    }
    //Login procedure ends here

    //Booking procedure starts
    BookingMgr *bmgr = new BookingMgr(mdb, cdb);

    cout<<cdb;
    //Booking procedure ends here

    delete bmgr;
    delete lmgr;

    return 0;
}
