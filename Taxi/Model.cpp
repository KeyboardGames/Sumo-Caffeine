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
#include "Audio.h"
#include "../App_Taxi.hpp"
vl::ref<vl::Applet> applet;
vl::ref<vl::ResourceDatabase> res_db;
vl::ref<vl::Actor> morph_act2 = new vl::Actor;
vl::ref<vl::MorphingCallback> morph_cb2 = new vl::MorphingCallback;
vl::ref<vl::Light> light = new vl::Light;
vl::ref<vl::Effect> effect = new vl::Effect;
sf::Music clash;
int dataM=1;
int renderOrder=0;
double coordX1, coordX2, coordZ1, coordZ2;
double xM, zM;
double lightA=1.0;

using namespace vl;

void modelTAXI(std::string modelP, std::string textureP, std::string complexV, bool extraL, double x, double y, double z);
void roomTAXI(std::string modelLP, std::string textureLP, double xL, double yL, double zL);
void moveTAXI(double varX, double varY, double varZ);
void animationTAXI(int limitA, int limitB, float limitS);
void collideTAXI(double locX1, double locX2, double locZ1, double locZ2, double recoilA);
void imageTAXI(std::string imageN, std::string freeI, double xI, double yI, double zI);

//to load a model
void modelTAXI(std::string modelP, std::string textureP, std::string complexV, bool extraL, double x, double y, double z)
{

    dataM=1;
    interestH=3;
    renderOrder+=1;
    if(menuC==1 && showA==1)
    {
    vl::ref<vl::Light> light = new vl::Light;

    res_db = vl::loadResource(modelP);

    VL_CHECK(res_db && res_db->get<vl::Geometry>(0));

    vl::ref<vl::MorphingCallback> morph_cb1 = new vl::MorphingCallback;
    morph_cb1->init(res_db.get());

    int directionC=1;

    effect = new vl::Effect;
    if(extraL==false || extraL==FALSE)
    {

       directionC=2;
    }
    if(directionC==1)
    {

    effect->shader()->setRenderState( light.get(), 0 );
    light->setPosition(vl::fvec4(x,y,z,4)); /* default */
    effect->shader()->enable(vl::EN_LIGHTING);
    }
    effect->shader()->enable(vl::EN_DEPTH_TEST);
    vl::ref<vl::Texture> texture = new vl::Texture;
    texture->prepareTexture2D(textureP, vl::TF_RGBA);
    effect->shader()->gocTextureImageUnit(0)->setTexture(texture.get());

    morph_cb2 = new vl::MorphingCallback;
    morph_act2 = new vl::Actor;

    morph_cb2->bindActor(morph_act2.get());
    morph_cb2->initFrom(morph_cb1.get());

    morph_act2->setEffect(effect.get());

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getTranslation(x,-morph_act2->lod(0)->boundingBox().minCorner().y()+y,z));
    morph_act2->transform()->computeWorldMatrix(NULL);

    morph_cb2->setAnimation(0, 1, 1.5f);
    morph_cb2->startAnimation();

    modelPS=modelP;
    texturePS=textureP;
    xLS=x;
    yLS=y;
    zLS=z;

    if(complexV==("Complex"))
    {

        interestH=1;
    }

    if(complexV==("Non-Complex"))
    {

        interestH=2;
    }

    if(complexV==("Nothing"))
    {

        interestH=3;
    }

    dataM=2;
    if(interestH==1 || interestH==2)
    {

    iSaveTAXI();
    }
    }
}

//to load a room
void roomTAXI(std::string modelLP, std::string textureLP, double xL, double yL, double zL)
{

    dataM=1;
    interestH=3;
    renderOrder+=1;
    if(menuC==1 && showA==1)
    {

    vl::ref<vl::ResourceDatabase> res_db = vl::loadResource(modelLP);

    VL_CHECK(res_db && res_db->get<vl::Geometry>(0));

    vl::ref<vl::MorphingCallback> morph_cb1 = new vl::MorphingCallback;
    morph_cb1->init(res_db.get());

    effect = new vl::Effect;
    effect->shader()->enable(vl::EN_DEPTH_TEST);
    vl::ref<vl::Texture> texture = new vl::Texture;
    texture->prepareTexture2D(textureLP, vl::TF_RGBA);
    effect->shader()->gocTextureImageUnit(0)->setTexture(texture.get());

    morph_act2 = new vl::Actor;
    vl::ref<vl::MorphingCallback> morph_cb2 = new vl::MorphingCallback;
    morph_cb2->bindActor(morph_act2.get());
    morph_cb2->initFrom(morph_cb1.get());

    morph_act2->setEffect(effect.get());

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getTranslation(xL,-morph_act2->lod(0)->boundingBox().minCorner().y()+yL,zL));
    morph_act2->transform()->computeWorldMatrix(NULL);

    morph_cb2->setAnimation(0, 1, 1.5f);
    morph_cb2->startAnimation();

    modelPS=modelLP;
    texturePS=textureLP;
    xLS=xL;
    yLS=yL;
    zLS=zL;

    dataM=3;
    interestH=3;
    iSaveTAXI();
    }
}

