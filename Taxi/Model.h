#ifndef _Model_INCLUDE
#define _Model_INCLUDE

//P=path
//T=taxi

extern vl::ref<vl::Applet> applet;
extern vl::ref<vl::ResourceDatabase> res_db;
extern vl::ref<vl::Actor> morph_act2;
extern vl::ref<vl::MorphingCallback> morph_cb2;
extern vl::ref<vl::Light> light;
extern vl::ref<vl::Effect> effect;
extern int dataM;
extern int renderOrder;
extern double coordX1, coordX2, coordZ1, coordZ2;
extern double xM, zM;
extern int planeV;

void modelTAXI(std::string modelP, std::string textureP, std::string complexV, bool extraL, double x, double y, double z);
void roomTAXI(std::string modelLP, std::string textureLP, double xL, double yL, double zL);
void moveTAXI(double varX, double varY, double varZ);
void animationTAXI(int limitA, int limitB, float limitS);
void collideTAXI(double locX1, double locX2, double locZ1, double locZ2, double recoilA);
void imageTAXI(std::string imageN, std::string freeI, double xI, double yI, double zI);

#endif
