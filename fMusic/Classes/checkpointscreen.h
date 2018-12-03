#pragma once

#ifndef __checkpointscreen__
#define __checkpointscreen__

#include"Scene1.h"
#include "cocos2d.h"
#include"cocos-ext.h"

USING_NS_CC_EXT;
USING_NS_CC;

class checkpointScene : public Scene
{
private:
	Size winSize;
public:
	CREATE_FUNC(checkpointScene);
	bool init();
	void initWorld(checkpointScene *);
	void enterAdventure_1_1(Ref* pSender);
	void enterAdventure_1_2(Ref* pSender);
	void enterAdventure_1_3(Ref* pSender);
	void enterAdventure_1_4(Ref* pSender);
	void enterAdventure_1_5(Ref* pSender);
	void enterAdventure_1_6(Ref* pSender);
	void enterAdventure_1_7(Ref* pSender);
	void enterAdventure_1_8(Ref* pSender);
	void enterAdventure_1_9(Ref* pSender);
};

#endif