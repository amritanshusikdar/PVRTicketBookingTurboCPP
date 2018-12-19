//  Truth values

#define false 0
#define true !false

//  Login checks --- also assigning initial values
//  tells the login medium

static int loggedAsUser = true;
static int loggedAsAdmin = false;
static int loggedAsGuest = false;


//  Seat alphabetical coordinates

enum SEAT_ROW     // to be declared as--->     SEAT_ROW var = SEAT_ROW::C;  // to be used as SEAT_ROW::C
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
