/* 
    To take care of all the back-end processes like...

    Calculating fees, generating TicketID, etc.
 */

/* One time functions are here */
class Administrator
{
    private:
        char *userID;
        char *password;
        unsigned int age;
        char *ticketID;
    
    
    protected:
    

    //  Generates random TicketIDs using 0-9 and A-Z characters
        char* ticketIDGenerator();
        int newUserGenerator();     //  @TODO
    
    
    public:
    //  Constructor : Initialising the variables
        Administrator();

    //  Destructor : Freeing / Deallocating the memory
        ~Administrator();

};

/* Function to be used recursively are here */
class Manager : public Administrator
{
    private:


    protected:
    //  Ask user for login credentials
        void askCredentials();  // @TODO
        void checkLogin();  // @TODO

    public:
        Manager();
        ~Manager();
};



//  Administrator class Function Definitions   //

Administrator::Administrator()
{
    userID = new char[10];
    password = new char[10];
    ticketID = new char[9];

    age = 0;
}

Administrator::~Administrator()
{
    delete[] userID;
    delete[] password;
    delete[] ticketID;
}

void Manager::askCredentials()
{}

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
