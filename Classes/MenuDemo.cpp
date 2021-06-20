/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include "MenuDemo.h"
#include"gameScene.h"
#include "gameScene2.h"



void MenuDemo::enterGameOneCallback(Ref* pSender)
{
	//���Źؿ�����
	float vol = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("gameMusic.mp3", true);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(vol);
	//�滻����Ӧ�ؿ�����
	auto gameScene = gameScene::create();
	Director::getInstance()->replaceScene(gameScene);
}

void MenuDemo::enterGameTwoCallback(Ref* pSender)
{
	float vol = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
	SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("gameMusic.mp3", true);
	SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(vol);
	auto gameScene = gameScene2::create();
	Director::getInstance()->replaceScene(gameScene);
}

bool MenuDemo::init()
{
	if(!Scene::init())
	return false;

	//�����ձ�����
	auto skygroundLayer = Layer::create();
	skygroundLayer->setColor(Color3B::WHITE);
	this->addChild(skygroundLayer);

	//�����ձ���ͼƬ������
	auto sprite1 = Sprite::create("skyBackground.png");
	sprite1->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	sprite1->setPosition(Vec2::ZERO);
	skygroundLayer->addChild(sprite1);
	
	//���ñ�����
	backgroundLayer = Layer::create();
	backgroundLayer->setColor(Color3B::WHITE);
	this->addChild(backgroundLayer);

	//�������ͼ
	sprite = Sprite::create("MenuBackground.png");
	sprite->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	sprite->setPosition(Vec2::ZERO);
	backgroundLayer->addChild(sprite);

	//���������ؿ��İ�ťͨ��
	auto entryItem1 = MenuItemImage::create(
		"entryNormal.png",
		"entry.png",
		CC_CALLBACK_1(MenuDemo::enterGameOneCallback, this));

	auto entryItem2 = MenuItemImage::create(
		"entryNormal.png",
		"entry.png",
		CC_CALLBACK_1(MenuDemo::enterGameTwoCallback, this));

	entryItem1->setPosition(Vec2(230, 415));
	entryItem2->setPosition(Vec2(360, 470));

	//��������ť�����˵�
	auto menu = Menu::create(entryItem1, entryItem2, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
	
	uiSharedLayer::getInstance()->createLayer();
	this->addChild(uiSharedLayer::getInstance());
	
	return true;
}


