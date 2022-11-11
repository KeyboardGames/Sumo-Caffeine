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
sf::Music clickM;
int uniqueP=1;
int mugTI=1;
int menuA=1, menuF=1;
int startA=1, startF=1;
int timerStart=1, timerStartA=0;
int timerOkay=1, timerOkayA=0;
double xCV, yCV, zCV;

//menu
void guiMenu();
void actMenu();
void moveMenu();
void keyMenu();

//start screen
void guiStart();
void moveStart();
void keyStart();

void unlockMug()
{
    dialogTAXI(40, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "UNLOCKED MUG", "Blue", "Top", "Left");
    text->setOutlineEnabled(true); //additional
    text->setOutlineColor(vl::red); //additional
    text->setShadowEnabled(true); //additional
    text->setShadowColor(vl::white); //additional
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
}

void lockMug()
{
    dialogTAXI(40, "../Resource/justF/HighSchoolUsaSerif-6vwM.ttf", "LOCKED MUG", "Blue", "Top", "Left");
    text->setOutlineEnabled(true); //additional
    text->setOutlineColor(vl::red); //additional
    text->setShadowEnabled(true); //additional
    text->setShadowColor(vl::white); //additional
    applet->sceneManager()->tree()->addActor(text.get(), effectT.get());
}

//menu
void guiMenu()
{
    //reset
    if(menuA==3)
    {
        menuA=1;
    }
    //activate menu
    if(menuA==2)
    {

    std::string menuFS;
    std::ostringstream menuFO;
    menuFO<<"../Resource/undoA/Menu/menu"<<menuF<<".jpg";
    menuFS=menuFO.str();
    imageTAXI(menuFS, "free", xC, yC, zC-9.0);
    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getTranslation(xC,-morph_act2->lod(0)->boundingBox().minCorner().y(),zC-9));
    morph_act2->transform()->computeWorldMatrix(NULL);

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getScaling(10.0,10.0, 1.0));
    morph_act2->transform()->computeWorldMatrix(NULL);
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor(vl::black);
    }

    if(menuF==4)
    {
        unlockMug();
    }
    if(menuF==5)
    {
        if(championA==1)
        {
            lockMug();
        }
        if(championA==2)
        {
            unlockMug();
        }
    }
    if(menuF==6)
    {
        if(totalR==1 || totalR==3)
        {
            lockMug();
        }
        if(totalR==2 || totalR==4)
        {
            unlockMug();
        }
    }
    if(menuF==7)
    {
        if(totalR==1 || totalR==2)
        {
            lockMug();
        }
        if(totalR==3 || totalR==4)
        {
            unlockMug();
        }
    }
    if(menuF==8)
    {
        if(advanceM<=9999)
        {
            lockMug();
        }
        if(advanceM>=10000)
        {
            unlockMug();
        }
    }

    if(timerOkay==2)
    {
        if(timerOkayA>=5)
        {
            timerOkayA=0;
            timerOkay=1;
        }
        timerOkayA+=1;
    }
}

void actMenu()
{
    if(key==vl::Key_Escape)
    {
        if(menuA==2)
        {
            xC=xCV;
            yC=yCV;
            zC=zCV;
            menuA=3;
        }
        if(menuA==1)
        {
            xCV=xC;
            yCV=yC;
            zCV=zC;
            xC=-0.14;
            yC=-0.87;
            zC=22.5;
            menuA=2;
        }
    }
}

