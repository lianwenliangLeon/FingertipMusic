#pragma once
#ifndef __mainScreen__
#define __mainScreen__

#include "cocos2d.h"
#include"cocos-ext.h"
#include"SimpleAudioEngine.h"

USING_NS_CC_EXT;
USING_NS_CC;
using namespace CocosDenshion;

class mainScene : public Scene
{
private:
	
	Size winSize;
	bool voiceCon;//1 open 0 close
public:
	CREATE_FUNC(mainScene);
	bool init();
	void initWorld(mainScene *);
	void enterAdventure(Ref* pSender);
	void enterCreate(Ref* pSender);
	void exitLis(Ref * pSender);
	void initMusic();
	void voiceOC(Ref * pSender);//OPEN CLOSE
};

#endif