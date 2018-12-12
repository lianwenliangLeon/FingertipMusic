#pragma once

#include "staveClass.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "Box2D/Box2D.h"// Please pay attention to the txt 1.
#include "SimpleAudioEngine.h"
#include "SceneFather.h"
#include <vector>
#ifndef __Scene2__
#define __Scene2__

#define GROUND__HIGHT 400

USING_NS_CC_EXT;
USING_NS_CC;
using namespace CocosDenshion;

extern int operateType;

class Scene2 : public SceneFather
{
private:
	Sprite * groundUp, *groundDown, *treeL1, *treeL2;
	void settingAction();
	int operateIndex = 1;
public:
	CREATE_FUNC(Scene2);
	bool init();
	void initWorld();
	void initBackGround();
	void initVoice();
	void initSprite();
	//void initListener();
	void roleRun();
	void update(float dt);


	//Test
	std::vector<Sprite *> testBlock;
	void testBlockSet();
	//Test end
};

#endif // !__Scene2__
