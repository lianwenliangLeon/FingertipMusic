#pragma once
#ifndef _Stave_Class
#define _Stave_Class

#include"cocos2d.h"
#include"cocos-ext.h"
//#include"Sprite_Action.h"
#include "Synth.h"


USING_NS_CC;
USING_NS_CC_EXT;

#define __NOTE__FONTSIZE__ 50

#define __BASIC__MODEL__DISTANCE__ 159 
#define __BASIC__MODEL__Y -34
#define __BASIC__MODEL__DOBUTTON__X -81

#define __BASIC__MODEL__ 1

#define STAVE_NOTE_DISTANCE 80
#define STAVE_NOTE_DEFAULT_X 5
#define CP_DEPTH 77
#define DP_DEPTH 92
#define EP_DEPTH 107
#define FP_DEPTH 122
#define GP_DEPTH 137
#define AP_DEPTH 152
#define BP_DEPTH 167

#define PAGE_VOLUME 12

enum note{z=-1,c=0,d=1,e=2,f=3,g=4,a=5,b=6};//z equal none

extern int operateType;

class Stave : public Sprite
{
private:
	cocos2d::Sprite * curSpr;
	cocos2d::ui::Button * buttonLeft, *buttonRight;
	cocos2d::ui::Button * cP,* dP,* eP,* fP,* gP,* aP,* bP;// 1 2 3 4 5 6 7
	int Arr[1000 + 5];//display music point
	int index;//pages number
	cocos2d::ui::Button * runBut;
	cocos2d::MenuItemImage * staveNote[PAGE_VOLUME];
	// yjp
	MySynth synth;
	// yjp
	bool initButton();
	bool initBackground();
	bool noteInit(int model);
	bool initPram();
	bool isInit();
	bool initStaveNote();
	bool initListener();
	
public:
	//CREATE_FUNC(Stave);
	bool init(int model);
	static Stave * create(const std::string & filename,int model);//CREATE_FUNC rewrite /  mode
	void updateStave();
	cocos2d::ui::Button * getcP() {
		return cP;
	}
	cocos2d::ui::Button * getdP() {
		return dP;
	}
	cocos2d::ui::Button * geteP() {
		return eP;
	}
	 void setCurSprite(cocos2d::Sprite * s)
	{
		curSpr = s;
	}
	 Sprite * getCurSprite()
	 {
		 return curSpr;
	 }
};


#endif // !_Stave_Class
