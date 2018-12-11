#include"Scene1.h"

bool Scene1::init()
{
	if (!Scene::initWithPhysics())
		return false;

	//PhysicsWorld::step(1.0/ 120);

	winSize = Director::getInstance()->getVisibleSize();

	initSprite();
	initWorld();
	initVoice();
	settingAction();
	
	operateType = operateIndex;

	schedule(schedule_selector(Scene1::update), 0.05f);

	//Test
	BlockSet();
	//Test end

	return true;
}

void Scene1::initWorld()//initialize world
{
	world = new b2World(b2Vec2(0, -9.8f));
	world->SetContactListener(this);
}

void Scene1::initVoice()
{
	SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic("music\\scene1.mp3");
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music\\scene1.mp3", false);
	SimpleAudioEngine::sharedEngine()->setBackgroundMusicVolume(0.5);
}

void Scene1::initSprite()
{
	//ciwei 
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

	auto physicsBody = PhysicsBody::createBox(Size(50, 65));
	physicsBody->setDynamic(true);
	ciwei->addComponent(physicsBody);

	Animation * animation1 = Animation::createWithSpriteFrames(animFrames1, 0.2);
	ciwei->runAction(RepeatForever::create(Animate::create(animation1)));

	groundUp = Sprite::create("scene 1 chapter up.png");
	groundDown = Sprite::create("scene 1 chapter down.png");
	treeL1 = Sprite::create("tree1.png");//left first
	treeL2 = Sprite::create("tree2.png");
	stave = Stave::create("stave.png", __BASIC__MODEL__);

	stave->setCurSprite(ciwei);


	// groundback
	Size groundUpSize = groundUp->getContentSize();
	Size groundDownSize = groundDown->getContentSize();

	groundDown->setPosition(Vec2(winSize.width / 2, groundDownSize.height / 2));
	groundUp->setPosition(Vec2(winSize.width / 2, groundDownSize.height + groundUpSize.height / 2));
	physicsBody = PhysicsBody::createBox(Size(1440, 372),PhysicsMaterial(100.0f, 1.0f, 0.0f));
	physicsBody->setDynamic(false);
	groundDown->addComponent(physicsBody);


	addChild(groundUp, -1);
	addChild(groundDown, 1);

	treeL1->setPosition(Vec2(400, groundDown->getContentSize().height - 20));
	addChild(treeL1); //set render order
	treeL2->setPosition(Vec2(700, 500));
	addChild(treeL2);

	stave->setPosition(Vec2(717, 188));
	addChild(stave, 2);


	
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

	const int Left = 1;
	const int Right = 2;
	const int up = 3;
	const int under = 4;
	const int non = 0;

	auto director= Director::getInstance();


	auto rec1 = ciwei->getBoundingBox();
	auto rec2 = testBlock->getBoundingBox();

	int res;

	
}

void Scene1::BlockSet()
{
	testBlock = Sprite::create("block.png");
	testBlock->setPosition(Vec2(400, GROUND__HIGHT));

	auto physicsBody = PhysicsBody::createBox(Size(80, 80));
	physicsBody->setDynamic(false);
	testBlock->addComponent(physicsBody);

	addChild(testBlock,5);
}