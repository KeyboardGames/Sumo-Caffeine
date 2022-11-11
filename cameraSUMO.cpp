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
int clockC=0;
int funkC=1;

void arenaCameraForm();

void arenaCameraForm()
{

    if(menuC==1 && showA==1)
    {

    if(funkC==3 && matchA==1)
    {
    funkC=1;
    }

    if(funkC==1 && matchA==1)
    {
    if(yC<=9.3)
    {
        yC+=0.1;
    }
  //  xC=-2.8;
   // zC=4.2;
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor( vl::royalblue );
    }

    if(funkC==2 && matchA==1)
    {
    if(yC<=9.3)
    {
        yC+=0.1;
    }
    if(mugMA==1)
    {
    xC=mug1X;
    yC=9.4;
    zC=mug1Z;
    }
    if(mugMA==2)
    {
    xC=mug2X;
    yC=9.4;
    zC=mug2Z;
    }
    }
  //  xC=-2.8;
   // zC=4.2;
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor( vl::royalblue );
    }

    if(matchA==2)
    {
    xC=-2.8;
    yC=20.0;
    zC=4.2;
    applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor( vl::black );
    }
}
