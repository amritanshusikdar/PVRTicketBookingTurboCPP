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
    loginMenuChoice = loginMenu();

    if(loginMenuChoice == 1)
    {
        person.askCredentials();
        person.checkLogin();

        if(loggedAsAdmin)
        {
            adminMenuChoice = adminMenu();
        }
        else if(loggedAsUser)
        {
            userMenuChoice = userMenu();
        }
    }

    if(loginMenuChoice == 2)
    {
        person.newUserGenerator();
        commenceTheBusiness();
    }

    if(loginMenuChoice == 3)
    {
        customerService();
        commenceTheBusiness();  //  Self recurring/calling function
    }

    if(loginMenuChoice == 4)
    {
        welcomeAndThanks(!0);
    }
}
