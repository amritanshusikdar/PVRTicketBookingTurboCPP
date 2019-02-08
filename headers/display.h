/*
    All front end "To be displayed on screen" functions are defined here
    Eg: welcomeScreen, loadingScreen, viewEmptySeats, etc.
*/

#ifndef __DISPLAY_H__
#define __DISPLAY_H__

/* ~~~~~~~~~~********** START OF __DISPLAY_H__ **********~~~~~~~~~~ */

#include "consts.h"
#include "globals.h"

/* Function definitions */

// Returns Choice //
int loginMenu()
{
    clrscr();

    int choice, valid = false;
    char selection;

    //  Starting the drawing  //

    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t*-------------------------*";
    cout << "\n\t\t\t|\t ==========\t  |";
    cout << "\n\t\t\t|\t LOGIN MENU\t  |";
    cout << "\n\t\t\t|\t ==========\t  |";
    cout << "\n\t\t\t|\t 1. Login\t  |";
    cout << "\n\t\t\t|\t2. Register\t  |";
    cout << "\n\t\t\t|\t3. Customer Care  |";
    cout << "\n\t\t\t|\t  4. Quit\t  |";
    cout << "\n\t\t\t|\t\t\t  |";
    cout << "\n\t\t\t*-------------------------*\n\n";

    cout << "\t\t\t   Enter your choice: ";
    //  checking for invalid options
    while(!valid)
    {
        cin >> selection;

        switch (selection)
        {
            case '1':
                choice = 1;
                valid = true;
                break;
            case '2':
                choice = 2;
                valid = true;
                break;
            case '3':
                choice = 3;
                valid = true;
                break;
            case '4':
                choice = 4;
                valid = true;
                break;
            default:
                cout << "\t\tWrong choice entered! Please retry: ";
                break;
        }
    }

    return choice;
}

//  Menu only for the Admin
int adminMenu()
{
    clrscr();

    int choice, valid=false;
    char selection;

    //  Starting the drawing  //

    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t*-------------------------*";
    cout << "\n\t\t\t|\t ==========\t  |";
    cout << "\n\t\t\t|\t ADMIN MENU\t  |";
    cout << "\n\t\t\t|\t ==========\t  |";
    cout << "\n\t\t\t|\t\b1. Add Movie\t  |";
    cout << "\n\t\t\t|\t\b2. Delete Movie\t  |";
    cout << "\n\t\t\t|\t\b3. Reset Seats     |";
    cout << "\n\t\t\t|\t\b4. Sign Out\t  |";
    cout << "\n\t\t\t|\t\t\t  |";
    cout << "\n\t\t\t*-------------------------*\n\n";

    cout << "\t\t\t   Enter your choice: ";
    //  checking for invalid options
    while(!valid)
    {
        cin >> selection;

        switch (selection)
        {
            case '1':
                choice = 1;
                valid = true;
                break;
            case '2':
                choice = 2;
                valid = true;
                break;
            case '3':
                choice = 3;
                valid = true;
                break;
            case '4':
                choice = 4;
                valid = true;
                break;
            default:
                cout << "\t\tWrong choice entered! Please retry: ";
                break;
        }
    }

    return choice;
}

//  Menu for the normal User
int userMenu()
{
    clrscr();

    int choice, valid=false;
    char selection;

    //  Starting the drawing  //

    cout << "\n\n\n\n\n\n";
    cout << "\t\t\t*-------------------------*";

    cout << "\n\t\t\t|\t ==========\t  |";
    cout << "\n\t\t\t|\t MOVIE TIME\t  |";
    cout << "\n\t\t\t|\t ==========\t  |";
    cout << "\n\t\t\t|    1. Book a Show\t  |";
    cout << "\n\t\t\t|    2. My Details        |";
    cout << "\n\t\t\t|    3. My Tickets\t  |";
    cout << "\n\t\t\t|    4. Sign Out\t  |";

    cout << "\n\t\t\t*-------------------------*\n\n";

    cout << "\t\t\t   Enter your choice: ";
    //  checking for invalid options
    while(!valid)
    {
        cin >> selection;

        switch (selection)
        {
            case '1':
                choice = 1;
                valid = true;
                break;
            case '2':
                choice = 2;
                valid = true;
                break;
            case '3':
                choice = 3;
                valid = true;
                break;
            case '4':
                choice = 4;
                valid = true;
                break;
            default:
                cout << "\t\tWrong choice entered! Please retry: ";
                break;
        }
    }
    return choice;
}


