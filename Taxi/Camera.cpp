#include <vlCore/VisualizationLibrary.hpp>
#include <vlGraphics/Text.hpp>
#include <vlGraphics/Applet.hpp>
#include <vlCore/Transform.hpp>
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
#include <time.h>
#include <windows.h>
#include "Model.h"
#include "Camera.h"
#include "Complex.h"
#include "Input.h"
#include "Text.h"
#include "Window.h"
#include "../sumoHUB.h"
#include "../arena.h"
#include "../cameraSUMO.h"
#include "../intro.h"
#include "../gui.h"
vl::ref<vl::TrackballManipulator> trackball = new vl::TrackballManipulator;
vl::ref<vl::SceneManagerActorTree> scene_manager;
vl::ref<vl::Transform> tr1A;
vl::ref<vl::Transform> tr2A;
vl::ref<vl::RenderingTree> mRenderingTree;
vl::ref<vl::Rendering> mRendering0;
vl::ref<vl::Rendering> mRendering1;
bool timerTAXI;
//-2.8, 0.6, 4.2
int timR=1000;
int dependX=1;
//you can edit these variables to your preference of where the camera should spawn (single camera)
double xC=-2.8, yC=0.6, zC=4.2;
//you can edit these variables to your preference of where the cameras should spawn (two cameras)
double xMC1=0.0, yMC1=0.0, zMC1=3.5, xMC2=0.0, yMC2=1.0, zMC2=3.5;

using namespace vl;

void cameraTAXI(); //single camera
void borderTAXI(); //single camera + 2 cameras
void multiCameraTAXI(); //2 cameras
void updateMultiCameraTAXI(); //2 cameras
void setTimerTAXI(int timM, int timF, int switchT);
void debugTAXI();
void freshTAXI();

//to load the camera
void cameraTAXI()
{

    vec3 eye = vec3(xC,yC,zC);
    vec3 center;
    if(matchA==1 && funkC==1 && shatteredA==1)
    {
    center = vec3(0,1,1);
    }
    if(matchA==1 && funkC==2 && shatteredA==1 && mugMA==1)
    {
    center = vec3(mug1X,1,mug1Z);
    }
    if(matchA==1 && funkC==2 && shatteredA==1 && mugMA==2)
    {
    center = vec3(mug2X,1,mug2Z);
    }
    if(shatteredA==2 && health1==0)
    {
    center = vec3(mug2X,1,mug2Z);
    }
    if(shatteredA==2 && health2==0)
    {
    center = vec3(mug1X,1,mug1Z);
    }
    if(matchA==2 && funkC==1 && shatteredA==1 || viewG==2 && menuC==2 || viewG==2 && showA==2 || viewG==3 && menuC==2 || viewG==3 && showA==2 || pickA==2 || menuA==2 || uniqueP==2)
    {
    center = vec3(xC,yC,zC-4.0);
    }
    vec3 up     = vec3(0,1,0);
    mat4 view_mat = mat4::getLookAt(eye, center, up);
    applet->rendering()->as<Rendering>()->camera()->setViewMatrix( view_mat );
    applet->rendering()->as<Rendering>()->camera()->setFOV(40);
    dependX=2;

    borderTAXI();
}

//see if the camera should back away from an actor
void borderTAXI()
{

int attemptA=1;

//model hitbox and image hitbox
if(dataM==2 || dataM==4)
{

//single camera
//camera 1
if(zC+1.5>=coordZ2 && zC-1.5<=coordZ1 && xC+1.5>=coordX2 && xC-1.5<=coordX1)
{
    int cameraRH=1;
    if(dependX==2)
    {
    if(zC-1.5>=coordZ2 && zC+1.5<=coordZ1 && xC-1.5>=coordX2 && xC+1.5<=coordX1)
    {

        zC-=1.6;
        xC+=1.6;
        cameraRH=2;
    }
    if(cameraRH==1)
    {

    zC+=0.8;
    xC-=0.7;
    }
    }
}

//multiple cameras
//camera 1
if(zMC1+1.5>=coordZ2 && zMC1-1.5<=coordZ1 && xMC1+1.5>=coordX2 && xMC1-1.5<=coordX1)
{
    int cameras1RH=1;
    if(dependX==3)
    {
    if(zMC1-1.5>=coordZ2 && zMC1+1.5<=coordZ1 && xMC1-1.5>=coordX2 && xMC1+1.5<=coordX1)
    {

        zMC1-=1.6;
        xMC1+=1.6;
        cameras1RH=2;
    }
    if(cameras1RH==1)
    {

    zMC1+=0.8;
    xMC1-=0.7;
    }
    }
}
//camera 2
if(zMC2+1.5>=coordZ2 && zMC2-1.5<=coordZ1 && xMC2+1.5>=coordX2 && xMC2-1.5<=coordX1)
{
    int cameras2RH=1;
    if(dependX==3)
    {
    if(zMC2-1.5>=coordZ2 && zMC2+1.5<=coordZ1 && xMC2-1.5>=coordX2 && xMC2+1.5<=coordX1)
    {

        zMC2-=1.6;
        xMC2+=1.6;
        cameras2RH=2;
    }
    if(cameras2RH==1)
    {

    zMC2+=0.8;
    xMC2-=0.7;
    }
    }
}
}
//room hitbox
if(dataM==3)
{

//single camera
//camera 1
if(zC>=coordZ1)
{

    zC-=2;
}

if(zC<=coordZ2)
{

    zC+=2;
}

if(xC-1.0>=coordX2)
{

   xC-=2;
}

if(xC+2.5<=coordX1)
{

    xC+=2;
}

//multiple cameras
//camera 1
if(zMC1>=coordZ1)
{

    zMC1-=2;
}

if(zMC1<=coordZ2)
{

    zMC1+=2;
}

if(xMC1-1.0>=coordX2)
{

    xMC1-=2;
}

if(xMC1+2.5<=coordX1)
{

    xMC1+=2;
}
//camera 2
if(zMC2>=coordZ1)
{

    zMC2-=2;
}

if(zMC2<=coordZ2)
{

    zMC2+=2;
}

if(xMC2-1.0>=coordX2)
{

    xMC2-=2;
}

if(xMC2+2.5<=coordX1)
{

    xMC2+=2;
}
}
}

