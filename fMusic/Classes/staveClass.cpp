#include"staveClass.h"

bool Stave::init(int model)
{
	if (!initPram())
	{

	}
	if (!initButton())
		return false;
	if (!initBackground())
		return false;
	if (!noteInit(model))
		return false;
	if (!initStaveNote())
		return false;
	if (!initListener())
		return false;

	return true;
}

bool Stave::isInit()
{
	if (!Sprite::init())
	{
		return false;
	}
	
	return true;
}

Stave * Stave::create(const std::string& filename,int model)
{
	Stave * pRet = new Stave();
	if (pRet&&pRet->initWithFile(filename) && pRet->init(model))
	{
		pRet->autorelease();
		return pRet;
	}

	delete pRet;
	pRet = NULL;
	return NULL;
}

bool Stave::initButton()
{
	buttonLeft = cocos2d::ui::Button::create();
	buttonRight = cocos2d::ui::Button::create();
	runBut = cocos2d::ui::Button::create();

	if ((!buttonRight) || (!buttonLeft)||(!runBut))
	{
		return false;
	}

	buttonLeft->loadTextureNormal("Stave_Left.png");
	buttonLeft->loadTexturePressed("Stave_Left_Press.png");
	                                
	buttonRight->loadTextureNormal("Stave_Left.png");
	buttonRight->loadTexturePressed("rightpress.png");

	runBut->loadTextureNormal("run.png");
	runBut->loadTexturePressed("run_choose.png");

	return true;
}

bool Stave::initBackground()
{
	auto buttonLRH = this->getPositionY() + this->getContentSize().height / 2;//left and right button height
	auto staveBorder = this->getPositionX() + this->getContentSize().width;

	buttonLeft->setPosition(Vec2(-46,buttonLRH));
	buttonRight->setPosition(Vec2(staveBorder+46, buttonLRH));
	runBut -> setPosition(Vec2(-70, buttonLRH - 130));

	addChild(buttonLeft);
	addChild(buttonRight);
	addChild(runBut);

	return true;
}

bool Stave::noteInit(int model)
{
	cP = cocos2d::ui::Button::create();
	dP = cocos2d::ui::Button::create();
	eP = cocos2d::ui::Button::create();
	fP = cocos2d::ui::Button::create();
	gP = cocos2d::ui::Button::create();
	aP = cocos2d::ui::Button::create();
	bP = cocos2d::ui::Button::create();

	cP->loadTextureNormal("noteDo.png");
	dP->loadTextureNormal("noteRe.png");
	eP->loadTextureNormal("noteMi.png");
	fP->loadTextureNormal("noteFa.png");
	gP->loadTextureNormal("noteSci.png");
	aP->loadTextureNormal("noteLa.png");
	bP->loadTextureNormal("noteSi.png");

	cP->setTitleText("do");
	dP->setTitleText("re");
	eP->setTitleText("mi");
	fP->setTitleText("fa");
	gP->setTitleText("sci");
	aP->setTitleText("la");
	bP->setTitleText("si");

	cP->setTitleFontSize(__NOTE__FONTSIZE__);
	dP->setTitleFontSize(__NOTE__FONTSIZE__);
	eP->setTitleFontSize(__NOTE__FONTSIZE__);
	fP->setTitleFontSize(__NOTE__FONTSIZE__);
	gP->setTitleFontSize(__NOTE__FONTSIZE__);
	aP->setTitleFontSize(__NOTE__FONTSIZE__);
	bP->setTitleFontSize(__NOTE__FONTSIZE__);

	switch (model)
	{
	case 1:
	{
		int basicX = 717 - this->getContentSize().width / 2;
		cP->setPosition(Vec2(basicX+__BASIC__MODEL__DOBUTTON__X,__BASIC__MODEL__Y));
		dP->setPosition(Vec2(basicX+__BASIC__MODEL__DOBUTTON__X+1*__BASIC__MODEL__DISTANCE__,__BASIC__MODEL__Y));
		eP->setPosition(Vec2(basicX + __BASIC__MODEL__DOBUTTON__X + 2 * __BASIC__MODEL__DISTANCE__, __BASIC__MODEL__Y));
		fP->setPosition(Vec2(basicX + __BASIC__MODEL__DOBUTTON__X + 3 * __BASIC__MODEL__DISTANCE__, __BASIC__MODEL__Y));
		gP->setPosition(Vec2(basicX + __BASIC__MODEL__DOBUTTON__X + 4 * __BASIC__MODEL__DISTANCE__, __BASIC__MODEL__Y));
		aP->setPosition(Vec2(basicX + __BASIC__MODEL__DOBUTTON__X + 5 * __BASIC__MODEL__DISTANCE__, __BASIC__MODEL__Y));
		bP->setPosition(Vec2(basicX + __BASIC__MODEL__DOBUTTON__X + 6 * __BASIC__MODEL__DISTANCE__, __BASIC__MODEL__Y));

		addChild(cP);
		addChild(dP);
		addChild(eP);
		addChild(fP);
		addChild(gP);
		addChild(aP);
		addChild(bP);
	}break;
	default:
		break;
	}

	return true;
}

