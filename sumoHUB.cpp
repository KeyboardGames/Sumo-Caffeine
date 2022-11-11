#include <vlCore/VisualizationLibrary.hpp>
#include <vlGraphics/Text.hpp>
#include <vlGraphics/Applet.hpp>
#include <vlGraphics/RenderingTree.hpp>
#include <vlGraphics/SceneManager.hpp>
#include <vlCore/Time.hpp>
#include <vlCore/ResourceDatabase.hpp>
#include <vlGraphics/MorphingCallback.hpp>
#include <vlWin32/Win32Window.hpp>
#include <vlWin32/Win32Context.hpp>
#include <vlCore/Colors.hpp>
#include <vlCore/Say.hpp>
#include <vlCore/Log.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include "Taxi/Model.h"
#include "Taxi/Camera.h"
#include "Taxi/Complex.h"
#include "Taxi/Input.h"
#include "Taxi/Text.h"
#include "Taxi/Window.h"
#include "App_Taxi.hpp"
#include "intro.h"
#include "sumoHUB.h"
#include "arena.h"
#include "cameraSUMO.h"
#include "inputHUB.h"
int sumoA=1;
int mugMA;
int damageHit;
double difficultMA, difficultMB;
std::string textureTEAA, textureCOFFEEA;
std::string playerNameA, playerNameB;

void sumoBegin(int mugM, std::string playerName, std::string enemyName, std::string textureTEA, std::string textureCOFFEE, double difficultM1, int difficultM2, int damageH);

void sumoBegin(int mugM, std::string playerName, std::string otherName, std::string textureTEA, std::string textureCOFFEE, double difficultM1, int difficultM2, int damageH)
{
    //set variables
    textureTEAA=textureTEA;
    textureCOFFEEA=textureCOFFEE;
    difficultMA=difficultM1;
    mug2Speed=difficultMA;
    difficultMB=difficultM2;
    mugMA=mugM;
    playerNameA=playerName;
    playerNameB=otherName;
    damageHit=damageH;
    //camera
    if(showA==1 && menuC==1 && pickA==4 && menuA==1 && uniqueP==1)
    {
    arenaCameraForm();
    countdownARENA();
    }
    //results
    if(matchA==2 && shatteredA==1 && showA==1 && menuC==1 && pickA==4 && menuA==1 && uniqueP==1)
    {
        if(resultM==2)
        {
            outcomeA();
        }
        if(resultM==3)
        {
            outcomeB();
        }
    }
    //shatter
    if(matchA==1 && shatteredA==2 && showA==1 && menuC==1 && pickA==4 && menuA==1 && uniqueP==1)
    {
        mugShatter();
    }
    //load models (calculate hitboxes)
    if(matchA==1 && pickA==4 && menuA==1 && uniqueP==1)
    {
    loadArena();
    if(shatteredA==1)
    {
    loadMugs();
    }
    loadHealth();
    if(shatteredA==1 && showA==1 && menuC==1 && pickA==4 && menuA==1 && uniqueP==1)
    {
    loadOut();
    //important
    mugMove();
    loadHit();
    }
    }
}