void multiCameraTAXI()
{

    ref<Renderer> renderer = applet->rendering()->as<Rendering>()->renderer();
    ref<FramebufferObject> framebuffer = applet->rendering()->as<Rendering>()->renderer()->framebuffer();
    // install new rendering tree
    mRenderingTree = new RenderingTree;
    applet->setRendering(mRenderingTree.get());
    mRendering0 = new Rendering;
    mRendering1 = new Rendering;
    mRenderingTree->subRenderings()->push_back(mRendering0.get());
    mRenderingTree->subRenderings()->push_back(mRendering1.get());

    tr1A = new Transform;
    tr2A = new Transform;
    tr1A->addChild( tr2A.get() );

    for( size_t i=0; i<mRenderingTree->subRenderings()->size(); ++i )
    {
      mRenderingTree->subRenderings()->at(i)->as<Rendering>()->renderer()->setFramebuffer( framebuffer.get() );
      mRenderingTree->subRenderings()->at(i)->as<Rendering>()->setRenderer( renderer.get() );
      mRenderingTree->subRenderings()->at(i)->as<Rendering>()->setCamera( new Camera );
      mRenderingTree->subRenderings()->at(i)->as<Rendering>()->setTransform( tr1A.get() );
      scene_manager = new SceneManagerActorTree;
      mRenderingTree->subRenderings()->at(i)->as<Rendering>()->sceneManagers()->push_back( scene_manager.get() );

      switch(i)
      {
      case 0: mRenderingTree->subRenderings()->at(i)->as<Rendering>()->camera()->viewport()->setClearColor(black); break;
      case 1: mRenderingTree->subRenderings()->at(i)->as<Rendering>()->camera()->viewport()->setClearColor(yellow); break;
      }

      mat4 m;
      switch(i)
      {
      case 0: m = mat4::getLookAt( vec3(0,1,3.5f), vec3(0,0,0), vec3(0,1,0) ); break;
      case 1: m = mat4::getLookAt( vec3(0,1,3.5f), vec3(0,0,0), vec3(0,1,0) ); break;
      }
      mRenderingTree->subRenderings()->at(i)->as<Rendering>()->camera()->setViewMatrix(m);
      dependX=3;
    }
}

void updateMultiCameraTAXI()
{
    mat4 m;
    m = mat4::getLookAt(vec3(xMC1,yMC1,zMC1), vec3(xMC1,yMC1,zMC1-4.0), vec3(0,1,0));
    mRenderingTree->subRenderings()->at(0)->as<Rendering>()->camera()->setViewMatrix(m);
    m = mat4::getLookAt(vec3(xMC2,yMC2,zMC2), vec3(xMC2,yMC2,zMC2-4.0), vec3(0,1,0));
    mRenderingTree->subRenderings()->at(1)->as<Rendering>()->camera()->setViewMatrix(m);
}

void setTimerTAXI(int timM, int timF, int switchT)
{

    timF=timR;
    timerTAXI=false;

    if(timF<=timM)
    {

    timerTAXI=true;
    }

    timF-=1;
    timR=timF;
    if(timerTAXI==true)
    {

    timR=switchT;
    }
}

void debugTAXI()
{

    std::cout<<"CAMERA X: "<<xC<<""<<std::endl;
    std::cout<<"CAMERA Y: "<<yC<<""<<std::endl;
    std::cout<<"CAMERA Z: "<<zC<<""<<std::endl;
    std::cout<<""<<std::endl;
    std::cout<<"(FPS reports may not be accurate)"<<std::endl;
    vl::Log::print( vl::Say("FPS=%.1n\n") << applet->fps() );
}

void freshTAXI()
{

    std::ofstream reloadA;
    reloadA.open("../Variable/log.txt");
    reloadA<<"";
    reloadA.close();
}
