#include"Scene1.h"

bool Scene1::init()
{
	Scene::init();

	winSize = Director::getInstance()->getVisibleSize();

	roleRun();
	initSprite();
	initWorld();
	initBackGround();
	initVoice();
	settingAction();
	
	operateType = operateIndex;

	schedule(schedule_selector(Scene1::update), 0.05f);

	//Test
	testBlockSet();
	//Test end

	return true;
}

void Scene1::initWorld()//initialize world
{
	world = new b2World(b2Vec2(0, -9.8f));
	world->SetContactListener(this);
}

void Scene1::initBackGround()
{
	Size groundUpSize = groundUp->getContentSize();
	Size groundDownSize = groundDown->getContentSize();
	
	groundDown->setPosition(Vec2(winSize.width/2,groundDownSize.height/2));
	groundUp->setPosition(Vec2(winSize.width / 2, groundDownSize.height + groundUpSize.height / 2));
	addChild(groundUp, -1);
	addChild(groundDown, 1);
	
	treeL1->setPosition(Vec2(400, groundDown->getContentSize().height - 20));
	addChild(treeL1); //set render order
	treeL2->setPosition(Vec2(700, 500));
	addChild(treeL2);

	stave->setPosition(Vec2(717,188));
	addChild(stave, 2);
}

void Scene1::initVoice()
{
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music\\scene1.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music\\scene1.mp3", false);
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
}

void Scene1::initSprite()
{
	groundUp = Sprite::create("scene 1 chapter up.png");
	groundDown = Sprite::create("scene 1 chapter down.png");
	treeL1=Sprite::create("tree1.png");//left first
	treeL2 = Sprite::create("tree2.png");
	stave =Stave::create("stave.png",__BASIC__MODEL__);
	
	stave->setCurSprite(ciwei);
}

//test
void Scene1::roleRun()
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
	ciwei->setPosition(Vec2(100, GROUND__HIGHT-30));
	addChild(ciwei, 5);
	ciwei->setAnchorPoint(Vec2(1, 0));

	Animation * animation1 = Animation::createWithSpriteFrames(animFrames1, 0.2);
	ciwei->runAction(RepeatForever::create(Animate::create(animation1)));

	
}

void Scene1::settingAction()
{
	normalC = MoveBy::create(1.0f,Vec2(100, 0));
	
	auto dAction1 = CCScaleTo::create(0.5f, 0.5f, 0.5f);
	auto dAction2 = MoveBy::create(1.0f, Vec2(100, 0));
	auto dAction3 = CCScaleTo::create(0.5f, 1, 1);

	normalD = Sequence::create(dAction1, dAction2, dAction3, NULL);
}

void Scene1::update(float dt)
{
	auto rec1 = ciwei->getBoundingBox();
	auto rec2 = testBlock->getBoundingBox();
	if (rec2.intersectsRect(rec1)) {
		
		auto move = MoveBy::create(0.6f, Vec2(-50, 0));
		auto size = CCScaleTo::create(0.6f, 1, 1);
		


		ciwei->runAction(size);
		ciwei->runAction(move);
	}
}

void Scene1::testBlockSet()
{
	testBlock = Sprite::create("block.png");
	testBlock->setPosition(Vec2(400, GROUND__HIGHT));
	addChild(testBlock,5);
}