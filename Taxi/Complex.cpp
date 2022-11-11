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
std::string pathA, pathM, modelPS, texturePS, detailAS, imageNS, freeIS;
std::ofstream inFile;
int endT=0, endS=1, nowA=1, loopA=0, loopB=1, loopC, loopD=0, loopE, interestH=1, interestT=1;
double top, sideA, sideB, sideC, sideD, bottom;
double storedA, storedB, storedC, storedD, storedE, storedF;
double averageY, volumeA;

double xLS, yLS, zLS;

using namespace vl;

std::string tabA[9999]={"","","","","","","","","","","","","","","","","","","","",}; //stores the coords
std::string tabB[220]={"","","","","","","","","","","","","","","","","","","","",}; //checks if the renderingOrder has already had coords stored in tabA

void iSaveTAXI();
void storeRender();
void checkRender();

//to get coordinates of where a model is at and form hitbox
//(getOBJ sadly slows app execution down dramatically, although using hitbox forming during appropriate times can help stop lag)
void getOBJ()
{

    //open obj file to get x and z coordinates
    int nowA=1, loopA=0, loopB=1, loopC, loopD=0, loopE;
    double top, sideA, sideB, sideC, sideD, bottom;
    double storedA, storedB, storedC, storedD, storedE, storedF;
    double averageY, volumeA;
    pathA=("");
    pathM=("");

    //get 'obj' file from taxi log 'md2' file
    std::ostringstream readO;
    std::string mainA;
    int readI=1;
    int readS;
    std::ifstream readA;
    readA.open("../Variable/log.txt");
    while(getline(readA, mainA))
    {

        readS=mainA.size();
        for(int l=0; l<=readS; l++)
        {

            if(mainA[l]==(','))
            {

                readI+=1;
            }

            if(readI==2)
            {

                readO<<mainA[l];
            }
        }

    }
    readA.close();

    std::ostringstream pathB;
    int runA=1;
    pathM=readO.str();
    int readMS=pathM.size();
    for(int u=1; u<=readMS; u++)
    {

        if(pathM[u]==('.') && pathM[u+1]==('m') && pathM[u+2]==('d') && pathM[u+3]==('2'))
        {

            runA=2;
        }

        if(runA==2)
        {

            pathB<<".txi";
            runA=3;
        }

        if(runA==1)
        {

            pathB<<pathM[u];
        }

        if(runA==1 || runA==2)
        {

        runA=1;
        }
    }
    pathA=pathB.str();

    //need 6 points (one for each face)
    std::string processA;
    std::string thingB;
    std::ifstream outFile;
    outFile.open(pathA.c_str());
    //get file statistics
    while(getline(outFile, processA))
    {

    loopA+=1;
    std::ostringstream thingA;
    thingA<<""<<processA<<"\n";
    thingB=thingA.str();
    if(thingB[0]==('v') && thingB[1]==(' '))
    {

    if(loopB==1)
    {

    loopC=loopA;
    loopB=2;
    }

    loopD+=1;
    }
    }
    outFile.close();

    std::string processB;
    std::string lineB;
    loopE=loopD+loopC;
    loopE-=1;
    int roundA=0;
    std::string variableL=("");
    std::ostringstream lineA;
    std::ifstream outFileA;
    outFileA.open(pathA.c_str());
    //read and evaluate coordinates (need 6)
    while(getline(outFileA, processB))
    {

        roundA+=1;
        if(roundA>=loopC && roundA<=loopE)
        {

            lineA<<""<<processB<<"\n";
            std::ostringstream lineCA;
            lineCA<<""<<processB<<"\n";
            std::string lineC;
            lineC=lineCA.str();
            lineB=lineA.str();
            int lineI=lineC.size();

            int checkA=0;
            for(int r=0; r<=lineI; r++)
            {

                if(lineC[r]==(' '))
                {

                    if(checkA==2)
                    {

                        double keepA=storedA;
                        if(nowA==1)
                        {

                        std::istringstream (variableL) >> storedA;
                        nowA=2;
                        }

                        if(nowA==4)
                        {

                        std::istringstream (variableL) >> storedA;

                        if(storedA<=keepA)
                        {

                            if(storedA<=storedF)
                            {

                            storedF=storedA;
                            }
                            storedA=keepA;
                        }
                        }

                        variableL=("");
                        checkA=3;
                    }

                       if(checkA==1)
                       {

                           double keepB=storedB;
                           if(nowA==2)
                           {

                           std::istringstream (variableL) >> storedB;
                           nowA=3;
                           }

                        if(nowA==4)
                        {

                        std::istringstream (variableL) >> storedB;

                        if(storedB<=keepB)
                        {

                            if(storedB<=storedD)
                            {

                            storedD=storedB;
                            }
                            storedB=keepB;
                        }
                        }
                           variableL=("");
                           checkA=2;
                       }

                       if(checkA==0)
                       {

                       checkA=1;
                       }
                }

                if(checkA==1 || checkA==2)
                {

                    variableL=variableL+lineC[r];
                }
            }
            int altLineI=1;
            int altLineII=1;
            std::string altLine=("");
            if(lineC[lineI-9]==(' '))
            {

                altLineI=2;
            }

            for(int t=lineI-10; t<lineI; t++)
            {


            if(altLineI==2)
            {

            if(t==lineI-9)
            {

                altLineII=2;
            }
            if(altLineII==1)
            {

            altLine=altLine+lineC[t];
            }
            if(altLineII==2)
            {

            altLineII=1;
            }
            }

            if(altLineI==1)
            {

            altLine=altLine+lineC[t];
            }
            }

            double keepC=storedC;
            if(nowA==4)
            {

            std::istringstream (altLine) >> storedC;

            if(storedC<=keepC)
            {

                if(storedC<=storedE)
                {

                storedE=storedC;
                }
                storedC=keepC;
            }
            }

            if(nowA==3)
            {

            std::istringstream (altLine) >> storedC;
            nowA=4;
            }
        }
    }
    outFileA.close();

    top=storedA;
    sideA=storedB;
    sideB=storedC;
    sideC=storedD;
    sideD=storedE;
    bottom=storedF;

    averageY=top+bottom;
    averageY=averageY/2;

    double volumeX;
    double volumeY;
    double volumeZ;

    volumeX=sideA-sideC;
    volumeY=top-bottom;
    volumeZ=sideB-sideD;

    volumeA=volumeX*volumeY;
    volumeA=volumeA*volumeZ;
    volumeA=volumeA/25;

    coordX1=sideA;
    coordZ1=sideB;
    coordX2=sideC;
    coordZ2=sideD;

    coordX1+=xLS;
    coordZ1+=zLS;
    coordX2+=xLS;
    coordZ2+=zLS;

    if(interestH==2)
    {

    storeRender();
    }

    borderTAXI();
}

