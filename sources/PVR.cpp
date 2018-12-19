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

//  C++ Library
#include <cstream.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <time.h>

//  Custom headers written for this project
#include "admin.h"
#include "display.h"
#include "consts.h"
#include "globals.h"


//  START OF main()
int main()
{
    clrscr();
    welcomeAndThanks(1);

    showSeats();
    getch();
    return 0;

    /* @TODO:
        after everything's done, make another header and
        just call one function from main to commence the
        program */
}

//  END OF main()


//////////////////////////////////////
/////~~~~~~END OF PROGRAM~~~~~~///////
//////////////////////////////////////
