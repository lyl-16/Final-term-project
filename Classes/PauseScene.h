#pragma once
#include"cocos2d.h"
#include"ToolsShared.h"

USING_NS_CC;

class PauseScene : public Scene
{
public:
	//������ͣ����
	static Scene* createScene(int type);

	CREATE_FUNC(PauseScene);

};