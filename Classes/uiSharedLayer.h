#pragma once
/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
/*  
����һ���㵥������ר�Ŵ��һЩÿ��������Ҫ���ֵĿؼ�
*/
#include"cocos2d.h"
#include "..\cocos2d\cocos\editor-support\cocostudio\SimpleAudioEngine.h"
#include<ui\CocosGUI.h>

USING_NS_CC;
using namespace CocosDenshion;
using namespace ui;

class uiSharedLayer : public Layer
{
public:
	static void createLayer();

	virtual bool init();

	//�����������ص�����
	void sliderCallback(Ref* pSender, Slider::EventType type);

	//��ȡ�㵥��
	static uiSharedLayer* getInstance();

	static void destroyInstance();

	//�رհ�ť�Ļص�����
	void menuCloseCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(uiSharedLayer);

private:

	static uiSharedLayer* instance;

	Slider* musicSlider;
};