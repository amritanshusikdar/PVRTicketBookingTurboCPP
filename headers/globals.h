//  Truth values

#ifndef __GLOBALS_H__
#define __GLOBALS_H__

/* ~~~~~~~~~~********** START OF __GLOBALS_H__ **********~~~~~~~~~~ */

#define false 0
#define true !false

//  Login checks --- also assigning initial values
//  tells the login medium

static int loggedAsUser = true;
static int loggedAsAdmin = false;
static int loggedAsGuest = false;
static int index = 0;  //  check which movie index is currently being worked upon


//  Typedefs

typedef char* string;

/* ~~~~~~~~~~********** END OF __GLOBALS_H__ **********~~~~~~~~~~ */

#endif
