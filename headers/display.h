/* 
    All front end "To be displayed on screen" functions are defined here
    Eg: welcomeScreen, loadingScreen, viewEmptySeats, etc.
 */

#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <string.h>

const int loadWaitDelay = 40;

void welcomeScreen(char* message) {
    clrscr();
    cout << message << endl;
}

// Returns Choice //
int loginMenu() {

	clrscr();

    //  Starting the drawing  //

	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t*-------------------------*";
	for(size_t i=0; i<9; i++) {
		switch(i) {
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
				cout << "\n\t\t\t|\t1. Login\t  |";
			break;

			case 5:
				cout << "\n\t\t\t|\t2. Register\t  |";
			break;

			case 6:
				cout << "\n\t\t\t|\t3. Use Guest\t  |";
			break;

			case 7:
				cout << "\n\t\t\t|\t4. Quit\t\t  |";
			break;

			default:
				cout << "\n\t\t\t|\t\t\t  |";
		}
	}
	
	cout << "\n\t\t\t*-------------------------*\n\n";
	cout << "\t\t\t   Enter your choice: "; return getch();
}



void loadWait(char *phrase) {
    clrscr();

    int i=4;
    int x=26, y=13;

    gotoxy((80-strlen(phrase))/2,y-2);
    cout << phrase << endl;

    gotoxy(35,y-1);
    cout << "Loading...";

    while(i <= 100) {
        gotoxy(48,12);
        cout << '\\' << (char) 8;   // Printing backspace character --- ASCII = 8
        delay(loadWaitDelay);
        cout << '|' << (char) 8;
        delay(loadWaitDelay);
        cout << '/' << (char) 8;
        delay(loadWaitDelay);
        cout << '-' << (char) 8;
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
        cout << i << '%';

        i+=8;
    }

    delay(100);
}


void goodBye(void) {
    cout << "\n\nThanks for Visiting!\n\n";
}
