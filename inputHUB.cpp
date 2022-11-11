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

void inputHUBI();
void inputHUBM();

void inputHUBI()
{
    moveMug();
    specialMoves();
}

void inputHUBM()
{
    mousePress();
}
