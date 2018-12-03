#include"mainScreen.h"
#include"Scene1.h"
#include"checkpointscreen.h"

bool mainScene::init() {
	Scene::init();
	winSize = Director::getInstance()->getVisibleSize();

	initMusic();
	initWorld(this);//default screen

	voiceCon = 1;

	return true;
}

void mainScene::initMusic()
{
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music\\enterMusic.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music\\enterMusic.mp3", true);
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

void mainScene::initWorld(mainScene * scene) {
	Sprite * grounds=Sprite::create("ground1.jpg");
	Size groundSize = grounds->getContentSize();
	grounds->setPosition(Vec2(winSize.width / 2, winSize.height/2));
	addChild(grounds);

	auto adventureBut = MenuItemImage::create("adventureBut.png", "adventureButCho.png", CC_CALLBACK_1(mainScene::enterAdventure,this));

	if (adventureBut == nullptr)
	{
		problemLoading("'adventureBut.png'");
	}

	adventureBut->setPosition(720, 440);


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
	

	auto voiceBut = MenuItemImage::create("voice open.png", "voice close.png", CC_CALLBACK_1(mainScene::voiceOC, this));

	if (voiceBut == nullptr)
	{
		problemLoading("'voice open.png , voice close.png'");
	}

	voiceBut->setPosition(100, 800);

	auto menu = Menu::create(adventureBut, NULL);
	menu->addChild(createBut);
	menu->addChild(exitBut);
	menu->addChild(voiceBut);
	menu->setPosition(Vec2::ZERO);
	scene->addChild(menu, 4);
}

void mainScene::enterAdventure(Ref * pSender)
{
	SimpleAudioEngine::sharedEngine()->stopBackgroundMusic(true);
	auto scene = checkpointScene::create();
	Director::getInstance()->replaceScene(TransitionFade::create(2, scene)); 
}

void mainScene::enterCreate(Ref * pSender)
{

}

void mainScene::exitLis(Ref * pSender)
{
	Director::getInstance()->end();
	exit(0);
}

void mainScene::voiceOC(Ref * pSender)
{
	if (voiceCon)
	{
		SimpleAudioEngine::sharedEngine()->stopBackgroundMusic();
	}
	else
		SimpleAudioEngine::sharedEngine()->rewindBackgroundMusic();

	voiceCon = 1 - voiceCon;
}