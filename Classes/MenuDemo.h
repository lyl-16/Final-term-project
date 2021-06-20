#pragma once
/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include"cocos2d.h"
#include"uiSharedLayer.h"

USING_NS_CC;


class MenuDemo : public Scene
{
public:
	CREATE_FUNC(MenuDemo);

	//�����һ�ذ�ť�Ļص�����
	void enterGameOneCallback(Ref* pSender);

	//����ڶ��ذ�ť�Ļص�����
	void enterGameTwoCallback(Ref* pSender);

	virtual bool init();

private:
	Vec2 position;

	Sprite* sprite;

	Layer* backgroundLayer;

	Vec2 visibleSize = Director::getInstance()->getVisibleSize();

};