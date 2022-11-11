#ifndef _sumoHUB_INCLUDE
#define _sumoHUB_INCLUDE

extern int sumoA;
extern int damageHit;
extern double difficultMA, difficultMB;
extern std::string textureTEAA, textureCOFFEEA;
extern std::string playerNameA, playerNameB;
extern int mugMA;

//mugM==1 (player=tea)
//mugM==2 (player=coffee)
void sumoBegin(int mugM, std::string playerName, std::string otherName, std::string textureTEA, std::string textureCOFFEE, double difficultM1, int difficultM2, int damageH);

#endif