bool Stave::initPram()
{
	index = 0;
	for (int i = 0; i < 1000; i++)
		Arr[i] = -1;

	return true;
}

void Stave::updateStave()
{
	int start = index * PAGE_VOLUME;
	for (int i = 0; i < PAGE_VOLUME; i++)
	{
		int flag = 1;
		switch (Arr[start+i])
		{
		case z: {
			staveNote[i]->setVisible(false);
		}break;
		case c: {
			int curX,curY;
			int basicX = 717 - this->getContentSize().width / 2;
			curX = basicX + STAVE_NOTE_DEFAULT_X+STAVE_NOTE_DISTANCE*i;
			curY = CP_DEPTH;
			staveNote[i]->setPosition(Vec2(curX, curY));
			staveNote[i]->setVisible(true);
		}break;
		case d: {
			int curX, curY;
			int basicX = 717 - this->getContentSize().width / 2;
			curX = basicX + STAVE_NOTE_DEFAULT_X + STAVE_NOTE_DISTANCE * i;
			curY = DP_DEPTH;
			staveNote[i]->setPosition(Vec2(curX, curY));
			staveNote[i]->setVisible(true);
		}break;
		case e: {
			int curX, curY;
			int basicX = 717 - this->getContentSize().width / 2;
			curX = basicX + STAVE_NOTE_DEFAULT_X + STAVE_NOTE_DISTANCE * i;
			curY = EP_DEPTH;
			staveNote[i]->setPosition(Vec2(curX, curY));
			staveNote[i]->setVisible(true);
		}break;
		case f: {
			int curX, curY;
			int basicX = 717 - this->getContentSize().width / 2;
			curX = basicX + STAVE_NOTE_DEFAULT_X + STAVE_NOTE_DISTANCE * i;
			curY = FP_DEPTH;
			staveNote[i]->setPosition(Vec2(curX, curY));
			staveNote[i]->setVisible(true);
		}break;
		case g: {
			int curX, curY;
			int basicX = 717 - this->getContentSize().width / 2;
			curX = basicX + STAVE_NOTE_DEFAULT_X + STAVE_NOTE_DISTANCE * i;
			curY = GP_DEPTH;
			staveNote[i]->setPosition(Vec2(curX, curY));
			staveNote[i]->setVisible(true);
		}break;
		case a: {
			int curX, curY;
			int basicX = 717 - this->getContentSize().width / 2;
			curX = basicX + STAVE_NOTE_DEFAULT_X + STAVE_NOTE_DISTANCE * i;
			curY = AP_DEPTH;
			staveNote[i]->setPosition(Vec2(curX, curY));
			staveNote[i]->setVisible(true);
		}break;
		case b: {
			int curX, curY;
			int basicX = 717 - this->getContentSize().width / 2;
			curX = basicX + STAVE_NOTE_DEFAULT_X + STAVE_NOTE_DISTANCE * i;
			curY = BP_DEPTH;
			staveNote[i]->setPosition(Vec2(curX, curY));
			staveNote[i]->setVisible(true);
		}break;
		default:
			break;
		}
	}
}

bool Stave::initStaveNote()
{
	for (int i = 0; i < PAGE_VOLUME; i++)
	{
		staveNote[i] = MenuItemImage::create("noteTest.png", "noteTestChoose.png");
		staveNote[i]->setVisible(false);
	}
	auto menu = Menu::create(staveNote[0],NULL);
	for (int i = 1; i < PAGE_VOLUME; i++)
	{
		menu->addChild(staveNote[i]);
	}
	menu->setPosition(Vec2::ZERO);
	addChild(menu, PAGE_VOLUME);

	return true;
}