void moveTAXI(double varX, double varY, double varZ)
{

    if(menuC==1 && showA==1)
    {
    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getTranslation(varX,-morph_act2->lod(0)->boundingBox().minCorner().y()+varY,varZ));
    morph_act2->transform()->computeWorldMatrix(NULL);

    light->setPosition(vl::fvec4(varX,varY+lightA,varZ,49));
    lightA+=1;
    }
}

void animationTAXI(int limitA, int limitB, float limitS)
{
    if(menuC==1 && showA==1)
    {

    morph_cb2->setAnimation(limitA, limitB, limitS);
    morph_cb2->startAnimation();
    }
}

//model collision
void collideTAXI(double locX1, double locX2, double locZ1, double locZ2, double recoilA)
{
    //model and image collision
    if(dataM==2 || dataM==4)
    {
    if(locZ1-0.0<=coordZ1 && locZ2+1.1>=coordZ2 && locX2+1.6>=coordX2 && locX1-1.8<=coordX1)
    {
    int recoilRH=1;
    if(locZ1-0.0>=coordZ1 && locZ2+1.1<=coordZ2 && locX2-1.6>=coordX2 && locX1+1.8<=coordX1)
    {

        zM-=recoilA;
        xM+=recoilA;
        recoilRH=2;
    }
    if(recoilRH==1)
    {

    zM+=recoilA;
    xM-=recoilA;
    }

    //sound effects for collision/clashes
    int randCS=rand()%4;
    if(randCS==0)
    {
    clash.openFromFile("../Resource/fileA/clash/clash1.ogg");
    }
    if(randCS==1)
    {
    clash.openFromFile("../Resource/fileA/clash/clash2.ogg");
    }
    if(randCS==2)
    {
    clash.openFromFile("../Resource/fileA/clash/clash3.ogg");
    }
    if(randCS==3)
    {
    clash.openFromFile("../Resource/fileA/clash/clash4.ogg");
    }
    if(randCS==4)
    {
    clash.openFromFile("../Resource/fileA/clash/clash5.ogg");
    }
    if(volumeM==1)
    {
    clash.play();
    }
    }
    }

    //room collision
    if(dataM==3)
    {

    if(locZ2>=coordZ1)
    {

    zM-=recoilA;
    }

    if(locZ1<=coordZ2)
    {

    zM+=recoilA;
    }

    double recoilAR;
    recoilAR=recoilA/2;

    if(locX2-recoilAR>=coordX2)
    {

    xM-=recoilA;
    }

    if(locX1+recoilA<=coordX1)
    {

    xM+=recoilA;
    }
    }

    //room collision
    if(dataM==3)
    {

    if(locZ2>=coordZ1)
    {

    zM-=recoilA;
    }

    if(locZ1<=coordZ2)
    {

    zM+=recoilA;
    }

    double recoilAR;
    recoilAR=recoilA/2;

    if(locX2-recoilAR>=coordX2)
    {

    xM-=recoilA;
    }

    if(locX1+recoilA<=coordX1)
    {

    xM+=recoilA;
    }
    }
}

void imageTAXI(std::string imageN, std::string freeI, double xI, double yI, double zI)
{

    dataM=1;
    interestH=3;
    renderOrder+=1;
    if(menuC==1 && showA==1)
    {

    vl::ref<vl::ResourceDatabase> res_db = vl::loadResource("../Variable/image.md2");

    VL_CHECK(res_db && res_db->get<vl::Geometry>(0));

    vl::ref<vl::MorphingCallback> morph_cb1 = new vl::MorphingCallback;
    morph_cb1->init(res_db.get());

    effect = new vl::Effect;
    vl::ref<vl::Texture> texture = new vl::Texture;
    texture->prepareTexture2D(imageN, vl::TF_RGBA);
    effect->shader()->gocTextureImageUnit(0)->setTexture(texture.get());

    morph_cb2 = new vl::MorphingCallback;
    morph_act2 = new vl::Actor;

    morph_cb2->bindActor(morph_act2.get());
    morph_cb2->initFrom(morph_cb1.get());

    morph_act2->setEffect(effect.get());

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getTranslation(xI,-morph_act2->lod(0)->boundingBox().minCorner().y()+yI,zI));
    morph_act2->transform()->computeWorldMatrix(NULL);

    morph_cb2->setAnimation(0, 1, 1.5f);
    morph_cb2->startAnimation();

    freeIS=freeI;
    imageNS=imageN;
    xLS=xI;
    yLS=yI;
    zLS=zI;

    if(freeI==("Non-Free")) //form hitbox
    {

    dataM=4;
    interestH=2;
    }

    if(freeI==("Free")) //form no hitbox
    {

    dataM=5;
    interestH=3;
    }

    if(interestH==2)
    {

    iSaveTAXI();
    }
    }
}
