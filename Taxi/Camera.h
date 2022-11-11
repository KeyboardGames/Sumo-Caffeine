#ifndef _Camera_INCLUDE
#define _Camera_INCLUDE

#include <vlGraphics/Applet.hpp>
#include <vlGraphics/RenderingTree.hpp>
#include <vlGraphics/SceneManager.hpp>

extern vl::ref<vl::TrackballManipulator> trackball;
extern vl::ref<vl::SceneManagerActorTree> scene_manager;
extern vl::ref<vl::Transform> tr1A;
extern vl::ref<vl::Transform> tr2A;
extern vl::ref<vl::RenderingTree> mRenderingTree;
extern vl::ref<vl::Rendering> mRendering0;
extern vl::ref<vl::Rendering> mRendering1;
extern bool timerTAXI;
extern int timR;
extern double xC, yC, zC;
extern double xMC1, yMC1, zMC1, xMC2, yMC2, zMC2;

void cameraTAXI();
void borderTAXI();
void addCameraTAXI();
void multiCameraTAXI();
void updateMultiCameraTAXI();
void setTimerTAXI(int timM, int timF, int switchT);
void debugTAXI();
void freshTAXI();

#endif
