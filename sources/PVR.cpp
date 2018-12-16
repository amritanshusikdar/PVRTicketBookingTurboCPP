 /////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
/*                              **
    PVR Cinema - Ticket Booking
    Computer Science Project Work
    Session: 2018-'19
    Repository: amritanshusikdar/PVRTicketBookingTurboCPP
    @Author: Amritanshu Sikdar
    XII - B
    B-7681
**                              */
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////



#include "admin.h"
#include "display.h"


//  START OF main()
int main() {
    clrscr();

    welcomeScreen("Hey there!");
    loginMenu();
    loadWait("Damnson!");
    goodBye();

    Administrator nigga;

    cout << "Dictionary: \n" << ticketHash << endl;

    nigga.ticketIDGenerator();
    cout << "ID: \n" << ticketID << endl;

    getch();

    return 0;
}

//  END OF main()


//////////////////////////////////////
/////~~~~~~END OF PROGRAM~~~~~~///////
//////////////////////////////////////
