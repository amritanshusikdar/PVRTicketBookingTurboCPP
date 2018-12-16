/* 
    To take care of all the back-end processes like...

    Calculating fees, generating TicketID, etc.
 */


#include <stdlib.h>
#include <time.h>
#include <iostream.h>


const char ticketHash[37] = "0123456789"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

class Administrator {
    private:
    protected:
    public:
    //  Generates random TicketIDs using 0-9 and A-Z characters
        char *ticketIDGenerator();
};

class Manager : public Administrator {
    private:
    protected:
    public:
};

//  Class Function Definitions   //

char* Administrator::ticketIDGenerator() {
    
    int index;
    char ID[6];

    srand(time(NULL));
    
    for(int i=0; i<5; i++) {
        index = rand() % 37;
        *(ID+index) = *(ticketHash+index);
    }

    *(ID+5) = '\0';

    cout << ID;

    return (char*)ID;
}
