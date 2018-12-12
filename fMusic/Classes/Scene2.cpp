#include"Scene2.h"

bool Scene2::init()
{
	Scene::init();

	winSize = Director::getInstance()->getVisibleSize();

	roleRun();
	initSprite();
	initWorld();
	initBackGround();
	// initVoice();
	settingAction();

	operateType = operateIndex;

	scheduleUpdate();

	//Test
	testBlockSet();

	//Test end

	return true;
}

void Scene2::initWorld()//initialize world
{
	world = new b2World(b2Vec2(0, -9.8f));
	world->SetContactListener(this);
}

void Scene2::initBackGround()
{
	Size groundUpSize = groundUp->getContentSize();
	Size groundDownSize = groundDown->getContentSize();

	groundDown->setPosition(Vec2(winSize.width / 2, groundDownSize.height / 2));
	groundUp->setPosition(Vec2(winSize.width / 2, groundDownSize.height + groundUpSize.height / 2));
	addChild(groundUp, -1);
	addChild(groundDown, 1);

	treeL1->setPosition(Vec2(400, groundDown->getContentSize().height - 20));
	addChild(treeL1); //set render order
	treeL2->setPosition(Vec2(700, 500));
	addChild(treeL2);

	stave->setPosition(Vec2(717, 188));
	addChild(stave, 2);
}

void Scene2::initVoice()
{
	SimpleAudioEngine::getInstance()->preloadBackgroundMusic("music\\START-DASH.mid");
	SimpleAudioEngine::getInstance()->playBackgroundMusic("music\\START-DASH.mid", false);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5);
}

void Scene2::initSprite()
{
	groundUp = Sprite::create("scene 1 chapter up.png");
	groundDown = Sprite::create("scene 1 chapter down.png");
	treeL1 = Sprite::create("tree1.png");//left first
	treeL2 = Sprite::create("tree2.png");
	stave = Stave::create("stave.png", __BASIC__MODEL__);

	stave->setCurSprite(ciwei);
}

//test
void Scene2::roleRun()
{
	SpriteFrameCache * cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile("ciwei.plist");
	Vector <SpriteFrame *> animFrames1;
	char str1[1000] = { 0 };
	for (int i = 0; i < 4; i++)
	{
		sprintf(str1, "ciwei%d.png", i);
		SpriteFrame * pFrame = cache->getSpriteFrameByName(str1);
		animFrames1.pushBack(pFrame);
	}
	Size s = Director::getInstance()->getVisibleSize();
	ciwei = Sprite::createWithSpriteFrameName("ciwei0.png");
	ciwei->setPosition(Vec2(100, GROUND__HIGHT - 30));
	addChild(ciwei, 5);
	ciwei->setAnchorPoint(Vec2(1, 0));

	Animation * animation1 = Animation::createWithSpriteFrames(animFrames1, 0.2);
	ciwei->runAction(RepeatForever::create(Animate::create(animation1)));


}

void Scene2::settingAction()
{
	normalC = MoveBy::create(1.0f, Vec2(100, 0));

	auto dAction1 = CCScaleTo::create(0.5f, 0.5f, 0.5f);
	auto dAction2 = MoveBy::create(1.0f, Vec2(100, 0));
	auto dAction3 = CCScaleTo::create(0.5f, 1, 1);

	normalD = Sequence::create(dAction1, dAction2, dAction3, NULL);
}

void Scene2::update(float dt)
{

	const int Left = 1;
	const int Right = 2;
	const int up = 3;
	const int under = 4;
	const int non = 0;

	auto director = Director::getInstance();


	auto rec1 = ciwei->getBoundingBox();
	// auto rec2 = testBlock->getBoundingBox();

	// int res = rec2.intersectsRect(rec1);

	for (auto &block : testBlock) {
		if (block->getBoundingBox().intersectsRect(rec1)) {
			director->getActionManager()->pauseTarget(ciwei);


			auto move = MoveBy::create(0.6f, Vec2(-50, 0));
			// auto size = CCScaleTo::create(0.6f, 1, 1);

			// ciwei->runAction(size);//none conflict £¿
			ciwei->runAction(move);//none conflict £¿

			director->getActionManager()->resumeTarget(ciwei);
		}
	}
}

void Scene2::testBlockSet()
{
	for (int i = 0; i < 5; ++i) {
		testBlock.push_back(Sprite::create("block.png"));
		testBlock.back()->setPosition(Vec2(400 + i * 200, GROUND__HIGHT + 45));
		addChild(testBlock.back(), 5);
	}
}