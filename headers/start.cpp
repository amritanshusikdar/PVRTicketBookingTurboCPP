//  C++ Library
#include <fstream.h>
#include <cstream.h>
#include <stdio.h>
#include <stdlib.h>
#include <dos.h>
#include <string.h>
#include <time.h>

//  Custom headers written for this project

#include "admin.h"
#include "display.h"

int loginMenuChoice, adminMenuChoice, userMenuChoice;
Customer person;

void commenceTheBusiness(void)
{
    welcomeAndThanks(!0);

    while(loginMenuChoice != 4)
    {
        loginMenuChoice = loginMenu();

        if(loginMenuChoice == 1)
        {
            person.askCredentials();
            person.checkLogin();

            if(loggedAsAdmin)
            {
                while(adminMenuChoice != 4)
                {
                    adminMenuChoice = adminMenu();

                    if(adminMenuChoice == 1)
                        addMovieToLibrary();
                    
                    if(adminMenuChoice == 2)
                        deleteMovieFromLibary();
                    
                    if(adminMenuChoice == 3)
                    {
                        int number;
                        while(!(number >= 0 && number <= 4))
                        {
                            cout << "\nEnter the Movie no. whose seats to be reset(0-4): ";
                            cin >> number;
                        }
                        movieSeats[number].resetSeats();
                    }
                }
            }
            else if(loggedAsUser)
            {
                while(userMenuChoice != 4)
                {
                    userMenuChoice = userMenu();
                    if(userMenuChoice == 1)
                        //  book a show
                        person.displayUserDetails();
                    
                    if(userMenuChoice == 2)
                        person.displayUserDetails();
                    
                    if(userMenuChoice == 3)
                        //  my already booked tickets
                        person.displayUserDetails();
                }
            }
            
        }
        
        if(loginMenuChoice == 2)
        {
            person.newUserGenerator();
            commenceTheBusiness();  //  Self recurring/calling function
        }

        if(loginMenuChoice == 3)
        {
            customerService();
            commenceTheBusiness();  //  Self recurring/calling function
        }
    }

    welcomeAndThanks(0);
}
