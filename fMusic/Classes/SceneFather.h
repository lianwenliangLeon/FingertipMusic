#pragma once

#include"staveClass.h"
#include "cocos2d.h"
#include"cocos-ext.h"
#include"Box2D/Box2D.h"// Please pay attention to the txt 1.
#include"SimpleAudioEngine.h"

extern Action * normalC;
extern Action * normalD;
extern Action * normalE;
extern Action * normalF;
extern Action * normalG;
extern Action * normalA;
extern Action * normalB;

#ifndef __SceneFather__
#define __SceneFather__

USING_NS_CC_EXT;
USING_NS_CC;
using namespace CocosDenshion;

/*
The first scene
*/

class SceneFather : public Scene, public b2ContactListener
{
protected:
	Size winSize;
	b2World * world;
	Stave * stave;
	Sprite *ciwei;
private:
public:
	virtual void settingAction();
};

#endif // !__SceneFather__
