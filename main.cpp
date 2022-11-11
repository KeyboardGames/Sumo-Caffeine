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
#include <cstdlib>
#include <ctime>
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
#include "intro.h"
#include "cameraSUMO.h"
sf::Music musicA, musicB, musicC;
int timerA=1, timerB=1;
int videoT=1;
int audioT=1, audioC=1;
int teamM=0;
int tutorialA=1;
int totalR=1, wonR=0, loseR=0;
int advanceM=0;
int championA=1;
int levelA=0;
int handA=1;
int volumeM=1;

using namespace vl;
using namespace vlWin32;

//setup window & applet
int APIENTRY WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

  VisualizationLibrary::init();

  OpenGLContextFormat format;
  format.setDoubleBuffer(true);
  format.setRGBABits( 8,8,8,0 );
  format.setDepthBufferBits(24);
  format.setStencilBufferBits(8);
  format.setMultisampleSamples(16);
  format.setMultisample(false);

  applet = new App_Taxi;
  applet->initialize();

  ref<vlWin32::Win32Window> win32_window = new vlWin32::Win32Window;

  win32_window->addEventListener(applet.get());

  applet->rendering()->as<Rendering>()->renderer()->setFramebuffer( win32_window->framebuffer() );
  applet->rendering()->as<Rendering>()->camera()->viewport()->setClearColor( vl::royalblue );

  int x = 5; //have "x=5" for fullscreen and "x=0" or "x=(insert number)" for custom window sizing
  int y = 0;
  int width = 785;
  int height= 600;
  win32_window->initWin32GLWindow(NULL, NULL, "Sumo-Caffeine", format, x, y, width, height );

  freshTAXI();
  loadTeam();
  fullscreenTAXI();

  unsigned seed = time(0);
  srand(seed);

  win32_window->show();

  int res = vlWin32::messageLoop();

  win32_window = NULL;

  VisualizationLibrary::shutdown();
  return res;
}