void moveMenu()
{
   if(menuA==2)
   {
       //basic menu
       if(menuF<=3)
       {
        if(handA==1)
        {
       if(key==Key_Down)
       {
           if(menuF<=2)
           {
           menuF+=1;
           }
       }
       if(key==Key_Up)
       {
           if(menuF>=2)
           {
           menuF-=1;
           }
       }
        }
        if(handA==2)
        {
            if(key==Key_S)
       {
           if(menuF<=2)
           {
           menuF+=1;
           }
       }
       if(key==Key_W)
       {
           if(menuF>=2)
           {
           menuF-=1;
           }
       }
        }
       }
       //mug menu
       if(menuF>=4)
       {
        if(handA==1)
        {
       if(key==Key_Down)
       {
           if(menuF<=8)
           {
           menuF+=1;
           }
       }
       if(key==Key_Up)
       {
           if(menuF>=5)
           {
           menuF-=1;
           }
       }
       }
       if(handA==2)
        {
       if(key==Key_S)
       {
           if(menuF<=8)
           {
           menuF+=1;
           }
       }
       if(key==Key_W)
       {
           if(menuF>=5)
           {
           menuF-=1;
           }
       }
       }
       }
   }
}

void keyMenu()
{
    if(menuA==2)
    {
        if(key==Key_Return)
        {

            if(menuF==1)
            {
                xC=xCV;
                yC=yCV;
                zC=zCV;
                menuA=1;
            }
            if(menuF==2)
            {
                timerOkay=2;
                menuF=4;
            }
            if(menuF==3)
            {
                startA=2;
                uniqueP=2;
                pickA=3;
                timerStart=2;
                menuA=1;
                menuF=1;
            }
            if(timerOkay==1)
            {
            //basic mug
            if(menuF==4)
            {
             mugTI=1;
             menuF=1;
            }
            //champion mug
            if(menuF==5 && championA==2)
            {
             mugTI=2;
             menuF=1;
            }
            //happy mug
            if(menuF==6 && totalR==2 || menuF==6 && totalR==4)
            {
             mugTI=3;
             menuF=1;
            }
            //sad mug
            if(menuF==7 && totalR==3 || menuF==7 && totalR==4)
            {
             mugTI=4;
             menuF=1;
            }
            //white belt mug
            if(menuF==8 && advanceM>=100)
            {
             mugTI=5;
             menuF=1;
            }
            if(menuF==9)
            {
             menuF=1;
            }
            }
            if(volumeM==1)
            {
            clickM.play();
            }
        }
    }
}

//start screen
void guiStart()
{
    //display star screen
    if(startA==2)
    {
    std::string startFS;
    std::ostringstream startFO;
    startFO<<"../Resource/undoA/Start/start"<<startF<<".jpg";
    startFS=startFO.str();
    imageTAXI(startFS, "free", xC, yC, zC-9.0);
    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getTranslation(xC,-morph_act2->lod(0)->boundingBox().minCorner().y(),zC-9));
    morph_act2->transform()->computeWorldMatrix(NULL);

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getScaling(8.0,10.0, 1.0));
    morph_act2->transform()->computeWorldMatrix(NULL);
    applet->sceneManager()->tree()->addActor(morph_act2.get());
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor(vl::black);

    xC=-0.14;
    yC=-0.87;
    zC=22.5;

    if(levelA==7)
    {
        startA=2;
        uniqueP=2;
        pickA=3;
        timerStart=2;
        menuA=1;
        menuF=1;
        startF=5;
    }

    //save
    std::ofstream selectS;
    selectS.open("../Resource/remindA/Team.pld");
    if(teamM==1)
    {
        selectS<<"1\n";
    }
    if(teamM==2)
    {
        selectS<<"2\n";
    }
    selectS<<""<<wonR<<"\n";
    selectS<<""<<loseR<<"\n";
    selectS<<""<<advanceM<<"\n";
    selectS<<""<<championA<<"\n";
    selectS<<""<<tutorialA<<"\n";
    selectS<<""<<totalR<<"\n";
    selectS<<""<<mugTI<<"\n";
    selectS<<""<<levelA<<"\n";
    selectS<<""<<handA<<"\n";
    selectS<<""<<volumeM<<"\n";
    selectS.close();
    }

    if(timerStart==2)
    {
        if(timerStartA>=5)
        {
            timerStartA=0;
            timerStart=1;
        }
        timerStartA+=1;
    }
}

