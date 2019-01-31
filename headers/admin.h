/*
    To take care of all the back-end processes like...

    Calculating fees, generating TicketID, etc.
*/


#ifndef __ADMIN_H__
#define __ADMIN_H__

/* ~~~~~~~~~~********** START OF __ADMIN_H__ **********~~~~~~~~~~ */


#include "globals.h"
#include "consts.h"

//  Storing customer details
class Customer
{
    protected:
        int ID;
        char name[20+1];
        char username[10+1];
        char password[10+1];
        unsigned char phone[10+1];
        unsigned int age;
        char ticketID[8+1];
        //@TODO: multiple tickets for one user to book

    //  Generates random TicketIDs using 0-9 and A-Z characters


    public:
    //  Constructor : Initialising the variables
        Customer();

    //  Destructor : Freeing / Deallocating the memory
        ~Customer();

    //  Generates new user
        int newUserGenerator(void);
    
    //  Get the credentials from user
        void askCredentials(void);
    
    //  Only admin can use it
        void displayUserDetails(void);
    
    //  Generates an 8 digit ticketID for each ticket generated
        char* ticketIDGenerator(void);
    
    //  Check how the user has logged in: Customer / Admin
        void checkLogin(void);

        int getID(void) const
        {
            return ID;
        }

        Customer setID(int ID)
        {
            this->ID = ID;
            return *this;
        }

};

//  Only for the Administrator
class MovieDetails
{
    private:
        int ID;

    public:
        char name[20];     //  name of movie
        int adult;      //  to be used as boolean
        float rate;     //  out of 5.0
        int critics;    //  out of 100%

        MovieDetails();
        ~MovieDetails(){};

        int getID() const
        {
            return ID;
        }

        MovieDetails setID(int ID)
        {
            this->ID = ID;
            return *this;
        }

        void showMovies()
        {
            gotoxy(1,9);
            cout << "Name: " << name << "      " << endl;   // extra spaces for cleaning previously printed characters
            cout << "Adult: " << (adult ? "Yes" : "No") << "      " << endl;    // extra spaces for cleaning previously printed characters
            cout << "Rate: " << (float) rate << endl;
            cout << "Critics: " << critics << "      " << endl;

            gotoxy(9,7);
        }
}adminMovies[LIMIT];


class MovieSeats : public MovieDetails
{
    public:
        int seats[COL][ROW];    //  seats[14][10]
        MovieSeats();
        ~MovieSeats();
}movieSeats[LIMIT];




//  Customer class Function Definitions   //

Customer::Customer()
    :   ID(NULL), age(NULL)
{
    strcpy(name,"NULL");
    strcpy(username,"NULL");
    strcpy(password,"NULL");
    strcpy(phone,"0000000000");
    strcpy(ticketID,"NULL");
}

Customer::~Customer()
{
    delete[] name;
    delete[] username;
    delete[] password;    
    delete[] ticketID;
}

void readCustomerCountFromFile(void)
{
    ifstream file(FILE__CUSTOMER_COUNT,ios::in);
    file >> customerCount;
    file.close();
}

void writeCustomerCountToFile(void)
{
    ofstream file;
    file.open(FILE__CUSTOMER_COUNT,ios::out);

    file << customerCount;

    file.close();
}

int Customer::newUserGenerator(void)
{
    int i=0;    //  random helper variable

    ofstream file;
    file.open(FILE__USER_DETAILS,ios::in | ios::binary);

    cout << "\t\t\t===================\n";
    cout << "\t\t\t    YOUR DETAILS\n";
    cout << "\t\t\t===================\n";

    cout << "Your Full Name: ";
    gets(name);

    cout << "\n\nUsername: ";
    cin >> username;

    cout << "Password: ";
    while(password[i-1] != 13)  //  while enter key is not pressed
    {
        password[i] = getch();
        cout << '*';
        i++;
    }password[i] = NULL;

    cout << "Phone number (10 digits without spaces): ";
    cin >> phone;

    cout << "Age: ";
    cin >> age;

    readCustomerCountFromFile();    

    if(!customerCount)
        ID = 100;
    else
        ID++;

    customerCount++;
    writeCustomerCountToFile();

    file.write((char*)&*this,sizeof(this));
    file.close();

    cout << "\nYour account has been created successfully!" << endl;

    loggedAsAdmin = false;
    loggedAsUser = true;

    return true;
}


