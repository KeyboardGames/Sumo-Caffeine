#include <vlGraphics/FontManager.hpp>
#include <vlCore/VisualizationLibrary.hpp>
#include <vlGraphics/Text.hpp>
#include <vlGraphics/Applet.hpp>
#include <vlCore/Time.hpp>
#include <vlCore/ResourceDatabase.hpp>
#include <vlGraphics/RenderingTree.hpp>
#include <vlGraphics/SceneManager.hpp>
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
#include "../intro.h"
#include "../arena.h"
#include "../App_Taxi.hpp"
vl::ref<vl::Text> text;
vl::ref<vl::Effect> effectT;
int menuC=1, menuP=1, noteA=1, showA=1, videoV=1, timerX=1;
double xCR, yCR, zCR, videoP=0;

void dialogTAXI(int sizeF, std::string fileNF, std::string fileNT, std::string colorD, std::string spotT, std::string centerT);
void videoTAXI(std::string folderW, int minF, int maxF, bool autoS, bool loopM, int timerV);
void loadI();
void menuTAXI(std::string folderM);
void editMenu(); //the editable menu for you

void dialogTAXI(int sizeF, std::string fileNF, std::string fileNT, std::string colorD, std::string spotT, std::string centerT)
{

    float space = 75;

    vl::ref<vl::Font> font;
    font = vl::defFontManager()->acquireFont(fileNF, sizeF);

    effectT = new vl::Effect;
    effectT->shader()->enable(vl::EN_BLEND);

    text = new vl::Text;
    text->setFont(font.get());
    //puts "breaks" in text
    text->setText(fileNT);
    text->setMode(vl::Text2D);
    if(spotT==("Top") && centerT==("Center"))
    {

    text->setAlignment(vl::AlignTop | vl::AlignHCenter);
    text->setViewportAlignment(vl::AlignTop | vl::AlignHCenter);
    text->translate(0,-50,0);
    }

    if(spotT==("Top") && centerT==("Left"))
    {

    text->setAlignment(vl::AlignTop | vl::AlignLeft);
    text->setViewportAlignment(vl::AlignTop | vl::AlignLeft);
    text->translate(0,-50,0);
    }

    if(spotT==("Bottom") && centerT==("Center"))
    {

    text->setAlignment(vl::AlignBottom | vl::AlignHCenter);
    text->setViewportAlignment(vl::AlignBottom | vl::AlignHCenter);
    text->translate(0,50,0);
    }

    if(spotT==("Bottom") && centerT==("Left"))
    {

    text->setAlignment(vl::AlignBottom | vl::AlignLeft);
    text->setViewportAlignment(vl::AlignBottom | vl::AlignLeft);
    text->translate(0,50,0);
    }

    if(colorD==("Black"))
    {

    text->setColor(vl::black);
    }
    if(colorD==("Red"))
    {

    text->setColor(vl::red);
    }
    if(colorD==("White"))
    {

    text->setColor(vl::white);
    }
    if(colorD==("Blue"))
    {

    text->setColor(vl::blue);
    }
    if(colorD==("Green"))
    {

    text->setColor(vl::green);
    }
    if(colorD==("Yellow"))
    {

    text->setColor(vl::yellow);
    }
    if(colorD==("Orange"))
    {

    text->setColor(vl::orange);
    }
    text->setMargin(10);
}

