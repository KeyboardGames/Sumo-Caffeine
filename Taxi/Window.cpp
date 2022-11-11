//not that-well supported
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
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wtypes.h>
#include "Model.h"
#include "Camera.h"
#include "Complex.h"
#include "Input.h"
#include "Text.h"
#include "Window.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#pragma comment(lib, "user32.lib")

int totalW, totalH;
int taskH;
int heightS=GetSystemMetrics(SM_CYSCREEN);
int heightR=0;

BOOL bFullscreen = FALSE;

void fullscreenTAXI();
void destroyscreenTAXI();

void ChangeToFullScreen(int width, int height) //thanks gametutorials (https://github.com/gametutorials)
{
    DEVMODE dmSettings;

    memset(&dmSettings,0,sizeof(dmSettings));

    if(!EnumDisplaySettings(NULL,ENUM_CURRENT_SETTINGS,&dmSettings))
    {

        MessageBox(NULL, "Could Not Execute Fullscreen Feature Successfully", "Error", MB_OK);
    }

    dmSettings.dmPelsWidth  = width;
    dmSettings.dmPelsHeight = height;
    dmSettings.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

    int result = ChangeDisplaySettings(&dmSettings,CDS_FULLSCREEN);

    if(result != DISP_CHANGE_SUCCESSFUL)
    {

        MessageBox(NULL, "Display Mode Not Compatible For Fullscreen Feature", "Error", MB_OK);
    }
}

void GetDesktopResolution(int& horizontal, int& vertical)
{
    RECT desktop;

    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);

    vertical = desktop.bottom;
}

void fullscreenTAXI()
{

    int wantX=800;
    int wantY=600;
    int horizontal=0;
    int vertical=0;
    wantY=wantY-50;
    heightR=0;
    taskH=0;
    totalW=0;
    totalH=0;

    bFullscreen = TRUE;

    ChangeToFullScreen(SCREEN_WIDTH, SCREEN_HEIGHT);
    GetDesktopResolution(horizontal, vertical);
    heightR=vertical;
    taskH=heightR-heightS;
    totalH=wantY-taskH;
    totalH=totalH-183;
    totalW=wantX-20;
}

void destroyscreenTAXI()
{

    bFullscreen = FALSE;
    ChangeDisplaySettings(NULL, 0);
}
