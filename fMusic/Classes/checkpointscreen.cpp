#include"checkpointscreen.h"
#include "Scene2.h"

#include<iostream>

bool checkpointScene::init() {
	Scene::init();
	winSize = Director::getInstance()->getVisibleSize();
	initWorld(this);

	return true;
}

//应该是和纠错有关的函数
static void problemLoading(const char* filename)//这个我不知道是什么，就还没有加
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void checkpointScene::initWorld(checkpointScene * scene) {
	Sprite * grounds = Sprite::create("ground1.jpg");//背景图片
	Size groundSize = grounds->getContentSize();
	grounds->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	addChild(grounds);//增加一个儿子，放子节点

	//放一个关卡图，第一张图片是初始情况，第二张图是点击之后的情况
	auto checkpointbut1 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_1, this));
	if (checkpointbut1 == nullptr)//检验是否错误的函数
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut1->setPosition(320, 680);//设置显示的位置

	auto checkpointbut2 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_2, this));
	if (checkpointbut2 == nullptr)//检验是否错误的函数
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut2->setPosition(720, 680);//设置显示的位置

	auto checkpointbut3 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_3, this));
	if (checkpointbut3 == nullptr)//检验是否错误的函数
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut3->setPosition(1120, 680);//设置显示的位置

	auto checkpointbut4 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_4, this));
	if (checkpointbut4 == nullptr)//检验是否错误的函数
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut4->setPosition(320, 450);//设置显示的位置

	auto checkpointbut5 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_5, this));
	if (checkpointbut5 == nullptr)//检验是否错误的函数
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut5->setPosition(720, 450);//设置显示的位置

	auto checkpointbut6 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_6, this));
	if (checkpointbut6 == nullptr)//检验是否错误的函数
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut6->setPosition(1120, 450);//设置显示的位置

	auto checkpointbut7 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_7, this));
	if (checkpointbut7 == nullptr)//检验是否错误的函数
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut7->setPosition(320, 220);//设置显示的位置

	auto checkpointbut8 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_8, this));
	if (checkpointbut8 == nullptr)//检验是否错误的函数
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut8->setPosition(720, 220);//设置显示的位置

	auto checkpointbut9 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_9, this));
	if (checkpointbut9 == nullptr)//检验是否错误的函数
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut9->setPosition(1120, 220);//设置显示的位置
	/*
	auto createBut = MenuItemImage::create("createBut.png", "createButCho.png", CC_CALLBACK_1(mainScene::enterCreate, this));

	if (createBut == nullptr)
	{
		problemLoading("'createBut.png'");
	}

	createBut->setPosition(720, 270);




	auto exitBut = MenuItemImage::create("exitBut.png", "exitButCho.png", CC_CALLBACK_1(mainScene::exitLis, this));

	if (exitBut == nullptr)
	{
		problemLoading("'exitBut.png'");
	}

	exitBut->setPosition(720, 100);

	*/

	//auto自动匹配类型
	auto menu = Menu::create(checkpointbut1, NULL);
	menu->addChild(checkpointbut2);
	menu->addChild(checkpointbut3);
	menu->addChild(checkpointbut4);
	menu->addChild(checkpointbut5);
	menu->addChild(checkpointbut6);
	menu->addChild(checkpointbut7);
	menu->addChild(checkpointbut8);
	menu->addChild(checkpointbut9);
	//menu->addChild(createBut);
	//menu->addChild(exitBut);

	//下面这一句没有弄明天是什么意思
	menu->setPosition(Vec2::ZERO);
	scene->addChild(menu, 9);
}

void checkpointScene::enterAdventure_1_1(Ref * pSender)
{
	auto scene = Scene1::create();
	Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
}

void checkpointScene::enterAdventure_1_2(Ref * pSender)
{
	auto scene = Scene2::create();
	Director::getInstance()->replaceScene(TransitionFade::create(2, scene));
}

void checkpointScene::enterAdventure_1_3(Ref * pSender)
{
	pSender;
}

void checkpointScene::enterAdventure_1_4(Ref * pSender)
{
	pSender;
}

void checkpointScene::enterAdventure_1_5(Ref * pSender)
{
	pSender;
}

void checkpointScene::enterAdventure_1_6(Ref * pSender)
{
	pSender;
}

void checkpointScene::enterAdventure_1_7(Ref * pSender)
{
	pSender;
}

void checkpointScene::enterAdventure_1_8(Ref * pSender)
{
	pSender;
}

void checkpointScene::enterAdventure_1_9(Ref * pSender)
{
	pSender;
}