void Customer::askCredentials(void)
{
    int i=0;    //  random counter variable

    cout << "\t\t\t================\n";
    cout << "\t\t\t    Login Page\n";
    cout << "\t\t\t================\n";

    cout << "\t\t\tUsername: ";
    cin >> username;

    cout << "\t\t\tPassword: ";
    while(password[i-1] != 13)
    {
        password[i] = getch();
        cout << '*';
        i++;
    }password[i] = NULL;
}

void Customer::displayUserDetails(void)
{
    ifstream file;
    file.open(FILE__USER_DETAILS,ios::in | ios::binary);

    file.read((char*)this,sizeof(this));

    cout << "ID: " << ID << endl;
    cout << "Name: " << name << endl;
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Phone number: " << phone << endl;
    cout << "Age: " << age << endl;
    cout << "TicketID: " << ticketID << endl;

    file.close();
}

string Customer::ticketIDGenerator()
{
    srand(time(NULL));

    // Length of the ticketID should be 8
    for(int i=0; i<9; i++)
    {
        if(i % 2 == 0)
            *(ticketID+i) = *(ticketHash + (rand()%37));
        else
            *(ticketID+i) = *(ticketHash + (rand()%9));
    }

    *(ticketID+8) = '\0';
    return ticketID;
}

void Customer::checkLogin(void)
{
    //  Checking for login as admin
    if(!(strcmp(username,"admin") && strcmp(password,"admin")))
    {
        loggedAsAdmin = true;
        loggedAsUser = false;
        
        return;
    }
    else    //  Checking for login as user
    {
        ifstream file(FILE__USER_DETAILS,ios::in | ios::binary);

        while(!file.eof())
        {
            file.read((char*)&*this,sizeof(this));

            if(!strcmp(username,this->username))
            {
                loggedAsAdmin = false;
                loggedAsUser = true;

                return;
            }
        }
    }

    loggedAsAdmin = false;
    loggedAsUser = false;

    cout << "You do not appear to have an account already. Returning to Login Menu!\n";
}



//  MovieDetails class Function Definitions   //

MovieDetails::MovieDetails()
    :   adult(false), rate(0.0), critics(NULL)
{
    strcpy(name,"NULL");
}

//  MovieSeats class Function Definitions   //

MovieSeats::MovieSeats()
{
    for(int i=0; i<COL; i++)
    {
        for(int j=0; j<ROW; j++)
        {
            seats[COL][ROW] = false;    // false = 0
        }
    }
}

MovieSeats::~MovieSeats()
{
    delete[] seats;
}



//   Custom functions   //

