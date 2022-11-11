//9 rounds per match
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
#include "sumoHUB.h"
#include "arena.h"
#include "cameraSUMO.h"
#include "inputHUB.h"
#include "gui.h"
sf::Music ringM;
int shatteredA=1, shatteredC=1;
int tickAct=1, tickB=1;
int resultM=1;
int countA=0;
int damage1=0, damage2=0;
int health1=0, health2=0;
int tutTimer=0;
int pushM=1;
int pushMC=1;
int matchA=1;
int roundN=1;
int accordM=1;
int clockP=0;
int winsM=0, loseM=0;
int ringA=1, ringI=1;
int timerEnd=0;
int displayM=1;
double mug1X=-1.7, mug1Y=0.0, mug1Z=1.6;
double mug2X=2.1, mug2Y=0.0, mug2Z=-1.9;
double mug2Speed=0.045;

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

void assignShaderMug1()
{
    std::ostringstream mugTTO;
    std::string mugTT;
    int textureTEAS=textureTEAA.size();
    for(int tts=0; tts<=textureTEAS; tts++)
    {
        if(textureTEAA[tts]==('t') && textureTEAA[tts+1]==('e') && textureTEAA[tts+2]==('a'))
        {
            mugTTO<<""<<textureTEAA[tts+3]<<""<<textureTEAA[tts+4];
        }
    }
    mugTT=mugTTO.str();
    int switchT=1;;
    if(mugTT==("01") || mugTT==("03") || mugTT==("04") || mugTT==("05"))
    {
        effect->shader()->gocMaterial()->setEmission(vl::blue);
        switchT=2;
    }
    if(mugTT==("02"))
    {
        effect->shader()->gocMaterial()->setEmission(vl::orange);
        switchT=2;
    }
    if(levelA==1 && switchT==1)
    {
        effect->shader()->gocMaterial()->setEmission(vl::green);
    }
    if(levelA==2 && switchT==1)
    {
        effect->shader()->gocMaterial()->setEmission(vl::royalblue);
    }
    if(levelA==4 && switchT==1)
    {
        effect->shader()->gocMaterial()->setEmission(vl::red);
    }
    if(levelA==5 && switchT==1)
    {
       effect->shader()->gocMaterial()->setEmission(vl::red);
    }
}

void assignShaderMug2()
{
    std::ostringstream mugTCO;
    std::string mugTC;
    int textureCOFFEES=textureCOFFEEA.size();
    for(int tcs=0; tcs<=textureCOFFEES; tcs++)
    {
        if(textureCOFFEEA[tcs]==('c') && textureCOFFEEA[tcs+1]==('o') && textureCOFFEEA[tcs+2]==('f') && textureCOFFEEA[tcs+3]==('f') && textureCOFFEEA[tcs+4]==('e') && textureCOFFEEA[tcs+5]==('e'))
        {
            mugTCO<<""<<textureCOFFEEA[tcs+6]<<""<<textureCOFFEEA[tcs+7];
        }
    }
    mugTC=mugTCO.str();
    int switchT=1;
    if(mugTC==("01") || mugTC==("03") || mugTC==("04") || mugTC==("05"))
    {
        effect->shader()->gocMaterial()->setEmission(vl::orange);
        switchT=2;
    }
    if(mugTC==("02"))
    {
        effect->shader()->gocMaterial()->setEmission(vl::royalblue);
        switchT=2;
    }
    if(levelA==1 && switchT==1)
    {
        effect->shader()->gocMaterial()->setEmission(vl::lightgreen);
    }
    if(levelA==2 && switchT==1)
    {
        effect->shader()->gocMaterial()->setEmission(vl::gray);
    }
    if(levelA==4 && switchT==1)
    {
        effect->shader()->gocMaterial()->setEmission(vl::pink);
    }
    if(levelA==5 && switchT==1)
    {
        effect->shader()->gocMaterial()->setEmission(vl::gray);
    }
}

