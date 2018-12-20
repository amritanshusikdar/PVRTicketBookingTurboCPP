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
        char *name;
        char *username;
        char *password;
        unsigned long long phone;
        unsigned int age;
        char *ticketID;

    //  Generates random TicketIDs using 0-9 and A-Z characters
        int newUserGenerator();     //  @TODO
        char* ticketIDGenerator();


    public:
    //  Constructor : Initialising the variables
        Customer();

    //  Destructor : Freeing / Deallocating the memory
        ~Customer();

};

//  Only for the Administrator
class MovieDetails
{
    protected:
        int ID;

    public:
        char name[20];     //  name of movie
        int adult;      //  to be used as boolean
        float rate;     //  out of 5.0
        int critics;    //  out of 100%

        MovieDetails();
        ~MovieDetails();

        int getID() const
        {
            return ID;
        }

        void setID(int& ID)
        {
            this.ID = ID;
        }

        void showMovies()
        {
            cout << "Name: " << name << endl;
            cout << "Adult: " << (adult ? "Yes" : "No") << endl;
            cout << "Rate: " << (float) rate << endl;
            cout << "Critics: " << critics << endl;
        }
};

//  maintaining seating coordinates
class Seats : public MovieDetails
{
    protected:
        unsigned int x;
        enum SEAT_ROW y;

    public:
        Seats() : x(0), y(A) {}
        void occupySeat();
        int isSeatOccupied();
};





//  Customer class Function Definitions   //

Customer::Customer()
    :   name(new char[20]), username(new char[10]), password(new char[10]),
        phone(NULL), age(NULL), ticketID(new char[9])
{}

Customer::~Customer()
{
    delete[] name;
    delete[] username;
    delete[] password;
    delete[] ticketID;
}


char* Customer::ticketIDGenerator()
{
    srand(time(NULL));

    // Length of the ticketID should be 8
    for(int i=0; i<9; i++)
    {
        *(ticketID+i) = *(ticketHash + (rand()%37));
    }

    *(ticketID+8) = '\0';
    return ticketID;
}



//  MovieDetails class Function Definitions   //

MovieDetails::MovieDetails()
    :   adult(false), rate(0.0), critics(NULL)
{
    strcpy(name,"NULL");
}

MovieDetails::~MovieDetails()
{
    delete[] name;
}



//  Seats class Function Definitions    //

void Seats::occupySeat()
{}

int Seats::isSeatOccupied()
{return 0;}





void addMovieToLibrary(MovieDetails& admin)
{
    char choice, answer='n';
    int ID;

    ofstream file(FILE__MOVIES_DATABASE, ios::app | ios::binary);

    cout << "\t\t\t    =====================\n";
    cout << "\t\t\t     ENTER MOVIE DETAILS\n";
    cout << "\t\t\t    =====================\n";

    do
    {
        cout << "Name: ";
        gets(admin.name);

        cout << "Enter movie ID: ";
        cin >> ID;
        admin.setID(ID);

        do
        {
            cout << "Is the movie only for Adults(y/n): ";
            cin >> choice;
        }while(!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N'));

        admin.adult = (choice == 'y' || choice == 'Y') ? true : false;

        do{
            cout << "How much would you rate the movie(out of 0.0 - 5.0): ";
            cin >> (float) admin.rate;
        }while(!(admin.rate >= 0.0 && admin.rate <= 5.0));

        do
        {
            cout << "How's the critics(out of 0% - 100%): ";
            cin >> admin.critics;
        }while(!(admin.critics >= 0 && admin.critics <= 100));

        file.write((char*)admin, sizeof(admin));

        cout << "Movie added successfully!" << endl;
        cin.get();

        cout << "\nDo you want to add another movie(y/n): ";
        cin >> answer;
    }while(answer == 'y' || answer == 'Y');

    file.close();
}


void deleteMovieFromLibary(MovieDetails& admin )
{
    fstream file(FILE__MOVIES_DATABASE, ios::in | ios::binary);

    cout << "\t\t\t    =====================\n";
    cout << "\t\t\t       AVAILABLE MOVIES\n";
    cout << "\t\t\t    =====================\n";

    if(!file)
    {
        cout << "File not found!" << endl;
        getch();
        return;
    }

    while(!file.eof())
    {
        file.read((char*)admin, sizeof(admin));

        admin.showMovies();
    }


    cout << "\n\n";
    cout << "\t\t\t    =====================\n";
    cout << "\t\t\t     ENTER MOVIE DETAILS\n";
    cout << "\t\t\t    =====================\n";

    file.close();
}



/* ~~~~~~~~~~********** END OF __ADMIN_H__ **********~~~~~~~~~~ */

#endif
