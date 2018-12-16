///////////////////////////////////
///////////////////////////////////
/*                              **
    PVR Cinema - Ticket Booking
    Computer Science Project Work
    Session: 2018-'19
    Repository: amritanshusikdar/PVRTicketBookingTurboCPP
    @Author: Amritanshu Sikdar
    XII - B
    B-7681
**                              */
///////////////////////////////////
///////////////////////////////////



//  HEADER FILES

#include <fstream.h>
#include <conio.h>
#include <graphics.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>

#include "store.h"

//  GLOBAL VARIABLES

const int loadWaitDelay = 40;
const char ticketHash[37] = "0123456789"
                        "abcdefghijklmnopqrstuvwxyz";

//  FUNCTION PROTOTYPES

void welcomeScreen(char*);
int loginMenu(void);
void loadWait(char*);
void goodBye(void);

class Accounts {
    private:
        char username[30], password[30];
    protected:
        void passwordValid();
};

void Accounts::passwordValid(){
    if(strlen(Accounts::password)){/* @TODO */}
}

class AccountManager : public Accounts {
    public:
        void checkUserValid(char* username, char* password){
            //fstream accs(); // @TODO //

        }
};


//  START OF main()
int main()
{
    clrscr();

    int gd = DETECT, gm;
	initgraph(&gd, &gm,"");

    welcomeScreen("Hey there!");
    //loadWait("Damnson!");
    //goodBye();

    getch();
    return 0;
}

//  END OF main()


//////////////////////////////////////
////~~~USER DEFINED FUNCTIONS~~~//////
//////////////////////////////////////

void welcomeScreen(char* message)
{
    outtextxy(20,10,"Welcome to PVR Cinemas");
    outtextxy(40,40,message);
    rectangle(20,20,getmaxx()-40,getmaxy()-40);
}

int loginMenu(void)
{
    int choice;

    cout << "Main Menu!\n";

    cout << "1. Login\n2. Register\n3. Continue As Guest\n";
    cin >> choice;

    return choice;
}

void loadWait(char *phrase)
{
    clrscr();

    cout << phrase << endl;
    int i=4;
    int x=-1, y=3;

    cout << "Loading...";

    while(i <= 100)
    {
        gotoxy(12,2);
        cout << '\\' << (char) 8;   // Printing backspace character --- ASCII = 8
        delay(loadWaitDelay);
        cout << '|' << (char) 8;
        delay(loadWaitDelay);
        cout << '/' << (char) 8;
        delay(loadWaitDelay);
        cout << '-' << (char) 8;
        delay(loadWaitDelay);

        gotoxy(x+=2,y);

        if(i <= 30)
            cout << (char) 176 << (char) 176;
        else if(i <= 60)
            cout << (char) 177 << (char) 177;
        else
            cout << (char) 178 << (char) 178;

        gotoxy(30,3);
        cout << i << '%';

        i+=8;
    }

    cout << endl << "Loaded";
    delay(60);

}

void goodBye(void)
{
    cout << "\n\nThanks for Visiting!\n\n";
}

//  END OF USER DEFINED FUNCTIONS



//////////////////////////////////////
/////~~~~~~END OF PROGRAM~~~~~~///////
//////////////////////////////////////