//reset variables/reset match
void matchReset()
{
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor(vl::black);
    shatteredA=1, shatteredC=1;
    tickAct=1, tickB=1;
    resultM=1;
    countA=0;
    damage1=0, damage2=0;
    health1=0, health2=0;
    pushM=1;
    pushMC=1;
    menuA=1;
    roundN=1;
    accordM=1;
    ringA=1;
    winsM=0, loseM=0;
    matchA=1;
    mug1X=-1.7, mug1Y=0.0, mug1Z=1.6;
    mug2X=2.1, mug2Y=0.0, mug2Z=-1.9;
    mug2Speed=difficultMA;
    sumoA=1;
    ringI=1;
    displayM=1;
    timerEnd=0;
    xC=-2.8, yC=0.6, zC=4.2;
    clockC=0;
    funkC=1;
}

void roundReset()
{
    if(matchA==2)
    {
    if(tutorialA==2)
    {
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor(vl::black);
    shatteredA=1, shatteredC=1;
    tickAct=1, tickB=1;
    resultM=1;
    countA=0;
    damage1=0, damage2=0;
    health1=0, health2=0;
    pushM=1;
    pushMC=1;
    accordM=1;
    menuA=1;
    matchA=1;
    mug1X=-1.7, mug1Y=0.0, mug1Z=1.6;
    mug2X=2.1, mug2Y=0.0, mug2Z=-1.9;
    mug2Speed=difficultMA;
    sumoA=1;
    ringI=1;
    xC=-2.8, yC=0.6, zC=4.2;
    clockC=0;
    funkC=1;
    }
    if(tutorialA==1)
    {
        startA=2;
        tutTimer=0;
        uniqueP=2;
        pickA=3;
        levelA=1;
        menuA=1;
        tutorialA=2;
    }
    }
}

