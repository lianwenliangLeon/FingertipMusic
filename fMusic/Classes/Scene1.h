#pragma once

#include"staveClass.h"
#include "cocos2d.h"
#include"cocos-ext.h"
#include"Box2D/Box2D.h"// Please pay attention to the txt 1.
#include"SimpleAudioEngine.h"
#include"SceneFather.h"
#ifndef __Scene1__
#define __Scene1__

#define GROUND__HIGHT 400

USING_NS_CC_EXT;
USING_NS_CC;
using namespace CocosDenshion;

extern int operateType;

/*
The first scene
*/

class Scene1 : public SceneFather
{
private:
	Sprite * groundUp, *groundDown, *treeL1, *treeL2;
	void settingAction();
	int operateIndex = 1;
public:
	CREATE_FUNC(Scene1);
	bool init();
	void initWorld();
	void initVoice();
	void initSprite();
	//void initListener();
	void update(float dt);

	//Block need change to a array
	Sprite * testBlock;
	void BlockSet();


	//Test end
};

#endif // !__Scene1__
