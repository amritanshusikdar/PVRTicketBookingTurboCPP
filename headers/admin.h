/* 
    To take care of all the back-end processes like...

    Calculating fees, generating TicketID, etc.
 */

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
class movieDetails
{
    protected:
        char *name;     //  name of movie
        int adult;      //  to be used as boolean
        float rate;     //  out of 5.0
        int critics;    //  out of 100%

    public:
        movieDetails();
        ~movieDetails();
};

//  maintaining seating coordinates
class seats : public movieDetails
{
    protected:
        unsigned int x;
        SEAT_ROW y;
    
    public:
        seats() { x = 0; }
        void occupySeat();
        int isSeatOccupied();
};


//  Customer class Function Definitions   //

Customer::Customer()
{
    name = new char[20];
    username = new char[10];
    password = new char[10];
    phone = NULL;
    age = NULL;
    ticketID = new char[9];
}

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



//  movieDetails class Function Definitions   //

movieDetails::movieDetails()
{
    name = new char[20];
    adult = false;
    rate = 0.0;
    critics = NULL;
}

movieDetails::~movieDetails()
{
    delete[] name;
}



//  seats class Function Definitions    //

void seats::occupySeat()
{}

int seats::isSeatOccupied()
{}
