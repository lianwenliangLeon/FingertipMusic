#pragma once
#ifndef _Stave_Class
#define _Stave_Class

#include"cocos2d.h"
#include"cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

class Stave : public Sprite
{
private:
	cocos2d::ui::Button * buttonLeft, *buttonRight;
public:
	static Stave * createStave();
	bool init();
	CREATE_FUNC(createStave);
};


#endif // !_Stave_Class
