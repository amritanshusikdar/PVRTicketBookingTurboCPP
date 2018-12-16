/* 
    To take care of all the back-end processes like...

    Calculating fees, generating TicketID, etc.
 */


#include <stdlib.h>
#include <time.h>
#include <iostream.h>


static const char ticketHash[37] = "0123456789"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char ticketID[9];

class Administrator {
    private:
    protected:
    public:
    //  Generates random TicketIDs using 0-9 and A-Z characters
        void ticketIDGenerator();

        ~Administrator() {
        }
};

class Manager : public Administrator {
    private:
    protected:
    public:
};

//  Class Function Definitions   //

void Administrator::ticketIDGenerator() {
    srand(time(NULL));
    
    for(int i=0; i<9; i++) {
        *(ticketID+i) = *(ticketHash + (rand()%37));
    }

    *(ticketID+8) = '\0';
}
