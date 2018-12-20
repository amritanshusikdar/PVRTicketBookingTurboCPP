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
	for(size_t i=0; i<9; i++)
	{
		switch(i)
		{
				case 0:
					cout << "\n\t\t\t|\t ==========\t  |";
				break;

				case 1:
					cout << "\n\t\t\t|\t LOGIN MENU\t  |";
				break;

				case 2:
					cout << "\n\t\t\t|\t ==========\t  |";
				break;

				case 4:
					cout << "\n\t\t\t|\t 1. Login\t  |";
				break;

				case 5:
					cout << "\n\t\t\t|       2. Register\t  |";
				break;

				case 6:
					cout << "\n\t\t\t|  3. Continue as Guest   |";
				break;

				case 7:
					cout << "\n\t\t\t|\t  4. Quit\t  |";
				break;

				default:
					cout << "\n\t\t\t|\t\t\t  |";
		}
	}

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
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t  *-------------------------*";
	for(int i=0; i<4; i++)
	{
		switch(i)
		{
				case 0:
					cout << "\n\t\t\t  |\t  ----------\t    |";
				break;

				case 1:
					if(choice==1) cout << "\n\t\t\t  |\t  Welcome to\t    |";
					else cout << "\n\t\t\t  |\t    Thanks\t    |";
				break;

				case 2:
					if(choice==1) cout << "\n\t\t\t  |\t  PVR Cinemas\t    |";
					else cout << "\n\t\t\t  |\t for visiting!\t    |";
				break;

				case 3:
					cout << "\n\t\t\t  |\t  ----------\t    |";
				break;

				default:
					cout << "\n\t\t\t  |\t\t\t    |";
		}
	}

	cout << "\n\t\t\t  *-------------------------*\n\n";
	cout << "\t\t\t    Press any key to continue.\n\n";

	cout << "\t\t\t######### ###      ### ######### \n";
	cout << "\t\t\t##     ### ###     ### ##     ###\n";
	cout << "\t\t\t##     ### ###     ### ##     ###\n";
	cout << "\t\t\t#########  ###     ### ######### \n";
	cout << "\t\t\t###         ###   ###  ###   ###  \n";
	cout << "\t\t\t###          ###  ###  ###    ### \n";
	cout << "\t\t\t###           ####     ###     ###\n";

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

void showSeats()
{
	clrscr();

	char alphabet = 'A';

	cout << "\n\n\n\n\n\n\n\n";
	srand(time(NULL));
	cout << "\t\t       ";

	cout << '-' << char(197) << "- ";

	for(int i=0; i<15; i++)
	{
		for(int j=0; j<10; j++)
		{
				int now = rand() % 2;
				if(now == 1)
				{
					if(i==0) cout << j+1 << "  ";
					else cout << "  " << char(4);
				}
				else
				{
					if(i==0) cout << j+1 << "  ";
					else cout << "  " << char(127);
				}
		} cout << endl << "\t\t\t";

		if(i<=13)
			cout << alphabet++;
	}
}

int adminMenu()
{

	clrscr();

    int choice, valid=false;
    char selection;

	//  Starting the drawing  //

	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t*-------------------------*";
	for(size_t i=0; i<9; i++)
	{
		switch(i)
		{
				case 0:
					cout << "\n\t\t\t|\t ==========\t  |";
				break;

				case 1:
					cout << "\n\t\t\t|\t ADMIN MENU\t  |";
				break;

				case 2:
					cout << "\n\t\t\t|\t ==========\t  |";
				break;

				case 4:
					cout << "\n\t\t\t|\t1. Add Movie\t  |";
				break;

				case 5:
					cout << "\n\t\t\t|\t2. Delete Movie\t  |";
				break;

				case 6:
					cout << "\n\t\t\t|\t3. View Profit    |";
				break;

				case 7:
					cout << "\n\t\t\t|\t4. Sign Out\t  |";
				break;

				default:
					cout << "\n\t\t\t|\t\t\t  |";
		}
	}

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

void customerService()
{
	//	@TODO just random email and phone numbers in a beAuTiFuL format
}

/* ~~~~~~~~~~********** END OF __DISPLAY_H__ **********~~~~~~~~~~ */

#endif
