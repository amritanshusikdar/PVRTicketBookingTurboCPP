#include <cstream.h>
#include <globals.h>

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


int main()
{
    clrscr();

    int something = adminMenu();
    cout << "\n\nYou entered: " << something;

    getch();
    return 0;
}