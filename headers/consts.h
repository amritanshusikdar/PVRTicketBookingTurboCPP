
#ifndef __CONSTS_H__
#define __CONSTS_H__

/* ~~~~~~~~~~********** START OF __CONSTS_H__ **********~~~~~~~~~~ */

/* Constants for "admin.h" */

//  names of identifiers and files should be self explanatory
static const char FILE__USER_DETAILS[13] = "userData.dat";
static const char FILE__TICKET_ID_STORAGE[13] = "ticketID.dat";
static const char FILE__MOVIES_DATABASE[11] = "movies.dat";
static const char FILE__SEATS[10] = "seats.dat";
static const char FILE__CUSTOMER_COUNT[18] = "customerCount.txt";

static const char ticketHash[37] = "0123456789"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

//  Limit for number of movies
static const int LIMIT = 5;

//  Rows and columns for the seats
static const int ROW = 10;
static const int COL = 14;

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* Constants for "display.h" */

//  loading screen delay
static const int loadWaitDelay = 40;



/* ~~~~~~~~~~********** END OF __CONSTS_H__ **********~~~~~~~~~~ */

#endif
