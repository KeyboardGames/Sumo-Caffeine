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
#include "cameraSUMO.h"
#include "inputHUB.h"
#include "intro.h"
#include "gui.h"
int pickA=2;
int pickV=1;
int viewG=1;
int menuX=1;
int timerChoose=0;

void startGame();
void loadTeam();

void startGame()
{
    if(pickA==2 && teamM==0)
    {

    imageTAXI("../Resource/youA/choose/pick.png", "free", xC, 0.0, zC-9);
    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getTranslation(xC,-morph_act2->lod(0)->boundingBox().minCorner().y(),zC-9));
    morph_act2->transform()->computeWorldMatrix(NULL);

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getScaling(8.0, 8.0, 1.0));
    morph_act2->transform()->computeWorldMatrix(NULL);
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    xC=-0.14;
    yC=-0.87;
    zC=22.5;
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor(vl::black);

    dialogTAXI(40, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "Choose Your Team", "Blue", "Bottom", "Center");
    text->setOutlineEnabled(true); //additional
    text->setOutlineColor(vl::red); //additional
    text->setShadowEnabled(true); //additional
    text->setShadowColor(vl::white); //additional
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
    }

    if(teamM>=1 && timerChoose<=1)
    {
       startA=2;
       uniqueP=2;
       pickA=3;
       menuA=1;
    }
    if(teamM>=1 && timerChoose<=5)
    {
        timerChoose+=1;
    }
}

void loadTeam()
{
    int runO=1;
    std::ifstream teamL;
    std::string teamR;
    teamL.open("../Resource/remindA/Team.pld");
    while(getline(teamL, teamR))
    {
    int teamN;
    std::ostringstream teamLO;
    teamLO<<teamR;
    std::string teamLS=teamLO.str();
    std::istringstream (teamLS)>> teamN;
    if(runO==1)
    {
    if(teamLS[0]==('1'))
    {
        teamM=1;
    }
    if(teamLS[0]==('2'))
    {
        teamM=2;
    }
    }
    if(runO==2)
    {
        wonR=teamN;
    }
    if(runO==3)
    {
        loseR=teamN;
    }
    if(runO==4)
    {
        advanceM=teamN;
    }
    if(runO==5)
    {
        championA=teamN;
    }
    if(runO==6)
    {
        tutorialA=teamN;
    }
    if(runO==7)
    {
        totalR=teamN;
    }
    if(runO==8)
    {
        mugTI=teamN;
    }
    if(runO==9)
    {
        levelA=teamN;
    }
    if(runO==10)
    {
        handA=teamN;
    }
    if(runO==11)
    {
        volumeA=teamN;
    }
    runO+=1;
    }
}
