#include <vlCore/VisualizationLibrary.hpp>
#include <vlGraphics/Text.hpp>
#include <vlGraphics/Applet.hpp>
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
#include "Model.h"
#include "Camera.h"
#include "Complex.h"
#include "Input.h"
#include "Text.h"
#include "Window.h"
#include "../App_Taxi.hpp"
#include "../intro.h"
#include "../sumoHUB.h"
#include "../arena.h"
#include "../cameraSUMO.h"
#include "../inputHUB.h"
unsigned short ch;
vl::EMouseButton btn;
vl::EKey key;
int trialE=1, zCCB;
int mouseX, mouseY;
int regainA=1;
int unlock1S=1, unlock1SC=1;
int unlock2S=1, unlock2SC=1;
int unlock3S=1, unlock3SC=1;
int basicTimer=1, basicTimerA=0;

using namespace vl;

void moveMug();
void specialMoves();
void mousePress();

void basicDelay()
{
    if(basicTimer==2)
    {
        if(basicTimerA>=3)
        {
            basicTimer=1;
        }
        basicTimerA+=1;
    }
}

//move your mug
void moveMug()
{
    if(menuC==1 && showA==1 && sumoA==2 && matchA==1 && shatteredA==1 && mugMA==1 && menuA==1 && basicTimer==1)
    {
    if(handA==2)
    {
    if(key==vl::Key_W)
    {

     mug1Z-=0.2;
     basicDelay();
    }

    if(key==vl::Key_A)
    {

     mug1X-=0.2;
     basicDelay();
    }

    if(key==vl::Key_S)
    {

     mug1Z+=0.2;
     basicDelay();
    }

    if(key==vl::Key_D)
    {

     mug1X+=0.2;
     basicDelay();
    }
    }
    if(handA==1)
    {
    if(key==vl::Key_Up)
    {

     mug1Z-=0.2;
     basicDelay();
    }

    if(key==vl::Key_Left)
    {

     mug1X-=0.2;
     basicDelay();
    }

    if(key==vl::Key_Down)
    {

     mug1Z+=0.2;
     basicDelay();
    }

    if(key==vl::Key_Right)
    {

     mug1X+=0.2;
     basicDelay();
    }
    }

    if(key==vl::Key_Return)
    {

    if(funkC==2)
    {
    funkC=3;
    }
    if(funkC==1)
    {
    funkC=2;
    }
    basicDelay();
    }
    }
    if(menuC==1 && showA==1 && sumoA==2 && matchA==1 && shatteredA==1 && mugMA==2 && menuA==1 && basicTimer==1)
    {
    if(handA==2)
    {
    if(key==vl::Key_W)
    {

     mug2Z-=0.2;
     basicDelay();
    }

    if(key==vl::Key_A)
    {

     mug2X-=0.2;
     basicDelay();
    }

    if(key==vl::Key_S)
    {

     mug2Z+=0.2;
     basicDelay();
    }

    if(key==vl::Key_D)
    {

     mug2X+=0.2;
     basicDelay();
    }
    }
    if(handA==1)
    {
    if(key==vl::Key_Up)
    {

     mug2Z-=0.2;
     basicDelay();
    }

    if(key==vl::Key_Left)
    {

     mug2X-=0.2;
     basicDelay();
    }

    if(key==vl::Key_Down)
    {

     mug2Z+=0.2;
     basicDelay();
    }

    if(key==vl::Key_Right)
    {

     mug2X+=0.2;
     basicDelay();
    }
    }

    if(key==vl::Key_Return)
    {

    if(funkC==2)
    {
    funkC=3;
    }
    if(funkC==1)
    {
    funkC=2;
    }
    basicDelay();
    }
    }
}