bool Stave::initListener()
{
	cP->addClickEventListener([&](Ref * ref) {
		int start = index * PAGE_VOLUME;
		int i = 0,flag=0;
		for (; i < PAGE_VOLUME; i++)
		{
			if (Arr[start + i] == -1)
			{
				Arr[start + i] = c;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			index = index + 1;
			Arr[index * PAGE_VOLUME] = c;
		}
		updateStave();
	});

	dP->addClickEventListener([&](Ref * ref) {
		int start = index * PAGE_VOLUME;
		int i = 0, flag = 0;
		for (; i < PAGE_VOLUME; i++)
		{
			if (Arr[start + i] == -1)
			{
				Arr[start + i] = d;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			index = index + 1;
			Arr[index * PAGE_VOLUME] = d;
		}
		updateStave();
	});

	eP->addClickEventListener([&](Ref * ref) {
		int start = index * PAGE_VOLUME;
		int i = 0, flag = 0;
		for (; i < PAGE_VOLUME; i++)
		{
			if (Arr[start + i] == -1)
			{
				Arr[start + i] = e;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			index = index + 1;
			Arr[index * PAGE_VOLUME] = e;
		}
		updateStave();
	});

	fP->addClickEventListener([&](Ref * ref) {
		int start = index * PAGE_VOLUME;
		int i = 0, flag = 0;
		for (; i < PAGE_VOLUME; i++)
		{
			if (Arr[start + i] == -1)
			{
				Arr[start + i] = f;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			index = index + 1;
			Arr[index * PAGE_VOLUME] = f;
		}
		updateStave();
	});

	gP->addClickEventListener([&](Ref * ref) {
		int start = index * PAGE_VOLUME;
		int i = 0, flag = 0;
		for (; i < PAGE_VOLUME; i++)
		{
			if (Arr[start + i] == -1)
			{
				Arr[start + i] = g;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			index = index + 1;
			Arr[index * PAGE_VOLUME] = g;
		}
		updateStave();
	});

	aP->addClickEventListener([&](Ref * ref) {
		int start = index * PAGE_VOLUME;
		int i = 0, flag = 0;
		for (; i < PAGE_VOLUME; i++)
		{
			if (Arr[start + i] == -1)
			{
				Arr[start + i] = a;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			index = index + 1;
			Arr[index * PAGE_VOLUME] = a;
		}
		updateStave();
	});

	bP->addClickEventListener([&](Ref * ref) {
		int start = index * PAGE_VOLUME;
		int i = 0, flag = 0;
		for (; i < PAGE_VOLUME; i++)
		{
			if (Arr[start + i] == -1)
			{
				Arr[start + i] = b;
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			index = index + 1;
			Arr[index * PAGE_VOLUME] = b;
		}
		updateStave();
	});

	buttonLeft->addClickEventListener([&](Ref * ref) {
		if(index)
			index = index - 1;
		updateStave();
	});

	buttonRight->addClickEventListener([&](Ref * ref) {
		if(Arr[index*12+12]!=z)
			index = index + 1;
		updateStave();
	});

	runBut->addClickEventListener([&](Ref * ref) {
		auto ans = Sequence::create(MoveBy::create(0.3f, Vec2(0, 0)) ,NULL);

		switch (operateType)
		{
		case 1: {
			auto cA = MoveBy::create(1.0f, Vec2(50, 0));
			
			auto dA1 = CCScaleBy::create(0.5f, 0.5, 0.5);
			auto dA2 = MoveBy::create(1.0f, Vec2(50, 0));
			auto dA3 = CCScaleBy::create(0.5f, 2, 2);
			auto dA = Sequence::create(dA1,dA2,dA3,NULL);
			

			for (int i = 0; i < 1000; i++)
			{
				switch (Arr[i])
				{
				case c: {
					ans = Sequence::create(ans, cA, NULL);
				}break;
				case d: {
					ans = Sequence::create(ans, dA, NULL);
				}break;
				default:
					break;
				}

				Arr[i] = -1;
			}
		}break;
		default:
			break;
		}
	
		this->getCurSprite()->runAction(ans);
		index = 0;
		updateStave();
	});

	return true;
}