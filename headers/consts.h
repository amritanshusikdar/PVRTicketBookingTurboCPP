/* Constants for "admin.h" */

//  names of identifiers and files should be self explanatory
static const char FILE__GUEST_FILE[10] = "guest.dat";
static const char FILE__TICKET_ID_STORAGE[13] = "ticketID.dat";
static const char FILE__USER_LOGIN_DETAILS[13] = "userData.dat";
static const char FILE__MOVIES_DATABASE[11] = "movies.dat";
static const char FILE__SEATS_AVAILABLE[10] = "seats.dat";

static const char ticketHash[37] = "0123456789"
                            "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/* 

for movies
name
age
rate ----- 4.4
critics ---- 97% */

/* 
for user
name
username
phone number
password
age
 */


/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


/* Constants for "display.h" */

static const int loadWaitDelay = 40;