/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include "gameScene.h"
#include "PauseScene.h"

Scene* gameScene::createScene()
{
	return gameScene::create();
}

bool gameScene::init()
{
	if(!Scene::create())
	return false;

	//����������
	auto backgroundLayer = Layer::create();
	this->addChild(backgroundLayer);

	//��������ͼƬ
	auto bg = Sprite::create("GameBackground.png");
	bg->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	backgroundLayer->addChild(bg);

	//������¼ʣ�������ľ���
	auto timesBoard = Sprite::create("timesBroad.png");
	timesBoard->setAnchorPoint(Vec2::ANCHOR_TOP_RIGHT);
	timesBoard->setPosition(backgroundLayer->getContentSize());
	backgroundLayer->addChild(timesBoard);

	//�����÷ְ澫��
	auto scoreBoard = Sprite::create("ScoreBoard.png");
	scoreBoard->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	scoreBoard->setPosition(Vec2(0, 800));
	backgroundLayer->addChild(scoreBoard);

	//����ʤ��Ŀ��澫��
	auto targetScoreBoard = Sprite::create("targetBoard.png");
	targetScoreBoard->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	targetScoreBoard->setPosition(Vec2(200, backgroundLayer->getContentSize().height));
	backgroundLayer->addChild(targetScoreBoard);

	
	auto targetSpriteBoard = Sprite::create("targetBoard.png");
	targetSpriteBoard->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	targetSpriteBoard->setPosition(Vec2(350, backgroundLayer->getContentSize().height));
	backgroundLayer->addChild(targetSpriteBoard);

	//����Ϸ����ӵ������У�����ʼ����Ϸ��ʵ��
	this->addChild(gameLayer);
	StandardGame::getInstance()->set(6, 6, 20, gameLayer, Vec2(150, 250));
	StandardGame::getInstance()->gameBegin();

	//ͨ����ǩ�ؼ�����ʾ����

	//������ǩ
	scoreLabel = Label::createWithSystemFont("Score: 0", "΢���ź�", 20);
	scoreLabel->setColor(Color3B::BLACK);
	scoreLabel->setPosition(Vec2(60, 770));
	backgroundLayer->addChild(scoreLabel);

	//ʣ�������ǩ
	timeLabel = Label::createWithSystemFont("20", "���Ĳ���", 35);
	timeLabel->setColor(Color3B::ORANGE);
	timeLabel->setPosition(Vec2(timesBoard->getPosition().x - timesBoard->getContentSize().width / 2 + 20, timesBoard->getPosition().y - timesBoard->getContentSize().height / 2 - 10));
	backgroundLayer->addChild(timeLabel);

	//��ʾ��Ϣ��ǩ
	auto infoLabel = Label::createWithSystemFont("Target Score", "΢���ź�", 15);
	infoLabel->setColor(Color3B::WHITE);
	infoLabel->setPosition(Vec2(200, backgroundLayer->getContentSize().height - 70));
	backgroundLayer->addChild(infoLabel);

	//��ʾĿ���ֵ��ǩ
	auto targetScoreLabel = Label::createWithSystemFont(to_string(StandardGame::getInstance()->getTargetScore()), "΢���ź�", 30);
	targetScoreLabel->setColor(Color3B::WHITE);
	targetScoreLabel->setPosition(Vec2(200, backgroundLayer->getContentSize().height - 100));
	backgroundLayer->addChild(targetScoreLabel);

	//��ʾ��Ҫ�����ľ����ǩ
	auto targetSprite = Sprite::create("sprite/bear/bear.png");
	targetSprite->setPosition(Vec2(350, backgroundLayer->getContentSize().height - 80));
	backgroundLayer->addChild(targetSprite);

	targetSpriteLabel = Label::createWithSystemFont("10", "΢���ź�", 20);
	targetSpriteLabel->setColor(Color3B::WHITE);
	targetSpriteLabel->setPosition(Vec2(350, backgroundLayer->getContentSize().height - 110));
	backgroundLayer->addChild(targetSpriteLabel);

	//����������¼�
	auto listener = EventListenerTouchOneByOne::create();

	listener->onTouchBegan = [this](Touch* touch, Event* event) {
		clickBegan = touch->getLocation();
		return true;
	};
	listener->onTouchEnded = [this](Touch* touch, Event* event) {
		clickEnded = touch->getLocation();
		StandardGame::getInstance()->playGame(clickBegan, clickEnded);
		scoreUpdate(StandardGame::getInstance()->getScore());
		timesUpdate(StandardGame::getInstance()->getMoveTime());
		targetUpdate(StandardGame::getInstance()->getTargetNum());

		int gameCondition = StandardGame::getInstance()->checkEnded();
		if (gameCondition)
		{

			Director::getInstance()->pushScene(PauseScene::createScene(gameCondition));
		}

		return true;
	};
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

	//��ӹ���ui��
	uiSharedLayer::getInstance()->createLayer();
	this->addChild(uiSharedLayer::getInstance());

	//������ͣ��ť
	auto stopButton = Button::create("stopBotton.png", "stopBotton.png");
	stopButton->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	stopButton->setPosition(Vec2(30, 810));
	this->addChild(stopButton);

	stopButton->addTouchEventListener([this](Ref* sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
		{

			Director::getInstance()->pushScene(PauseScene::createScene(CONTINUE));
		}
		});

	return true;
}

void gameScene::scoreUpdate(int score)
{
	//ʹ��to_string������ת����ʾ��ֵ
	scoreLabel->setString("Score: " + to_string(score));
	return;
}

void gameScene::timesUpdate(int moveTimes)
{
	timeLabel->setString(to_string(moveTimes));
	return;
}

void gameScene::targetUpdate(int leftNum)
{
	targetSpriteLabel->setString(to_string(leftNum));
	return;
}