void moveStart()
{
    if(startA==2)
    {
        if(handA==1)
        {
        if(startF<=4)
        {
        if(key==Key_Right)
        {
            if(startF==3)
            {
            startF+=1;
            }
        }
        if(key==Key_Left)
        {
            if(startF==4)
            {
            startF-=1;
            }
        }
        if(key==Key_Down)
        {
            if(startF==1 || startF==2)
            {
            startF+=1;
            }
        }
        if(key==Key_Up)
        {
            if(startF==2 || startF==3)
            {
            startF-=1;
            }
            if(startF==4)
            {
            startF-=2;
            }
        }
        }
        if(startF>=6)
        {
            if(key==Key_Left)
            {
                if(startF==7 || startF==9)
                {
                    startF-=1;
                }
            }
            if(key==Key_Right)
            {
                if(startF==6 || startF==8)
                {
                    startF+=1;
                }
            }
            if(key==Key_Up)
            {
                if(startF==8 || startF==9 || startF==10)
                {
                    startF-=2;
                }
            }
            if(key==Key_Down)
            {
                if(startF==8)
                {
                    startF+=2;
                }
                if(startF==9)
                {
                    startF+=1;
                }
                if(startF==6 || startF==7)
                {
                    startF+=2;
                }
            }
        }
    }
    if(handA==2)
        {
        if(startF<=4)
        {
        if(key==Key_D)
        {
            if(startF==3)
            {
            startF+=1;
            }
        }
        if(key==Key_A)
        {
            if(startF==4)
            {
            startF-=1;
            }
        }
        if(key==Key_S)
        {
            if(startF==1 || startF==2)
            {
            startF+=1;
            }
        }
        if(key==Key_W)
        {
            if(startF==2 || startF==3)
            {
            startF-=1;
            }
            if(startF==4)
            {
            startF-=2;
            }
        }
        }
        if(startF>=6)
        {
            if(key==Key_A)
            {
                if(startF==7 || startF==9)
                {
                    startF-=1;
                }
            }
            if(key==Key_D)
            {
                if(startF==6 || startF==8)
                {
                    startF+=1;
                }
            }
            if(key==Key_W)
            {
                if(startF==8 || startF==9 || startF==10)
                {
                    startF-=2;
                }
            }
            if(key==Key_S)
            {
                if(startF==8)
                {
                    startF+=2;
                }
                if(startF==9)
                {
                    startF+=1;
                }
                if(startF==6 || startF==7)
                {
                    startF+=2;
                }
            }
        }
    }
}
}

void keyStart()
{
    if(startA==2 && timerStart==1)
    {
        if(key==Key_Return)
        {
            if(startF==1)
            {
                xC=-2.8, yC=0.6, zC=4.2;
                pickA=4;
                uniqueP=1;
                startA=1;
                matchReset();
            }
            if(startF==2)
            {
                destroyscreenTAXI();
                exit(0);
            }
            if(startF==3)
            {
                startF=6;
            }
            //update this code in the future
            if(startF==4)
            {
                std::ofstream teamD;
                teamD.open("../Resource/remindA/Team.pld");
                teamD.close();
                //select character reset
                uniqueP=1;
                startA=1;
                mugTI=1;
                pickA=2;
                levelA=0;
                wonR=0;
                loseR=0;
                advanceM=0;
                championA=1;
                totalR=1;
                tutorialA=1;
                timerChoose=0;
                teamM=0;
                startF=1;
            }
            if(startF==5)
            {
                levelA=8;
                startF=1;
            }
            if(startF==6)
            {
                handA=1;
            }
            if(startF==7)
            {
                handA=2;
            }
            if(startF==8)
            {
                volumeM=1;
            }
            if(startF==9)
            {
                volumeM=2;
            }
            if(startF==10)
            {
                startF=1;
            }
            if(volumeM==1)
            {
            clickM.play();
            }
        }
    }
}
