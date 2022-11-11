#ifndef _arena_INCLUDE
#define _arena_INCLUDE

extern int shatteredA;
extern int countA;
extern int resultM;
extern int pushM;
extern int matchA;
extern int health1, health2;
extern int damage1, damage2;
extern int winsM, loseM;
extern double mug1X, mug1Z;
extern double mug2X, mug2Z;
extern double mug2Speed;

void matchReset();
void roundReset();
void countdownARENA();
void loadArena();
void loadMugs();
void loadHealth();
void loadOut();
void mugMove();
void loadHit();
void outcomeA();
void outcomeB();
void mugShatter();

#endif
