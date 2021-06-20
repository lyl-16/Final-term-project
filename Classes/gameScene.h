#pragma once
/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include"cocos2d.h"
#include"StandardMode.h"


USING_NS_CC;

class gameScene : public Scene
{
public:
	Scene* createScene();

	virtual bool init();

	//���·�����ʾ
	void scoreUpdate(int score);

	//����ʣ�������ʾ
	void timesUpdate(int moveTimes);

	//���¾���ʤ��Ŀ�������ʾ
	void targetUpdate(int leftNum);

	CREATE_FUNC(gameScene);

private:
	Layer* gameLayer = Layer::create();

	Vec2 clickBegan;

	Vec2 clickEnded;

	Label* scoreLabel;

	Label* timeLabel;

	Label* targetSpriteLabel;

};
