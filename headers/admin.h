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
        char *name;     //  name of movie
        int adult;      //  to be used as boolean
        float rate;     //  out of 5.0
        int critics;    //  out of 100%

    public:
        MovieDetails();
        ~MovieDetails();
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


class Admin : public MovieDetails
{
    protected:
        char *username;
        char *password;
    public:
        Admin();
        ~Admin();
        int adminMenu();
        void addMovieToLibrary();
        void deleteMovieFromLibary(int movieID);
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
    :   name(new char[20]), adult(false), rate(0.0), critics(NULL)
{}

MovieDetails::~MovieDetails()
{
    delete[] name;
}



//  Seats class Function Definitions    //

void Seats::occupySeat()
{}

int Seats::isSeatOccupied()
{return 0;}



//  Admin class Function Definitions    //

Admin::Admin()
    :   username(new char[6]), password(new char[6])
{
    username = password = "admin";
}

Admin::~Admin()
{
    delete[] username, password;
}

void addMovieToLibrary()
{
    fstream file(FILE__MOVIES_DATABASE, ios::app);
    
}

void deleteMovieFromLibary(int movieID)
{}



/* ~~~~~~~~~~********** END OF __ADMIN_H__ **********~~~~~~~~~~ */

#endif
