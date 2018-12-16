/* 
    All front end "To be displayed on screen" functions are defined here
    Eg: welcomeScreen, loadingScreen, viewEmptySeats, etc.
 */

#include <iostream.h>
#include <conio.h>
#include <dos.h>

const int loadWaitDelay = 40;

void welcomeScreen(char* message) {
    clrscr();
    cout << message << endl;
}

// Returns Choice //
int loginMenu(){
	clrscr();
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t*-------------------------*";
	for(int i=0; i<9; i++){
		switch(i){
			case 0:
				cout << "\n\t\t\t|\t ---------\t  |";
			break;

			case 1:
				cout << "\n\t\t\t|\t PVR Sikka\t  |";
			break;

			case 2:
				cout << "\n\t\t\t|\t ---------\t  |";
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

    cout << phrase << endl;
    int i=4;
    int x=-1, y=3;

    cout << "Loading...";

    while(i <= 100) {
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

void goodBye(void) {
    cout << "\n\nThanks for Visiting!\n\n";
}