void specialMoves()
{
    //special attacks
    if(menuC==1 && showA==1 && sumoA==2 && matchA==1 && shatteredA==1 && mugMA==1 && menuA==1)
    {
    if(pushM==2)
    {
    //1
    if(key==vl::Key_Space)
    {
        if(unlock1S==1)
        {
            unlock1S=2;
        }
    }
    //1
    if(key==vl::Key_J)
    {
        if(unlock1S==2)
        {
        damage2+=1;
        unlock1S=1;
        }
    }
    //1
    if(unlock1S==2)
    {
        unlock1SC+=1;
    if(unlock1SC>=4)
    {
        unlock1S=1;
        unlock1SC=1;
    }
    }
    //2
    if(key==vl::Key_X)
    {
        if(unlock2S==1)
        {
            unlock2S=2;
        }
    }
    //2
    if(key==vl::Key_J)
    {
        if(unlock2S==2)
        {
        unlock2S=3;
        }
    }
    //3
    if(key==vl::Key_G)
    {
        if(unlock3S==1)
        {
            unlock3S=2;
        }
    }
    //3
    if(key==vl::Key_K)
    {
        if(unlock3S==2)
        {
            unlock3S=3;
        }
    }
    //3
    if(key==vl::Key_Space)
    {
        if(unlock3S==3)
        {
            damage2+=2;
            unlock3S=1;
        }
    }
    //3
    if(unlock3S==2 || unlock3S==3)
    {
    unlock3SC+=1;
    if(unlock3SC>=5)
    {
        unlock3S=1;
        unlock3SC=1;
    }
    }
    }
    }

    if(menuC==1 && showA==1 && sumoA==2 && matchA==1 && shatteredA==1 && mugMA==2 && menuA==1)
    {
    if(pushM==2)
    {
    //1
    if(key==vl::Key_Space)
    {
        if(unlock1S==1)
        {
            unlock1S=2;
        }
    }
    //1
    if(key==vl::Key_J)
    {
        if(unlock1S==2)
        {
        damage1+=1;
        unlock1S=1;
        }
    }
    //1
    if(unlock1S==2)
    {
        unlock1SC+=1;
    if(unlock1SC>=4)
    {
        unlock1S=1;
        unlock1SC=1;
    }
    }
    //2
    if(key==vl::Key_X)
    {
        if(unlock2S==1)
        {
            unlock2S=2;
        }
    }
    //2
    if(key==vl::Key_J)
    {
        if(unlock2S==2)
        {
        unlock2S=3;
        }
    }
    //3
    if(key==vl::Key_G)
    {
        if(unlock3S==1)
        {
            unlock3S=2;
        }
    }
    //3
    if(key==vl::Key_K)
    {
        if(unlock3S==2)
        {
            unlock3S=3;
        }
    }
    //3
    if(key==vl::Key_Space)
    {
        if(unlock3S==3)
        {
            damage1+=2;
            unlock3S=1;
        }
    }
    //3
    if(unlock3S==2 || unlock3S==3)
    {
    unlock3SC+=1;
    if(unlock3SC>=5)
    {
        unlock3S=1;
        unlock3SC=1;
    }
    }
    }
    }
}

//Mouse Input
void mousePress()
{
    //2
    if(menuC==1 && showA==1 && sumoA==2 && matchA==1 && shatteredA==1 && mugMA==1 && menuA==1)
    {
    if(btn==RightButton)
    {
        if(unlock2S==3)
        {
        damage2+=4;
        unlock2S=1;
        }
    }
    if(unlock2S==2 || unlock2S==3)
    {
        unlock2SC+=1;
    if(unlock2SC>=5)
    {
        unlock2S=1;
        unlock2SC=1;
    }
    }
    }

    if(menuC==1 && showA==1 && sumoA==2 && matchA==1 && shatteredA==1 && mugMA==2 && menuA==1)
    {
    if(btn==RightButton)
    {
        if(unlock2S==3)
        {
        damage1+=4;
        unlock2S=1;
        }
    }
    if(unlock2S==2 || unlock2S==3)
    {
        unlock2SC+=1;
    if(unlock2SC>=5)
    {
        unlock2S=1;
        unlock2SC=1;
    }
    }
    }

    if(menuC==1 && showA==1 && sumoA==2 && matchA==1 && shatteredA==1 && mugMA==2 && menuA==1)
    {
    if(btn==RightButton)
    {
        if(unlock2S==3)
        {
        damage1+=4;
        unlock2S=1;
        }
    }
    if(unlock2S==2 || unlock2S==3)
    {
        unlock2SC+=1;
    if(unlock2SC>=5)
    {
        unlock2S=1;
        unlock2SC=1;
    }
    }
    }

    if(btn==LeftButton)
    {
    if(resultM==2)
    {
    if(loseM+1==5)
    {
        matchReset();
    }
    if(winsM==5)
    {
        matchReset();
    }
    }
    if(resultM==3)
    {
    if(loseM==5)
    {
        matchReset();
    }
    if(winsM+1==5)
    {
        matchReset();
    }
    }
    }

    if(btn==LeftButton)
    {
        if(pickA==2)
        {
            POINT p;
            if(GetCursorPos(&p))
            {
                if(p.y>=0 && p.y<=260)
                {
                    teamM=1;

                }
                if(p.y>=261 && p.y<=520)
                {
                    teamM=2;
                }
            }
            clickM.stop();
            clickM.play();
        }
    }
}