void iSaveTAXI()
{

    interestT=1;
    if(interestH==2)
    {

    checkRender(); //check tabB;
    }
    if(interestT==1)
    {
    endT=0;
    std::ostringstream fullI;
    if(dataM==2)
    {
    //Model
    fullI<<""<<renderOrder<<","<<modelPS<<","<<texturePS<<","<<xLS<<","<<yLS<<","<<zLS<<",Model";
    }

    if(dataM==3)
    {
    //Room
    fullI<<""<<renderOrder<<","<<modelPS<<","<<texturePS<<","<<xLS<<","<<yLS<<","<<zLS<<",Room";
    }

    if(dataM==4 || dataM==5)
    {
    //Image
    fullI<<""<<renderOrder<<",../Variable/image.md2,"<<imageNS<<","<<freeIS<<","<<xLS<<","<<yLS<<","<<zLS<<",Image";
    }

    std::string lookA, lookB;
    std::ifstream inFile;
    std::ofstream innFile;
    inFile.open("../Variable/log.txt");
    innFile.open("../Variable/list.txt");
    while(getline(inFile, lookA))
    {

        if(endT==endS-1)
        {

        std::ostringstream sawAS;
        std::string sawA, sawB;
        sawA=lookA;
        sawAS<< sawA;
        innFile<<""<<sawAS.str()<<"\n";
        }
        endT+=1;
    }
    inFile.close();
    innFile.close();

    //copy and paste the lines from list.txt to log.txt
    std::ifstream backFile;
    std::ofstream frontFile;
    backFile.open("../Variable/list.txt");
    frontFile.open("../Variable/log.txt");
    while(getline(backFile, lookB))
    {

    std::ostringstream sawBS;
    sawBS<<""<<lookB<<"";
    frontFile<<""<<sawBS.str()<<"\n";
    }
    backFile.close();
    frontFile<<""<<fullI.str()<<"\n";
    frontFile.close();
    if(dataM==2 || dataM==3 || dataM==4)
    {

    getOBJ();
    }
    endS+=1;
    }
}

