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


//  Seat alphabetical coordinates

enum SEAT_ROW
{
    A=0,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N
};

// struct SEAT_ROW_OPERATERPP
// {    
//     SEAT_ROW operator^(SEAT_ROW Z)
//     {
//         return SEAT_ROW(Z+1);
//     }
// };

// SEAT_ROW operator ++ (SEAT_ROW Z)
// {
//     return SEAT_ROW(Z+1);
// }

/* ~~~~~~~~~~********** END OF __GLOBALS_H__ **********~~~~~~~~~~ */

#endif
