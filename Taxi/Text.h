#ifndef _Text_INCLUDE
#define _Text_INCLUDE

extern vl::ref<vl::Text> text;
extern vl::ref<vl::Effect> effectT;
extern int menuC, menuP, showA, videoV, timerX;
extern double videoP;

void dialogTAXI(int sizeF, std::string fileNF, std::string fileNT, std::string colorD, std::string spotT, std::string centerT);
void videoTAXI(std::string folderW, int minF, int maxF, bool autoS, bool loopM, int timerV);
void loadI();
void menuTAXI(std::string folderM);
void editMenu();

#endif