void addMovieToLibrary()
{
    char choice, answer='n',i=0;
    int ID;

    ofstream file(FILE__MOVIES_DATABASE, ios::app | ios::binary);

    cout << "\t\t\t    =====================\n";
    cout << "\t\t\t     ENTER MOVIE DETAILS\n";
    cout << "\t\t\t    =====================\n";

    do
    {
        cout << "Name: ";
        gets(adminMovies[i].name);

        cout << "Enter movie ID: ";
        cin >> ID;
        adminMovies[i].setID(ID);

        do
        {
            cout << "Is the movie only for Adults(y/n): ";
            cin >> choice;
        }while(!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N'));

        adminMovies[i].adult = (choice == 'y' || choice == 'Y') ? true : false;

        do{
            cout << "How much would you rate the movie (out of 0.0 - 5.0): ";
            cin >> (float) adminMovies[i].rate;
        }while(!(adminMovies[i].rate >= 0.0 && adminMovies[i].rate <= 5.0));

        do
        {
            cout << "How's the critics (out of 0% - 100%): ";
            cin >> adminMovies[i].critics;
        }while(!(adminMovies[i].critics >= 0 && adminMovies[i].critics <= 100));

        file.write((char*)&adminMovies[i], sizeof(MovieDetails));

        cout << "Movie added successfully!" << endl;
        cin.get();

        cout << "\nDo you want to add another movie(y/n): ";
        cin >> answer;
    }while(i < LIMIT && answer == 'y' || answer == 'Y');

    file.close();
}


void deleteMovieFromLibary()
{
    char choice;
    int upto;

    fstream readingFile(FILE__MOVIES_DATABASE, ios::in | ios::binary);
    fstream writingFile;

    cout << "\t\t\t    =====================\n";
    cout << "\t\t\t       AVAILABLE MOVIES\n";
    cout << "\t\t\t    =====================\n";

    if(!readingFile)
    {
        cout << "File not found!" << endl;
        getch();
        return;
    }

    while(!readingFile.eof())
    {
        readingFile.read((char*)&adminMovies[index],sizeof(MovieDetails));
        upto = index;
        index++;
    }
    readingFile.close();

    cout << "Navigation controls: Press 'n' for next and 'p' for previous.\n"
            "Press 'd' to delete the current movie and 'x' to exit.\n\n";
    
    cout << "Choice: ";    
    while(choice != 'x')
    {   
        choice = getche();
        if(choice == 'n')
        {
            index++;
            if(index >= upto)
                index = upto-1;

            adminMovies[index].showMovies();                       
        }

        if(choice == 'p')
        {
            index--;
            if(index <= 0)
                index = 0;

            adminMovies[index].showMovies();
        }

        if(choice == 'd')
        {
            writingFile.open("TEMP.DAT", ios::out | ios::binary);
            for(int i=0; i <= upto; i++)
            {
                if(i != index)
                    writingFile.write((char*)&adminMovies[i],sizeof(MovieDetails));
            }
            writingFile.close();

            remove(FILE__MOVIES_DATABASE);
            system("rename TEMP.DAT movies.dat");

            cout << "Movie deleted successfully!";
            gotoxy(9,7);
        }
    }
}

//  Name is self explanatory
void readSeatsFromFile(void)
{
    ifstream file;
    file.open(FILE__SEATS,ios::in);

    for(int i=0; i<LIMIT; i++)
        file.read((char*)&movieSeats[i],sizeof(MovieSeats));

    file.close();
}

//  Name is self explanatory
void writeSeatsToFile(void)
{
    ofstream file;
    file.open(FILE__SEATS,ios::out);

    for(int i = 0; i < LIMIT; i++)
        file.write((char*)&movieSeats[i],sizeof(MovieSeats));
    file.close();
}

//  for booking the seats of particular movie
void bookSeats(int record)
{
    char choice = 'y', charCol;
    int col, row;

    while(choice != 'n')
    {
        cout << "Enter Column (A-N): ";
        cin >> charCol;

        //  Assigning numerical value according to A=0, B=1 ... N = 13

        switch(charCol)
        {
            case 'A':
            case 'a':
                col = 0;
                break;
            case 'B':
            case 'b':
                col = 1;
                break;
            case 'C':
            case 'c':
                col = 2;
                break;
            case 'D':
            case 'd':
                col = 3;
                break;
            case 'E':
            case 'e':
                col = 4;
                break;
            case 'F':
            case 'f':
                col = 5;
                break;
            case 'G':
            case 'g':
                col = 6;
                break;
            case 'H':
            case 'h':
                col = 7;
                break;
            case 'I':
            case 'i':
                col = 8;
                break;
            case 'J':
            case 'j':
                col = 9;
                break;
            case 'K':
            case 'k':
                col = 10;
                break;
            case 'L':
            case 'l':
                col = 11;
                break;
            case 'M':
            case 'm':
                col = 12;
                break;
            case 'N':
            case 'n':
                col = 13;
                break;
        }


        cout << "Enter Row (1-10): ";
        cin >> row;
        row--;  //  decrementing the value of row as actual array is ranging from 0-9

        movieSeats[record].seats[col][row] = true;

        cout << "Book another seat (y/n): ";
        cin >> choice;
    }

    writeSeatsToFile();    //  writing the seat booking details to file
    
    cout << "Seats booked successfully!" << endl;
    
}



/* ~~~~~~~~~~********** END OF __ADMIN_H__ **********~~~~~~~~~~ */

#endif
