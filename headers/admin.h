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
    public:
        int ID;
        char name[20+1];
        char username[10+1];
        char password[10+1];
        unsigned char phone[10+1];
        unsigned int age;
        char ticketID[8+1];
        int movieID;    //  To keep tract of which movie the user has booked the ticket for

    //  Constructor : Initialising the variables
        Customer();

    //  Destructor : Freeing / Deallocating the memory
        ~Customer();
    
    //  Get the credentials from user
        void askCredentials(void);
    
    //  Generates an 8 digit ticketID for each ticket generated
        string ticketIDGenerator(void);

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
            gotoxy(5,9);
            cout << "Name: " << name << "      " << endl;   // extra spaces for cleaning previously printed characters
            cout << "Adult: " << (adult ? "Yes" : "No") << "      " << endl;    // extra spaces for cleaning previously printed characters
            cout << "Rate: " << (float) rate << endl;
            cout << "Critics: " << critics << "      " << endl;
        }
}adminMovies[LIMIT];


class MovieSeats : public MovieDetails
{
    public:
        int seats[COL][ROW];    //  seats[14][10]
        void resetSeats();
        ~MovieSeats();
}movieSeats[LIMIT];




//  Customer class Function Definitions   //

Customer::Customer()
    :   ID(NULL), age(NULL), movieID(NULL)
{
    strcpy(name,"NULL");
    strcpy(username,"NULL");
    strcpy(password,"NULL");
    strcpy(phone,"0000000000");
    strcpy(ticketID,"NULL");
}

Customer::~Customer(){}

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

//  Generates new user
int newUserGenerator(void)
{
    int i=0;    //  random helper variable
    Customer person;

    ofstream file;
    file.open(FILE__USER_DETAILS,ios::app | ios::binary);

    cout << "\t\t\t===================\n";
    cout << "\t\t\t    YOUR DETAILS\n";
    cout << "\t\t\t===================\n";

    cout << "Your Full Name: ";
    gets(person.name);

    cout << "\n\nUsername: ";
    cin >> person.username;

    memset(person.password,0,11);  //  clearing/cleaning the entire array
    cout << "Password: ";
    while(person.password[i-1] != 13)  //  while enter key is not pressed
    {
        person.password[i] = getch();
        if(person.password[i] == 8 && i>=0)
        {
            cout << "\b \b";
            i--;
        }
        else
        {
            cout << '*';
            i++;
        }
    }person.password[i-1] = NULL;

    cout << "\nPhone number (10 digits without spaces): ";
    cin >> person.phone;

    cout << "Age: ";
    cin >> person.age;

    readCustomerCountFromFile();

    if(!customerCount)
        person.ID = 100;
    else
        person.ID = customerCount + 100;
    
    customerCount++;
    writeCustomerCountToFile();

    file.write((char*)&person,sizeof(Customer));
    file.close();

    cout << "\nYour account has been created successfully!" << endl;

    getch();
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
    
    memset(password,0,11);  //  clearing/cleaning the entire array
    cout << "\t\t\tPassword: ";
    while(password[i-1] != 13)
    {
        password[i] = getch();
        if(password[i] == 8 && i>=0)
        {
            cout << "\b \b";
            i--;
        }
        else
        {
            cout << '*';
            i++;
        }
        
    }password[i-1] = NULL;
}