// Pass 1 for `Welcome` screen, anything else for `Thanks for Visiting` screen //
void welcomeAndThanks(int choice)
{
    clrscr();
    cout << "\n\n";
    cout << "\t\t\t  *-------------------------*";
    
    cout << "\n\t\t\t  |\t  ----------\t    |";

    if(choice==1) cout << "\n\t\t\t  |\t  Welcome to\t    |";
    else cout << "\n\t\t\t  |\t    Thanks\t    |";

    if(choice==1) cout << "\n\t\t\t  |\t  PVR Cinemas\t    |";
    else cout << "\n\t\t\t  |\t for visiting!\t    |";

    cout << "\n\t\t\t  |\t  ----------\t    |";
    cout << "\n\t\t\t  |\t\t\t    |";
    cout << "\n\t\t\t  *-------------------------*\n\n";

    cout << "\t\t\t######### ###      ### ######### \n";
    cout << "\t\t\t##     ### ###     ### ##     ###\n";
    cout << "\t\t\t##     ### ###     ### ##     ###\n";
    cout << "\t\t\t#########  ###     ### ######### \n";
    cout << "\t\t\t###         ###   ###  ###   ###  \n";
    cout << "\t\t\t###          ###  ###  ###    ### \n";
    cout << "\t\t\t###           ####     ###     ###\n";
    
    cout << "\n\n\t\t\t    Press any key to continue.\n\n";

    getch();
    clrscr();
}


void loadWait(char *phrase)
{
    clrscr();

    int i=4;
    int x=26, y=13;

    gotoxy((80-strlen(phrase))/2,y-2);
    cout << phrase << endl;

    gotoxy(35,y-1);
    cout << "Loading...";

    while(i <= 100)
    {
        gotoxy(48,12);
        cout << "\\" << (char) 8;   // Printing backspace character --- ASCII = 8
        delay(loadWaitDelay);
        cout << "|" << (char) 8;
        delay(loadWaitDelay);
        cout << "/" << (char) 8;
        delay(loadWaitDelay);
        cout << "-" << (char) 8;
        delay(loadWaitDelay);

        gotoxy(x,y+1);
        x+=2;

        if(i <= 30)
                cout << (char) 176 << (char) 176;
        else if(i <= 60)
                cout << (char) 177 << (char) 177;
        else
                cout << (char) 178 << (char) 178;

        gotoxy(55,14);
        cout << i << "%";

        i+=8;
    }

    delay(100);
}


//	For displaying booked/unbooked seats of a particular movie
void showSeats(int record)
{
    readSeatsFromFile();	//	writing the seat details from file to cpp objects

    char alphabet = 'A';

    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t       ";

    cout << '-' << char(197) << "- ";

    for(int i=0; i<15; i++)
    {
        for(int j=0; j<10; j++)
        {
                if(i==0)
                {
                    cout << j+1 << "  ";
                }
                else
                {
                    if(movieSeats[record].seats[i-1][j])	//	if the particular seat is booked
                    {
                        cout << "  " << char(4);
                    }
                    else	//	if the particular seat ain't booked
                    {
                        cout << "  " << char(127);
                    }
                }
        } cout << endl << "\t\t\t";

        if(i<=13)
            cout << alphabet++;
    }
}


void customerService(void)
{
    clrscr();

    cout << "\t\t\t\t====================" << endl;
    cout << "\t\t\t\t  Customer Service" << endl;
    cout << "\t\t\t\t====================" << endl << endl << endl;

    cout << "\tWe hope you liked our service. In case of any technical issues,\n"
    "    feel free to contact us via the details given below. Your patience is much\n\t\t\t\tappreciated.\n\n";

    cout << endl << endl << endl;
    cout << "\t\t\t*---------------------------------*\n";
    cout << "\t\t\t    Email: customercare@pvr.com" << endl;
    cout << "\t\t\t    Call us @: +91 66990 69690,"
            "\n\t\t\t\t       +91 69690 66990" << endl;
    cout << "\t\t\t*---------------------------------*\n";

    getch();
}

/* ~~~~~~~~~~********** END OF __DISPLAY_H__ **********~~~~~~~~~~ */

#endif
