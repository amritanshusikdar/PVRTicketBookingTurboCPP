/* 
    To take care of all the back-end processes like...

    Calculating fees, generating TicketID, etc.
 */


#include <iostream.h>
#include <stdlib.h>
#include <time.h>


//  Defining file name constants for ease of use

//  names should be self explanatory
const char FILE__GUEST_FILE[10] = "guest.dat";
const char FILE__TICKET_ID_STORAGE[13] = "ticketID.dat";
const char FILE__USER_LOGIN_DETAILS[13] = "userData.txt";
const char FILE__MOVIES_DATABASE[11] = "movies.txt";


static const char ticketHash[37] = "0123456789"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Administrator {
    private:
        char *ticketID;
    protected:
    public:

    //  Generates random TicketIDs using 0-9 and A-Z characters
        char* ticketIDGenerator();
};

class Manager : public Administrator {
    private:
    protected:
    public:
};

struct Accounts {

    //  Name of the user
    char name[30];

    // Age of the user, to check whether eligible for 18+ movies
    unsigned int age;


};

//  Class Function Definitions   //

char* Administrator::ticketIDGenerator() {
    srand(time(NULL));
    for(int i=0; i<9; i++) {
        *(ticketID+i) = *(ticketHash + (rand()%37));
    }

    *(ticketID+8) = '\0';
    return ticketID;
}
