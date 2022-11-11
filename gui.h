#ifndef _gui_INCLUDE
#define _gui_INCLUDE

#include "Taxi/Audio.h"

extern sf::Music clickM;
extern int uniqueP;
extern int mugTI;
extern int menuA;
extern int startA;

//menu
void guiMenu();
void actMenu();
void moveMenu();
void keyMenu();

//start screen
void guiStart();
void moveStart();
void keyStart();

#endif
