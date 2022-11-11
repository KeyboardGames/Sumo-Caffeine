#ifndef _App_Taxi_INCLUDE
#define _App_Taxi_INCLUDE

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
#include "Taxi/Audio.h"
#include "App_Taxi.hpp"
#include "sumoHUB.h"
#include "arena.h"
#include "cameraSUMO.h"
#include "inputHUB.h"
#include "intro.h"
#include "gui.h"

extern sf::Music musicA, musicB, musicC;
extern int audioT, audioC;
extern int teamM;
extern int tutorialA;
extern int totalR, wonR, loseR;
extern int advanceM;
extern int championA;
extern int levelA;
extern int handA;
extern int volumeM;

using namespace vl;

class App_Taxi: public Applet
{
public:
  virtual void initEvent()
  {
    applet->trackball()->setZoomButton(NULL);
    applet->trackball()->setTranslationButton(NULL);
    applet->trackball()->setRotationButton(NULL);
    applet->trackball()->adjustView(applet->rendering()->as<Rendering>(), vec3(0,0,1), vec3(0,1,0), 1.0f);

    clickM.openFromFile("../Resource/fileA/click/click.flac");

    cameraTAXI();
  }

  void updateEvent()
  {

    vl::Applet::updateEvent();
    ShowCursor(true);
    sceneManager()->tree()->actors()->clear();
    renderOrder=1;

    if(wonR>=20 && totalR<=3)
    {
        int totalRV=totalR;
        totalR=2;
        if(totalRV==3)
        {
            totalR=4;
        }
    }
    if(loseR>=50 && totalR<=3)
    {
        int totalRV=totalR;
        totalR=3;
        if(totalRV==2)
        {
            totalR=4;
        }
    }

    if(levelA>=8)
    {
        championA=2;
        levelA=1;
    }

    //load intro
    startGame();
    //load menu
    guiMenu();
    //load start screen
    guiStart();
    //load sumo battle
    std::string mugTIS;
    std::ostringstream mugTIO;
    //tutorial
    if(tutorialA==1)
    {
    if(teamM==1)
    {
    mugTIO<<"../Resource/justA/mugs/tea0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(1, "TEA", "COFFEE", mugTIS, "../Resource/justA/mugs/coffee01.jpg", 0.0, 1, 0);
    }
    if(teamM==2)
    {
    mugTIO<<"../Resource/justA/mugs/coffee0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(2, "TEA", "COFFEE", "../Resource/justA/mugs/tea01.jpg", mugTIS, 0.0, 1, 0);
    }
    }

    if(tutorialA==2)
    {
    if(levelA==1)
    {
    if(teamM==1)
    {
    mugTIO<<"../Resource/justA/mugs/tea0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(1, "TEA", "MOCA", mugTIS, "../Resource/justA/mugs/moca.jpg", 0.06, 30, 4);
    }
    if(teamM==2)
    {
    mugTIO<<"../Resource/justA/mugs/coffee0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(2, "GREEN TEA", "COFFEE", "../Resource/justA/mugs/greentea.jpg", mugTIS, 0.06, 30, 4);
    }
    }
    if(levelA==2)
    {
    if(teamM==1)
    {
    mugTIO<<"../Resource/justA/mugs/tea0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(1, "TEA", "LATE", mugTIS, "../Resource/justA/mugs/late.jpg", 0.09, 10, 4);
    }
    if(teamM==2)
    {
    mugTIO<<"../Resource/justA/mugs/coffee0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(2, "ICE TEA", "COFFEE", "../Resource/justA/mugs/icetea.jpg", mugTIS, 0.09, 10, 4);
    }
    }
    if(levelA==3)
    {
    if(teamM==1)
    {
    mugTIO<<"../Resource/justA/mugs/tea0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(1, "TEA", "COFFEE", mugTIS, "../Resource/justA/mugs/coffee01.jpg", 0.11, 7, 2);
    }
    if(teamM==2)
    {
    mugTIO<<"../Resource/justA/mugs/coffee0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(2, "TEA", "COFFEE", "../Resource/justA/mugs/tea01.jpg", mugTIS, 0.11, 7, 2);
    }
    }
    if(levelA==4)
    {
    if(teamM==1)
    {
    mugTIO<<"../Resource/justA/mugs/tea0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(1, "TEA", "CARAMEL", mugTIS, "../Resource/justA/mugs/caramel.jpg", 0.15, 20, 2);
    }
    if(teamM==2)
    {
    mugTIO<<"../Resource/justA/mugs/coffee0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(2, "HOT TEA", "COFFEE", "../Resource/justA/mugs/hottea.jpg", mugTIS, 0.15, 20, 2);
    }
    }
    if(levelA==5)
    {
    if(teamM==1)
    {
    mugTIO<<"../Resource/justA/mugs/tea0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(1, "TEA", "LATE", mugTIS, "../Resource/justA/mugs/late.jpg", 0.14, 8, 2);
    }
    if(teamM==2)
    {
    mugTIO<<"../Resource/justA/mugs/coffee0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(2, "HOT TEA", "COFFEE", "../Resource/justA/mugs/hottea.jpg", mugTIS, 0.14, 8, 2);
    }
    }
    if(levelA==6)
    {
    if(teamM==1)
    {
    mugTIO<<"../Resource/justA/mugs/tea0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(1, "TEA", "COFFEE", mugTIS, "../Resource/justA/mugs/coffee02.jpg", 0.165, 6, 2);
    }
    if(teamM==2)
    {
    mugTIO<<"../Resource/justA/mugs/coffee0"<<mugTI<<".jpg";
    mugTIS=mugTIO.str();
    sumoBegin(2, "TEA", "COFFEE", "../Resource/justA/mugs/tea02.jpg", mugTIS, 0.165, 6, 2);
    }
    }
    }
    initEvent();
  }

    //keyboard input (edit in "Taxi/Input.cpp"; fully Visualization Library compatible)
  void keyPressEvent(unsigned short chA, vl::EKey keyA)
  {

    key=keyA;
    ch=chA;
    Applet::keyPressEvent(ch,key);
    inputHUBI();
    if(resultM==1 && pickA>=4)
    {
    //menu
    actMenu();
    moveMenu();
    keyMenu();
    }
    if(uniqueP==2)
    {
    //start screen
    moveStart();
    keyStart();
    }
   }

   void mouseDownEvent(EMouseButton btnA, int xA, int yA)
   {
       btn=btnA;
       int x=xA;
       int y=yA;
       Applet::mouseDownEvent(btn, x, y);
       inputHUBM();
   }
};

#endif
