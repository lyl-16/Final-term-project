#pragma once
/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include<cocos2d.h>
#include"uiSharedLayer.h"
USING_NS_CC;

#include<map>



class StartDemo : public Scene
{
public:
	static Scene* createScene();

	virtual bool init();

	CREATE_FUNC(StartDemo);
private:
	std::map<int, Value> words;


};