void displayUserDetails(int ID)
{
    int found = false;
    Customer person;

    ifstream file;
    file.open(FILE__USER_DETAILS,ios::in | ios::binary);

    if(!file)
    {
        cout << "\n\n ERROR: File not found!" << endl;
        getch();
        return;
    }

    while(!file.eof() && !found)
    {
        file.read((char*)&person,sizeof(Customer));

        if(ID == person.ID)
            found = true;
    }

    if(found)
    {
        cout << "ID: " << person.ID << endl;
        cout << "Name: " << person.name << endl;
        cout << "Username: " << person.username << endl;
        cout << "Password: " << person.password << endl;
        cout << "Phone number: " << person.phone << endl;
        cout << "Age: " << person.age << endl;
    }
    else
    {
       cout << "\nUnknown Error in displaying user details.\n";
    }
    

    file.close();

    getch();
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

int checkLogin(Customer person)
{
    Customer check;

    //  Checking for login as admin
    if(!strcmp(person.username,"admin") && !strcmp(person.password,"admin"))
    {
        loggedAsAdmin = true;
        loggedAsUser = false;
        
        return 69;   //  69 is for admin
    }
    else    //  Checking for login as user
    {
        ifstream file(FILE__USER_DETAILS,ios::in | ios::binary);

        while(!file.eof())
        {
            file.read((char*)&check,sizeof(Customer));

            if(!strcmp(check.username,person.username) && !strcmp(check.password,person.password))
            {
                loggedAsAdmin = false;
                loggedAsUser = true;
                person.ID = check.ID;
                return person.getID();
            }
        }
        file.close();
    }

    loggedAsAdmin = false;
    loggedAsUser = false;

    cout << "\nSorry, no such username-password combination found.\n";
    getch();
    return -1;  //  Account doesn't exist
}



//  MovieDetails class Function Definitions   //

MovieDetails::MovieDetails()
    :   adult(false), rate(0.0), critics(NULL)
{
    strcpy(name,"NULL");
}

//  MovieSeats class Function Definitions   //

void MovieSeats::resetSeats()
{
    for(int i=0; i<COL; i++)
    {
        for(int j=0; j<ROW; j++)
        {
            seats[COL][ROW] = false;    // false = 0
        }
    }

    cout << "Seats have been reset successfully!" << endl;
    getch();
}

//   Custom functions   //

void addMovieToLibrary()
{
    char choice, answer='n';
    int ID;

    index = 0;

    ofstream file(FILE__MOVIES_DATABASE, ios::app | ios::binary);

    cout << "\t\t\t    =====================\n";
    cout << "\t\t\t     ENTER MOVIE DETAILS\n";
    cout << "\t\t\t    =====================\n";

    do
    {
        cout << "Name: ";
        gets(adminMovies[index].name);

        cout << "Enter movie ID: ";
        cin >> ID;
        adminMovies[index].setID(ID);

        do
        {
            cout << "Is the movie only for Adults(y/n): ";
            cin >> choice;
        }while(!(choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N'));

        adminMovies[index].adult = (choice == 'y' || choice == 'Y') ? true : false;

        do{
            cout << "How much would you rate the movie (out of 0.0 - 5.0): ";
            cin >> (float) adminMovies[index].rate;
        }while(!(adminMovies[index].rate >= 0.0 && adminMovies[index].rate <= 5.0));

        do
        {
            cout << "How's the critics (out of 0% - 100%): ";
            cin >> adminMovies[index].critics;
        }while(!(adminMovies[index].critics >= 0 && adminMovies[index].critics <= 100));

        file.write((char*)&adminMovies[index], sizeof(MovieDetails));

        cout << "Movie added successfully!" << endl;
        cin.get();
        index++;

        cout << "\nDo you want to add another movie(y/n): ";
        cin >> answer;
    }while((index < LIMIT) && (answer == 'y' || answer == 'Y'));

    if(index == LIMIT)
    {
        cout << "The max limit (5) for movies has been reached." << endl;
        index--;
    }

    file.close();
}


void deleteMovieFromLibary()
{
    index = 0;

    char choice;
    int upto=0;

    ifstream readingFile(FILE__MOVIES_DATABASE, ios::in | ios::binary);
    ofstream writingFile;

    clrscr();

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
    index=0;
    upto--;
    readingFile.close();

    cout << "Navigation controls: Press 'n' for next and 'p' for previous.\n"
            "Press 'd' to delete the current movie and 'x' to exit.\n\n";
    
    cout << "Choice: ";
    while(choice != 'x')
    {   
        choice = getch();

        if(upto <= -1)
        {
            cout << "No movies to show. " << endl;
            getch();
            choice = 'x';
        }
        else
        {
            if(choice == 'n')
            {
                index++;
                if(index > upto)
                    index = upto;

                adminMovies[index].showMovies();                       
            }

            if(choice == 'p')
            {
                index--;
                if(index < 0)
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

                cout << "\nMovie deleted successfully!";

                getch();

                break;
            }
        }
        
    }
}

//  Name is self explanatory
void readSeatsFromFile(void)
{
    ifstream file;
    file.open(FILE__SEATS,ios::in | ios::binary);

    for(int i=0; i<LIMIT; i++)
        file.read((char*)&movieSeats[i],sizeof(MovieSeats));
    file.close();
}

//  Name is self explanatory
void writeSeatsToFile(void)
{
    ofstream file;
    file.open(FILE__SEATS,ios::out | ios::binary);

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
        cout << "\n\nEnter Column (A-N): ";
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
    
    cout << "\nSeats booked successfully!" << endl;   
}

//	For displaying booked/unbooked seats of a particular movie
void showSeats(int record)
{
    readSeatsFromFile();	//	writing the seat details from file to cpp objects

    char alphabet = 'A';

    cout << "\n\n\n\n\n\n\n\n";
    cout << "\t\t       ";

    cout << '-' << char(197) << "- ";

    for(int i=0; i<15; i++)
    {
        for(int j=0; j<10; j++)
        {
                if(i==0)
                    cout << j+1 << "  ";
                else
                {
                    if(movieSeats[record].seats[i-1][j])	//	if the particular seat is booked
                        cout << "  " << char(4);
                    else	//	if the particular seat ain't booked
                        cout << "  " << char(127);
                }
        } cout << endl << "\t\t\t";

        if(i<=13)
            cout << alphabet++;
    }
}

//  function to book a movie for a specific userID
void bookMovie(int ID)
{
    index = 0;
    Customer person;
    char choice;
    int upto=0, move=0;

    ifstream readingFile;
    ofstream writingFile;

    clrscr();

    cout << "\t\t\t    =====================\n";
    cout << "\t\t\t       AVAILABLE MOVIES\n";
    cout << "\t\t\t    =====================\n";

    readingFile.open(FILE__MOVIES_DATABASE, ios::in | ios::binary);
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
    index=0;
    upto--;
    readingFile.close();

    cout << "Navigation controls: Press 'n' for next and 'p' for previous.\n"
            "Press 's' to select the current movie and 'x' to exit.\n\n";
    
    cout << "Choice: ";
    while(choice != 'x')
    {   
        choice = getch();

        if(upto <= -1)
        {
            cout << "No movies to show. " << endl;
            getch();
            choice = 'x';
        }
        else
        {
            if(choice == 'n')
            {
                index++;
                if(index > upto)
                    index = upto;

                adminMovies[index].showMovies();                       
            }

            if(choice == 'p')
            {
                index--;
                if(index < 0)
                    index = 0;

                adminMovies[index].showMovies();
            }

            if(choice == 's')
            {
                readingFile.open(FILE__USER_DETAILS,ios::in|ios::binary);
                while(!readingFile.eof())
                {
                    readingFile.read((char*)&person,sizeof(person));
                    if(person.ID == ID)
                        break;
                }
                readingFile.close();

                strcpy(person.ticketID,person.ticketIDGenerator());   //  assigning ticketID to the user booking the movie
                person.movieID = adminMovies[index].getID();
                
                writingFile.open(FILE__USER_DETAILS,ios::out|ios::binary);
                if(ID==0) move=0; else move = ((ID%100)-1) * sizeof(person);
                writingFile.seekp(move,ios::beg);
                writingFile.write((char*)&person,sizeof(person));
                writingFile.close();

                readSeatsFromFile();
                bookSeats(index);
                writeSeatsToFile();

                cout << "\nMovie booked successfully!";

                getch();

                break;
            }
        }
        
    }
}

//  To display details about the user's booked ticket
void showMyTicket(int ID)
{
    Customer person;
    MovieDetails movie;
    ifstream file;
    int track=0;
    
    //  For reading the user details
    file.open(FILE__USER_DETAILS,ios::in|ios::binary);
    while(!file.eof())
    {
        file.read((char*)&person,sizeof(person));
        if(ID == person.ID)
            break;
    }file.close();

    if(!strcmp(person.ticketID,"NULL"))
    {
        cout << "\nYou haven't booked any tickets yet!" << endl;
        getch();
    }
    else
    {
        //  For checking the movie the user has booked the ticket for
        file.open(FILE__MOVIES_DATABASE,ios::in|ios::binary);
        while(!file.eof())
        {
            track++;      
            file.read((char*)&movie,sizeof(movie));
            if(movie.getID() == person.movieID)
                break;
        }file.close();

        clrscr();

        cout << "\nMy ticket ID is: " << person.ticketID << endl;

        movie.showMovies();
        getch();
        cout << "\nThe booked seats are as follows: " << endl;
        showSeats(track-1);
        getch();
    }
}

/* ~~~~~~~~~~********** END OF __ADMIN_H__ **********~~~~~~~~~~ */

#endif
