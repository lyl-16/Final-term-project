/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include "StartDemo.h"
#include "MenuDemo.h"

Scene* StartDemo::createScene()
{
	return StartDemo::create();
}

bool StartDemo::init()
{
	if (!Scene::init())
	{
		return false;
	}

	//���ű�������
	auto audioEngine = SimpleAudioEngine::getInstance();
	audioEngine->playBackgroundMusic("music.mp3", true);
	
	//��������ͼƬ����
	auto sprite = Sprite::create("StartBackGround.png");
	sprite->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	sprite->setPosition(Vec2(Director::getInstance()->getVisibleSize() / 2));
	this->addChild(sprite);

	//��ȡ��������
	auto configData = FileUtils::getInstance()->getValueMapFromFile("XMLFile.xml");
	for (auto valPair : configData)
	{
		int key = atoi(valPair.first.c_str());
		Value val= valPair.second;

		words.insert(std::pair<int, Value>(key, val));
	}

	//�������밴ť
	auto button = Button::create("BeginBottonNormal.png", "BeginBottonSelected.png");
	button->setTitleFontSize(32);
	std::string str = words.at(1001).asString();
	button->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 120));
	this->addChild(button);

	//��ʾ�������ʾ��ǩ
	auto label = Label::createWithSystemFont(str,"��������",32);
	label->setPosition(button->getPosition());
	this->addChild(label);

	button->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
		{
			auto menuScene = MenuDemo::create();
			Director::getInstance()->replaceScene(menuScene);
		}
		});
	
	//��ӹ���ui��
	uiSharedLayer::getInstance()->createLayer();
	this->addChild(uiSharedLayer::getInstance());

	return true;
}