void videoTAXI(std::string folderW, int minF, int maxF, bool autoS, bool loopM, int timerV)
{

    if(videoV==1)
    {

        noteA=minF;
        std::ostringstream guyC;
        guyC<<minF;
        std::string guyS=guyC.str();
        std::istringstream (guyS)>>videoP;
        videoV=2;
        showA=1;
    }

    vl::ref<vl::ResourceDatabase> res_db = vl::loadResource("../Variable/image.md2");

    VL_CHECK(res_db && res_db->get<vl::Geometry>(0));

    vl::ref<vl::MorphingCallback> morph_cb1 = new vl::MorphingCallback;
    morph_cb1->init(res_db.get());

    vl::ref<vl::Effect> effect = new vl::Effect;
    vl::ref<vl::Texture> texture = new vl::Texture;
    std::string folderT;
    std::ostringstream folderO;
    int videoI;
    std::ostringstream noteC;
    noteC<<videoP;
    std::string jerry=noteC.str();
    std::istringstream (jerry) >> videoI;
    if(videoI==noteA && videoI<=maxF)
    {
    noteA+=1;
    }
    folderO<<""<<folderW<<"/video"<<videoI<<".png";
    folderT=folderO.str();

    if(autoS==true && showA==1)
    {

        xCR=xC;
        yCR=yC;
        zCR=zC;
        xC=-0.14;
        yC=-0.07;
        zC=18.5;
        menuP=1;
        menuC=2;
        showA=2;
    }

    if(videoI>=maxF)
    {

        if(loopM==true || loopM==NULL)
        {

        noteA=1;
        videoP=1;
        videoV=1;
        if(autoS==true && showA==1)
        {

        showA=2;
        }
        std::ostringstream folderOO;
        int videoII;
        std::ostringstream noteCC;
        noteCC<<videoP;
        std::string jerryA=noteCC.str();
        std::istringstream (jerryA) >> videoII;
        if(videoII==noteA)
        {

         showA=1;
         noteA+=1;
        }
        folderOO<<""<<folderW<<"/Layer "<<videoI<<".png";
        folderT=folderOO.str();
        }

        if(loopM==false)
        {

            xC=xCR;
            yC=yCR;
            zC=zCR;
            viewG=1;
            menuP=1;
            menuC=3;
            showA=1;
            pickV=2;
            loadI();
            timerX+=1;
        }
    }

    texture->prepareTexture2D(folderT, vl::TF_RGBA);
    effect->shader()->gocTextureImageUnit(0)->setTexture(texture.get());

    morph_cb2 = new vl::MorphingCallback;
    morph_act2 = new vl::Actor;

    morph_cb2->bindActor(morph_act2.get());
    morph_cb2->initFrom(morph_cb1.get());

    morph_act2->setEffect(effect.get());

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getTranslation(xC,-morph_act2->lod(0)->boundingBox().minCorner().y(),zC-9));
    morph_act2->transform()->computeWorldMatrix(NULL);

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getScaling(10.0, 8.0, 1.0));
    morph_act2->transform()->computeWorldMatrix(NULL);

    if(menuC==2)
    {

    morph_cb2->setAnimation(0, 1, 1.5f);
    morph_cb2->startAnimation();
    }
    videoP+=1;
}

void loadI()
{

    if(menuC==2 && showA==1)
    {
    if(key==vl::Key_Escape)
    {

     xC=xCR;
     yC=yCR;
     zC=zCR;
     viewG=1;
     menuX+=1;
     menuP=1;
     menuC=3;
    }
    }

    if(menuC==1 && showA==1)
    {
    if(key==vl::Key_Escape)
    {

     xCR=xC;
     yCR=yC;
     zCR=zC;
     xC=-0.14;
     yC=-0.87;
     zC=18.5;
     menuP=1;
     menuC=2;
    }
    }

    if(menuC==3)
    {

        menuC=1;
    }
}

void menuTAXI(std::string folderM)
{

    if(showA==1)
    {

    vl::ref<vl::ResourceDatabase> res_db = vl::loadResource("../Variable/image.md2");

    VL_CHECK(res_db && res_db->get<vl::Geometry>(0));

    vl::ref<vl::MorphingCallback> morph_cb1 = new vl::MorphingCallback;
    morph_cb1->init(res_db.get());

    vl::ref<vl::Effect> effect = new vl::Effect;
    vl::ref<vl::Texture> texture = new vl::Texture;
    std::string folderT;
    std::ostringstream folderO;
    folderO<<""<<folderM<<"/menu1"<<menuP<<".png";
    folderT=folderO.str();

    texture->prepareTexture2D(folderT, vl::TF_RGBA);
    effect->shader()->gocTextureImageUnit(0)->setTexture(texture.get());

    morph_cb2 = new vl::MorphingCallback;
    morph_act2 = new vl::Actor;

    morph_cb2->bindActor(morph_act2.get());
    morph_cb2->initFrom(morph_cb1.get());

    morph_act2->setEffect(effect.get());

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getTranslation(xC,-morph_act2->lod(0)->boundingBox().minCorner().y(),zC-9));
    morph_act2->transform()->computeWorldMatrix(NULL);

    morph_act2->setTransform(new vl::Transform);
    morph_act2->transform()->setLocalMatrix(vl::mat4::getScaling(8.0, 8.0, 1.0));
    morph_act2->transform()->computeWorldMatrix(NULL);
    viewG=2;

    if(menuC==2)
    {

    morph_cb2->setAnimation(0, 1, 1.5f);
    morph_cb2->startAnimation();
    }
    }
}

//should edit depending on menu
void editMenu()
{

    if(menuC==2 && showA==1)
    {

    if(key==vl::Key_Return)
    {

    //what should happen if selected
    if(menuP==1)
    {

        destroyscreenTAXI();
        exit(0);
    }

    if(menuP==2)
    {

        xC=xCR;
        yC=yCR;
        zC=zCR;
        viewG=1;
        menuC=1;
    }

    if(menuP==3)
    {

        std::cout<<"Hi"<<std::endl;
    }
    }

    //move selector
    if(menuC==2)
    {
    if(key==vl::Key_Down)
    {

        if(menuP<=3)
        {

        menuP+=1;
        }
        if(menuP==4)
        {

        menuP=1;
        }
    }

    if(key==vl::Key_Up)
    {

        if(menuP>=1)
        {

        menuP-=1;
        }
        if(menuP==0)
        {

        menuP=3;
        }
    }
}
}
}
