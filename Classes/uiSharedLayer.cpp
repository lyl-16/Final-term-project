/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include "uiSharedLayer.h"

uiSharedLayer* uiSharedLayer::instance = nullptr;
void uiSharedLayer::createLayer()
{
	instance = uiSharedLayer::create();
	
}

bool uiSharedLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	//��ȡ��ǰ������С
	float volume = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();

	//��������ͼ�꾫��
	auto musicSprite = Sprite::create("musicSprite.png");
	musicSprite->setPosition(Vec2(470, 660));
	musicSprite->setScale(0.5f);
	this->addChild(musicSprite);

	//��������������
	musicSlider = Slider::create();
	this->addChild(musicSlider);

	musicSlider->setPosition(Vec2(470, 640));
	musicSlider->setScale(0.7f);
	musicSlider->loadBarTexture("lightingBottom.png");
	musicSlider->loadProgressBarTexture("lightingBar.png");
	musicSlider->loadSlidBallTextures("musicControllerThumb.png", "musicControllerThumb.png", "musicControllerThumb.png");
	musicSlider->setPercent((int)(volume * 100));
	musicSlider->addEventListener(CC_CALLBACK_2(uiSharedLayer::sliderCallback, this));

	//�����رհ�ť
	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(uiSharedLayer::menuCloseCallback, this));

	closeItem->setPosition(Vec2(500, 30));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	return true;
}

void uiSharedLayer::sliderCallback(Ref* pSender, Slider::EventType type)
{
	if (type == Slider::EventType::ON_PERCENTAGE_CHANGED)
	{
		int volume = musicSlider->getPercent();
		SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume / 100.0f);
	}
}

uiSharedLayer* uiSharedLayer::getInstance()
{
	if (!instance)
	{
		instance = new uiSharedLayer();
	}
	return instance;
}

void uiSharedLayer::destroyInstance()
{
	if (instance)
	{
		delete instance;
		instance = nullptr;
	}
	return;
}

void uiSharedLayer::menuCloseCallback(cocos2d::Ref* pSender)
{
	Director::getInstance()->end();
}


