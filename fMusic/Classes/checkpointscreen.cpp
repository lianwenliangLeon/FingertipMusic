#include"checkpointscreen.h"
#include "Scene2.h"

#include<iostream>

bool checkpointScene::init() {
	Scene::init();
	winSize = Director::getInstance()->getVisibleSize();
	initWorld(this);

	return true;
}

//Ӧ���Ǻ;����йصĺ���
static void problemLoading(const char* filename)//����Ҳ�֪����ʲô���ͻ�û�м�
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void checkpointScene::initWorld(checkpointScene * scene) {
	Sprite * grounds = Sprite::create("ground1.jpg");//����ͼƬ
	Size groundSize = grounds->getContentSize();
	grounds->setPosition(Vec2(winSize.width / 2, winSize.height / 2));
	addChild(grounds);//����һ�����ӣ����ӽڵ�

	//��һ���ؿ�ͼ����һ��ͼƬ�ǳ�ʼ������ڶ���ͼ�ǵ��֮������
	auto checkpointbut1 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_1, this));
	if (checkpointbut1 == nullptr)//�����Ƿ����ĺ���
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut1->setPosition(320, 680);//������ʾ��λ��

	auto checkpointbut2 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_2, this));
	if (checkpointbut2 == nullptr)//�����Ƿ����ĺ���
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut2->setPosition(720, 680);//������ʾ��λ��

	auto checkpointbut3 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_3, this));
	if (checkpointbut3 == nullptr)//�����Ƿ����ĺ���
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut3->setPosition(1120, 680);//������ʾ��λ��

	auto checkpointbut4 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_4, this));
	if (checkpointbut4 == nullptr)//�����Ƿ����ĺ���
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut4->setPosition(320, 450);//������ʾ��λ��

	auto checkpointbut5 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_5, this));
	if (checkpointbut5 == nullptr)//�����Ƿ����ĺ���
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut5->setPosition(720, 450);//������ʾ��λ��

	auto checkpointbut6 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_6, this));
	if (checkpointbut6 == nullptr)//�����Ƿ����ĺ���
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut6->setPosition(1120, 450);//������ʾ��λ��

	auto checkpointbut7 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_7, this));
	if (checkpointbut7 == nullptr)//�����Ƿ����ĺ���
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut7->setPosition(320, 220);//������ʾ��λ��

	auto checkpointbut8 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_8, this));
	if (checkpointbut8 == nullptr)//�����Ƿ����ĺ���
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut8->setPosition(720, 220);//������ʾ��λ��

	auto checkpointbut9 = MenuItemImage::create("un_checkpoint.png", "un_checkpointcho.png", CC_CALLBACK_1(checkpointScene::enterAdventure_1_9, this));
	if (checkpointbut9 == nullptr)//�����Ƿ����ĺ���
	{
		problemLoading("'un_checkpoint.png'");
	}

	checkpointbut9->setPosition(1120, 220);//������ʾ��λ��
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

	//auto�Զ�ƥ������
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

	//������һ��û��Ū������ʲô��˼
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