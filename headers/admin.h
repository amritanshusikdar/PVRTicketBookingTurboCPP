/* 
    To take care of all the back-end processes like...

    Calculating fees, generating TicketID, etc.
 */


#include <iostream.h>
#include <stdlib.h>
#include <time.h>


//  Defining file name constants for ease of use




static const char ticketHash[37] = "0123456789"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Administrator
{
    private:
        char *userID;
        char *password;
        char *ticketID;
    protected:
    public:
    //  Constructor : Initialising the variables
        Administrator();

    //  Destructor : Freeing / Deallocating the memory
        ~Administrator();

    //  Generates random TicketIDs using 0-9 and A-Z characters
        char* ticketIDGenerator();
};

class Manager : public Administrator
{
    private:
    protected:
    public:
        Manager();
        ~Manager();
};

struct Accounts
{

    //  Name of the user
    char name[30];

    // Age of the user, to check whether eligible for 18+ movies
    unsigned int age;
};







//  Administrator class Function Definitions   //

Administrator::Administrator()
{
    userID = new char[10];
    password = new char[10];
    ticketID = new char[9];
}

Administrator::~Administrator()
{
    delete[] userID;
    delete[] password;
    delete[] ticketID;
}

char* Administrator::ticketIDGenerator()
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







//  Manager class Function Definitions  //

Manager::Manager()
{}

Manager::~Manager()
{}