//countdown/start of match
void countdownARENA()
{
    //buffer
    if(pushM==2)
    {
    pushMC+=1;
    if(pushMC>=5)
    {
        pushM=1;
        pushMC=1;
    }
    }

    //match display
    if(tutorialA==2 && displayM==1 && matchA==1)
    {
        if(countA>=130 && countA<=160)
        {
            std::string displayS;
            std::ostringstream displayO;
            displayO<<"Match "<<levelA<<"";
            displayS=displayO.str();

            if(levelA<=4)
            {
            dialogTAXI(100, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", displayS, "Black", "Bottom", "Left");
            }
            if(levelA==5)
            {
            dialogTAXI(40, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "Qualify Match", "Black", "Bottom", "Left");
            }
            if(levelA==6)
            {
            dialogTAXI(40, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "Championship", "Black", "Bottom", "Left");
            }
            applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        }
        if(countA>=161)
        {
            displayM=2;
        }
    }

    //countdown
    if(countA>=0 && countA<=102)
    {

    if(tutorialA==1)
    {
    dialogTAXI(30, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "TUTORIAL", "Red", "Top", "Left");
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    }
    if(tutorialA==2)
    {
    std::ostringstream roundNO;
    roundNO<<" Round "<<roundN<<"/9";
    std::string roundNS=roundNO.str();
    dialogTAXI(30, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", roundNS, "Red", "Top", "Left");
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    }
    }
    if(countA<=30)
    {
    dialogTAXI(130, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "3", "Black", "Top", "Center");
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    }
    if(countA>=31 && countA<=61)
    {
    dialogTAXI(130, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "2", "Black", "Top", "Center");
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    }
    if(countA>=62 && countA<=102)
    {
    dialogTAXI(130, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "1", "Black", "Top", "Center");
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    }
    if(countA>=103 && countA<=129 && matchA==1)
    {
    dialogTAXI(120, "../Resource/justF/MmmmCoffee-B0lV.ttf", "FIGHT!", "Blue", "Top", "Center");
    text->setOutlineEnabled(true); //additional
    text->setOutlineColor(vl::red); //additional
    text->setShadowEnabled(true); //additional
    text->setShadowColor(vl::yellow); //additional
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    if(ringI==1 && ringA==1)
    {
        ringM.stop();
        ringM.openFromFile("../Resource/fileA/ring/Blastwave_FX_BoxingBellRing_S08SP.136.ogg");
        if(volumeM==1)
        {
        ringM.play();
        }
        ringA=2;
        ringI=2;
    }
    sumoA=2;
    }
    countA+=1;
}

//load arena and environment
void loadArena()
{

   modelTAXI("../Resource/uniA/world.md2", "../Resource/uniA/cubemap.jpg", "Nothing", false, 0.0, -19.2, 0.0);
   applet->sceneManager()->tree()->addActor(morph_act2.get());

   modelTAXI("../Resource/uniA/plane.md2", "../Resource/uniA/plane.jpg", "Nothing", false, 0.0, -0.2, 0.0);
   applet->sceneManager()->tree()->addActor(morph_act2.get());

   modelTAXI("../Resource/dataA/tree.md2", "../Resource/dataA/tree.jpg", "Nothing", false, 0.0, 0.0, 0.0);
   applet->sceneManager()->tree()->addActor(morph_act2.get());

   modelTAXI("../Resource/dataA/tree.md2", "../Resource/dataA/tree.jpg", "Nothing", false, 5.0, 0.0, -11.0);
   applet->sceneManager()->tree()->addActor(morph_act2.get());

   modelTAXI("../Resource/dataA/stage.md2", "../Resource/dataA/stage.jpg", "Nothing", true, 0.0, 0.0, 0.0);
   effect->shader()->gocMaterial()->setEmission(vl::white);
   effect->shader()->gocMaterial()->setSpecular(vl::white);
   effect->shader()->gocMaterial()->setShininess(45);
   morph_act2->setEffect(effect.get());
   applet->sceneManager()->tree()->addActor(morph_act2.get());

   modelTAXI("../Resource/dataA/sides.md2", "../Resource/dataA/sides.jpg", "Nothing", true, 0.0, 0.0, 0.0);
   applet->sceneManager()->tree()->addActor(morph_act2.get());

   modelTAXI("../Resource/dataA/score1.md2", "../Resource/dataA/score.jpg", "Nothing", false, 0.0, 4.7, 0.0);
   applet->sceneManager()->tree()->addActor(morph_act2.get());

   modelTAXI("../Resource/dataA/score2.md2", "../Resource/dataA/score.jpg", "Nothing", false, 13.36, 4.7, 0.425);
   applet->sceneManager()->tree()->addActor(morph_act2.get());
}

//loading mugs, factoring collision, and bumping
void loadMugs()
{
    double mug2Y=0.4;
    clockP+=1;
    if(clockP>=difficultMB)
    {
    clockP=0;
    }
    modelTAXI("../Resource/justA/mug2.md2", textureCOFFEEA, "Complex", true, mug2X, 0.4, mug2Z);
    if(health2<=4)
    {
    animationTAXI(health2, health2, 1.0);
    }
    if(health2>=5)
    {
    animationTAXI(5, 5, 1.0);
    }
    assignShaderMug2();
    effect->shader()->gocMaterial()->setSpecular(vl::white);
    effect->shader()->gocMaterial()->setShininess(8);
    morph_act2->setEffect(effect.get());
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    moveTAXI(mug2X, mug2Y, mug2Z);

    double xB1=coordX1, xB2=coordX2, zB1=coordZ1, zB2=coordZ2;

    modelTAXI("../Resource/justA/mug1.md2", textureTEAA, "Complex", true, mug1X, 0.4, mug1Z);
    if(health1<=4)
    {
    animationTAXI(health1, health1, 1.0);
    }
    if(health1>=5)
    {
    animationTAXI(5, 5, 1.0);
    }
    assignShaderMug1();
    effect->shader()->gocMaterial()->setSpecular(vl::white);
    effect->shader()->gocMaterial()->setShininess(8);
    morph_act2->setEffect(effect.get());
    applet->sceneManager()->tree()->addActor(morph_act2.get());

    if(sumoA==2)
    {
    double rememberX=mug1X;
    double rememberZ=mug1Z;
    double totalC;
    xM=mug1X, zM=mug1Z;
    collideTAXI(xB1, xB2, zB1, zB2, 0.4);
    mug1X=xM, mug1Z=zM;
    if(rememberX<mug1X)
    {
    totalC=mug1X-rememberX;
    totalC=totalC/2;
    mug2X=mug2X-totalC;
    mug1X=rememberX+totalC;
    pushM=2;
    }
    if(rememberX>mug1X)
    {
    totalC=rememberX-mug1X;
    totalC=totalC/2;
    mug2X=mug2X+totalC;
    mug1X=rememberX-totalC;
    pushM=2;
    }
    if(rememberZ<mug1Z)
    {
    totalC=mug1Z-rememberZ;
    totalC=totalC/2;
    mug2Z=mug2Z-totalC;
    mug1Z=rememberZ+totalC;
    pushM=2;
    }
    if(rememberZ>mug1Z)
    {
    totalC=rememberZ-mug1Z;
    totalC=totalC/2;
    mug2Z=mug2Z+totalC;
    mug1Z=rememberZ-totalC;
    pushM=2;
    }

    if(pushM==2 && clockP==difficultMB-2 && mugMA==1)
    {
    damage1+=damageHit;
    }
    if(pushM==2 && clockP==difficultMB-2 && mugMA==2)
    {
    damage2+=damageHit;
    }
    }
}

//load healthbars
void loadHealth()
{

    modelTAXI("../Resource/uniA/health.md2", "../Resource/uniA/health.jpg", "Nothing", false, mug1X, 1.78, mug1Z);
    if(health1<=5)
    {
    animationTAXI(health1, health1, 1.0);
    }
    if(health1==6)
    {
    animationTAXI(9, 9, 1.0);
    sumoA=2;
    if(health2==0)
    {
    shatteredA=2;
    mugShatter();
    }
    if(health2>=1)
    {
    outcomeA();
    }
    }
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    if(health1==4 || health1==5)
    {
    modelTAXI("../Resource/uniA/exclamation.md2", "../Resource/uniA/exclamation.jpg", "Nothing", false, mug1X+0.07, 2.38, mug1Z);
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    }

    modelTAXI("../Resource/uniA/health.md2", "../Resource/uniA/health.jpg", "Nothing", false, mug2X, 1.78, mug2Z);
    if(health2<=5)
    {
    animationTAXI(health2, health2, 1.0);
    }
    if(health2==6)
    {
    animationTAXI(9, 9, 1.0);
    sumoA=2;
    if(health1==0)
    {
    shatteredA=2;
    mugShatter();
    }
    if(health1>=1)
    {
    outcomeB();
    }
    }
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    if(health2==4 || health2==5)
    {
    modelTAXI("../Resource/uniA/exclamation.md2", "../Resource/uniA/exclamation.jpg", "Nothing", false, mug2X+0.07, 2.38, mug2Z);
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    }
}

//square hitbox
void loadOut()
{
    if(mug2Z<=-2.6 || mug2Z>=2.2 ||  mug2X<=-2.2 || mug2X>=3.0)
    {
        outcomeB();
    }
    if(mug1Z<=-2.6 || mug1Z>=2.2 || mug1X<=-2.0 || mug1X>=3.0)
    {
        outcomeA();
    }
}

//enemy mug's movement
void mugMove()
{
    if(sumoA==2 && mugMA==1)
    {
        if(mug2X>mug1X)
        {
            mug2X-=mug2Speed;
        }
        if(mug2Z>mug1Z)
        {
            mug2Z-=mug2Speed;
        }
        if(mug1X>mug2X)
        {
            mug2X+=mug2Speed;
        }
        if(mug1Z>mug2Z)
        {
            mug2Z+=mug2Speed;
        }
    }
    if(sumoA==2 && mugMA==2)
    {
        if(mug1X>mug2X)
        {
            mug1X-=mug2Speed;
        }
        if(mug1Z>mug2Z)
        {
            mug1Z-=mug2Speed;
        }
        if(mug2X>mug1X)
        {
            mug1X+=mug2Speed;
        }
        if(mug2Z>mug1Z)
        {
            mug1Z+=mug2Speed;
        }
    }
}

//health functions
void loadHit()
{
    if(damage1==0)
    {
        health1=0;
    }
    if(damage1==1 || damage1==2)
    {
        health1=1;
    }
    if(damage1==3 || damage1==4)
    {
        health1=2;
    }
    if(damage1==5)
    {
        health1=3;
    }
    if(damage1==6 || damage1==7)
    {
        health1=4;
    }
    if(damage1==8 || damage1==9)
    {
        health1=5;
    }
    if(damage1>=10)
    {
        health1=6;
    }

    if(damage2==0)
    {
        health2=0;
    }
    if(damage2==1 || damage2==2)
    {
        health2=1;
    }
    if(damage2==3 || damage2==4)
    {
        health2=2;
    }
    if(damage2==5)
    {
        health2=3;
    }
    if(damage2==6 || damage2==7)
    {
        health2=4;
    }
    if(damage2==8 || damage2==9)
    {
        health2=5;
    }
    if(damage2>=10)
    {
        health2=6;
    }

    //tutorial text
        if(tutorialA==1 && countA>=130)
        {
        if(tutTimer<=50 && handA==1)
        {
        dialogTAXI(30, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "Press The Arrow Keys To Move", "Black", "Top", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        }
        if(tutTimer<=50 && handA==2)
        {
        dialogTAXI(30, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "Press The 'WASD' Keys To Move", "Black", "Top", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        }
        if(tutTimer>=51 && tutTimer<=69)
        {
        dialogTAXI(30, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "To Attack You Have Your", "Black", "Top", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        }
        if(tutTimer>=70 && tutTimer<=85)
        {
        dialogTAXI(30, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "Button Combinations Of:", "Black", "Top", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        }
        if(tutTimer>=86 && tutTimer<=155)
        {
        dialogTAXI(25, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "'J+SPACE', 'G+K+SPACE', And 'X+J+RIGHT CLICK'", "Black", "Top", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        }
        if(tutTimer>=156 && tutTimer<=190)
        {
        dialogTAXI(30, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "To Win, PUSH Your Opponent OUTSIDE", "Black", "Top", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        }
        if(tutTimer>=191 && tutTimer<=235)
        {
        dialogTAXI(20, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "Of The Square Or DEFEAT Them Via ATTACKING", "Black", "Top", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        }
        if(tutTimer>=250 && tutTimer<=295)
        {
        dialogTAXI(30, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "Well, Good Luck!", "Black", "Top", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        }
        tutTimer+=1;
        }
}

//lose
void outcomeA()
{
    matchA=2;
    sumoA=1;
    resultM=2;
    funkC=1;
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor( vl::midnightblue );

    if(accordM==1)
    {
    if(teamM==1)
    {
        loseR+=1;
        wonR=0;
    }
    if(teamM==2)
    {
        wonR+=1;
        loseR=0;
    }
    accordM=2;
    }

    modelTAXI("../Resource/justA/mug1.md2", textureTEAA, "Nothing", true, -4.2, 0.57+mug1Y, -2.0);
    if(health1<=4)
    {
    animationTAXI(health1, health1, 1.0);
    }
    if(health1>=5)
    {
    animationTAXI(5, 5, 1.0);
    }
    assignShaderMug1();
    effect->shader()->gocMaterial()->setSpecular(vl::white);
    effect->shader()->gocMaterial()->setShininess(8);
    morph_act2->setEffect(effect.get());
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    if(mug1Y<=18.5 && tickAct==1)
    {
        std::ostringstream record2MO;
        record2MO<<""<<playerNameB<<"("<<loseM+1<<"-"<<winsM<<") WINS! "<<playerNameA<<"("<<winsM<<"-"<<loseM+1<<") Loses";
        std::string record2MS=record2MO.str();
        dialogTAXI(25, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", record2MS, "Red", "Bottom", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
        mug1Y+=0.25;
    }
    if(mug1Y>=18.5)
    {
        tickAct=2;
    }
    if(tickAct==2)
    {
    if(tickB<=129 || tickB>=131)
    {
    tickB+=1;
    }
    if(tickB>=30)
    {
        mug1Y-=0.5;
    }
    if(tickB>=120)
    {
    if(tickB>=130)
    {
    tickB=130;
    }
    if(winsM==5)
    {
    std::ostringstream simpleNAO;
    simpleNAO<<""<<playerNameA<<" WINS THE MATCH!";
    std::string simpleNAS=simpleNAO.str();
    dialogTAXI(50, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", simpleNAS, "Red", "Top", "Center");
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    if(timerEnd>=60)
    {
        if(teamM==1)
        {
        levelA+=1;
        }
        startA=2;
        uniqueP=2;
        pickA=3;
        menuA=1;
    }
    timerEnd+=1;
    }
    if(loseM+1==5)
    {
    std::ostringstream simpleNAO;
    simpleNAO<<""<<playerNameB<<" WINS THE MATCH!";
    std::string simpleNAS=simpleNAO.str();
    dialogTAXI(50, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", simpleNAS, "Red", "Top", "Center");
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    if(timerEnd>=60)
    {
        if(teamM==2)
        {
        levelA+=1;
        }
        startA=2;
        uniqueP=2;
        pickA=3;
        menuA=1;
    }
    timerEnd+=1;
    }
    if(winsM<=4 && loseM+1<=4)
    {
    roundN+=1;
    loseM+=1;
    roundReset();
    }
    }
    }

    if(tickAct==2)
    {
        std::ostringstream record2O;
        record2O<<""<<playerNameB<<"("<<loseM+1<<"-"<<winsM<<") WINS!";
        std::string record2S=record2O.str();
        dialogTAXI(50, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf",record2S, "Red", "Bottom", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    }

    modelTAXI("../Resource/justA/mug2.md2", textureCOFFEEA, "Nothing", true, -2.76, 0.32+mug2Y, 0.0);
    assignShaderMug2();
    effect->shader()->gocMaterial()->setSpecular(vl::white);
    effect->shader()->gocMaterial()->setShininess(8);
    morph_act2->setEffect(effect.get());
    animationTAXI(0, 0, 1.0);
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    if(mug2Y<=18.5)
    {
        mug2Y+=0.5;
    }
    modelTAXI("../Resource/uniA/smoke.md2", "../Resource/uniA/smoke.jpg", "Nothing", false, -2.76, 1.2+mug2Y, 0.0);
    animationTAXI(0, 12, 2.0);
    applet->sceneManager()->tree()->addActor(morph_act2.get());
}

void outcomeB()
{
    matchA=2;
    sumoA=1;
    resultM=3;
    funkC=1;
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor( vl::midnightblue );
    if(accordM==1)
    {
    if(teamM==1)
    {
        wonR+=1;
        loseR=0;
    }
    if(teamM==2)
    {
        loseR+=1;
        wonR=0;
    }
    accordM=2;
    }
    modelTAXI("../Resource/justA/mug2.md2", textureCOFFEEA, "Nothing", true, -1.2, 0.67+mug2Y, -2.0);
    if(health2<=4)
    {
    animationTAXI(health2, health2, 1.0);
    }
    if(health2>=5)
    {
    animationTAXI(5, 5, 1.0);
    }
    assignShaderMug2();
    effect->shader()->gocMaterial()->setSpecular(vl::white);
    effect->shader()->gocMaterial()->setShininess(8);
    morph_act2->setEffect(effect.get());
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    if(mug2Y<=18.5 && tickAct==1)
    {
        std::ostringstream record1MO;
        record1MO<<""<<playerNameA<<"("<<winsM+1<<"-"<<loseM<<") WINS! "<<playerNameB<<"("<<loseM<<"-"<<winsM+1<<") LOSES!";
        std::string record1MS=record1MO.str();
        mug2Y+=0.25;
        dialogTAXI(25, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", record1MS, "Red", "Bottom", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    }
    if(mug2Y>=18.5)
    {
        tickAct=2;
    }
    if(tickAct==2)
    {
    if(tickB<=129 || tickB>=131)
    {
    tickB+=1;
    }
    if(tickB>=30)
    {
        mug2Y-=0.5;
    }
    if(tickB>=120)
    {
    if(tickB>=130)
    {
    tickB=130;
    }
    if(winsM+1==5)
    {
    std::ostringstream simpleNAO;
    simpleNAO<<""<<playerNameA<<" WINS THE MATCH!";
    std::string simpleNAS=simpleNAO.str();
    dialogTAXI(50, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", simpleNAS, "Red", "Top", "Center");
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    if(timerEnd>=60)
    {
        if(teamM==1)
        {
        levelA+=1;
        }
        startA=2;
        uniqueP=2;
        pickA=3;
        menuA=1;
    }
    timerEnd+=1;
    }
    if(loseM==5)
    {
    std::ostringstream simpleNAO;
    simpleNAO<<""<<playerNameB<<" WINS THE MATCH!";
    std::string simpleNAS=simpleNAO.str();
    dialogTAXI(50, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", simpleNAS, "Red", "Top", "Center");
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    if(timerEnd>=60)
    {
        if(teamM==2)
        {
        levelA+=1;
        }
        startA=2;
        uniqueP=2;
        pickA=3;
        menuA=1;
    }
    timerEnd+=1;
    }
    if(winsM+1<=4 && loseM<=4)
    {
    roundN+=1;
    winsM+=1;
    roundReset();
    }
    }
    }

    if(tickAct==2)
    {
        std::ostringstream record1O;
        record1O<<""<<playerNameA<<"("<<winsM+1<<"-"<<loseM<<") WINS!";
        std::string record1S=record1O.str();
        dialogTAXI(50, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", record1S, "Red", "Bottom", "Center");
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    }

    modelTAXI("../Resource/justA/mug1.md2", textureTEAA, "Nothing", true, -2.8, 0.4+mug1Y, 0.0);
    animationTAXI(0, 0, 1.0);
    assignShaderMug1();
    effect->shader()->gocMaterial()->setSpecular(vl::white);
    effect->shader()->gocMaterial()->setShininess(8);
    morph_act2->setEffect(effect.get());
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    if(mug1Y<=18.5)
    {
        mug1Y+=0.5;
    }

    modelTAXI("../Resource/uniA/smoke.md2", "../Resource/uniA/smoke.jpg", "Nothing", false, -2.8, 1.2+mug1Y, 0.0);
    animationTAXI(0, 12, 2.0);
    applet->sceneManager()->tree()->addActor(morph_act2.get());
}

//shattered
void mugShatter()
{
    if(health1==0)
    {

        if(shatteredC==1)
        {
            advanceM+=1;
        }

        dialogTAXI(70, "../Resource/justF/MmmmCoffee-B0lV.ttf", "SHATTERED!", "Blue", "Top", "Center");
        text->setOutlineEnabled(true); //additional
        text->setOutlineColor(vl::black); //additional
        text->setShadowEnabled(true); //additional
        text->setShadowColor(vl::black); //additional
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());

        modelTAXI("../Resource/justA/mug1.md2", textureTEAA, "Nothing", true, mug1X, 0.4, mug1Z);
        animationTAXI(0, 0, 1.0);
        assignShaderMug1();
        effect->shader()->gocMaterial()->setSpecular(vl::white);
        effect->shader()->gocMaterial()->setShininess(8);
        morph_act2->setEffect(effect.get());
        applet->sceneManager()->tree()->addActor(morph_act2.get());

        modelTAXI("../Resource/justA/mug2.md2", textureCOFFEEA, "Nothing", true, mug2X, 0.4, mug2Z);
        if(shatteredC<=44)
        {
        animationTAXI(6, 10, 1.0);
        }
        if(shatteredC>=45)
        {
            animationTAXI(10, 10, 1.0);
        }
        assignShaderMug2();
        effect->shader()->gocMaterial()->setSpecular(vl::white);
        effect->shader()->gocMaterial()->setShininess(8);
        morph_act2->setEffect(effect.get());
        applet->sceneManager()->tree()->addActor(morph_act2.get());
        if(shatteredC>=190)
        {
            shatteredA=1;
            outcomeB();
        }
        shatteredC+=1;
    }
    if(health2==0)
    {

        dialogTAXI(70, "../Resource/justF/MmmmCoffee-B0lV.ttf", "SHATTERED!", "Blue", "Top", "Center");
        text->setOutlineEnabled(true); //additional
        text->setOutlineColor(vl::black); //additional
        text->setShadowEnabled(true); //additional
        text->setShadowColor(vl::black); //additional
        applet->sceneManager()->tree()->addActor(text.get(), effectT.get());

        modelTAXI("../Data/mugs/mug1.md2", textureTEAA, "Nothing", true, mug1X, 0.4, mug1Z);
        if(shatteredC<=44)
        {
        animationTAXI(6, 12, 1.0);
        }
        if(shatteredC>=45)
        {
            animationTAXI(12, 12, 1.0);
        }
        assignShaderMug1();
        effect->shader()->gocMaterial()->setSpecular(vl::white);
        effect->shader()->gocMaterial()->setShininess(8);
        morph_act2->setEffect(effect.get());
        applet->sceneManager()->tree()->addActor(morph_act2.get());
        if(shatteredC>=190)
        {
            shatteredA=1;
            outcomeA();
        }

        modelTAXI("../Resource/justA/mug2.md2", textureCOFFEEA, "Nothing", true, mug2X, 0.4, mug2Z);
        animationTAXI(0, 0, 1.0);
        assignShaderMug2();
        effect->shader()->gocMaterial()->setSpecular(vl::white);
        effect->shader()->gocMaterial()->setShininess(8);
        morph_act2->setEffect(effect.get());
        applet->sceneManager()->tree()->addActor(morph_act2.get());

        shatteredC+=1;
    }
}