void storeRender()
{

    int refreshA;
    int refreshB=0;
    int refreshC;
    int scanA=1;
    while(refreshC<=refreshA+6)
    {

    if(scanA==1)
    {

    refreshC=refreshA;
    scanA=2;
    }
    refreshA=renderOrder;
    refreshA=refreshA*6;
    refreshA=refreshA-6;
    refreshA=refreshA+refreshB;
    std::ostringstream convertE;
    if(refreshB==0)
    {

    convertE<<coordX1;
    tabA[refreshA]=convertE.str();
    }
    if(refreshB==1)
    {

    convertE<<coordZ1;
    tabA[refreshA]=convertE.str();
    }
    if(refreshB==2)
    {

    convertE<<coordX2;
    tabA[refreshA]=convertE.str();
    }
    if(refreshB==3)
    {

    convertE<<coordZ2;
    tabA[refreshA]=convertE.str();
    }
    if(refreshB==4)
    {

    convertE<<top;
    tabA[refreshA]=convertE.str();
    }
    if(refreshB==5)
    {

    convertE<<bottom;
    tabA[refreshA]=convertE.str();
    }
    refreshA=refreshA-refreshB;
    refreshB+=1;
    refreshC+=1;
    }
}

void checkRender()
{

    std::ostringstream renderOrderC;
    renderOrderC<<renderOrder;
    if(tabB[renderOrder]==renderOrderC.str())
    {

        interestT=2;
    }

    if(interestT==2)
    {

       int refreshAA;
       int refreshBB=0;
       int refreshCC;
       int scanAA=1;
       while(refreshCC<=refreshAA+6)
       {

        if(scanAA==1)
        {

        refreshCC=refreshAA;
        scanAA=2;
        }
        refreshAA=renderOrder;
        refreshAA=refreshAA*6;
        refreshAA=refreshAA-6;
        refreshAA=refreshAA+refreshBB;
        if(refreshBB==0)
        {

        std::istringstream (tabA[refreshAA]) >> coordX1;
        }
        if(refreshBB==1)
        {

        std::istringstream (tabA[refreshAA]) >> coordZ1;
        }
        if(refreshBB==2)
        {

        std::istringstream (tabA[refreshAA]) >> coordX2;
        }
        if(refreshBB==3)
        {

        std::istringstream (tabA[refreshAA]) >> coordZ2;
        }
        if(refreshBB==4)
        {

        std::istringstream (tabA[refreshAA]) >> top;
        }
        if(refreshBB==5)
        {

        std::istringstream (tabA[refreshAA]) >> bottom;
        }
        refreshAA=refreshAA-refreshBB;
        refreshBB+=1;
        refreshCC+=1;
       }

       borderTAXI();
    }

    if(interestT==1 || interestT==2)
    {

        tabB[renderOrder]=renderOrderC.str();
    }
}
