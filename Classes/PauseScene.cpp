/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include "PauseScene.h"
#include "MenuDemo.h"

Scene* PauseScene::createScene(int sceneType)
{
	//�������ڷ��ص�ui��������������Ϊ��ɫ��ʾ��ͣ����Ϸ���ж�
	Scene* myScene = Scene::create();
	auto background = Sprite::create("GameBackground.png");
	background->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	background->setPosition(Vec2::ZERO);
	background->setColor(Color3B::GRAY);
	myScene->addChild(background);

	//����������Ϸ�İ�ť
	auto button = Button::create("BeginBottonNormal.png", "BeginBottonSelected.png");
	button->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	button->setPosition(Vec2(Director::getInstance()->getVisibleSize().width / 2, 120));
	myScene->addChild(button);

	//���ݲ�ͬ��������ò�ͬ�ı�ʾ
	//�˳���������Ϸ����ͣ�жϻ���ʤ����ʧ���ж�ʱ����ʾ
	string str1, str2;

	if (CONTINUE == sceneType)
	{
		str1 = "continue";
		str2 = "STOP";
	}
	else
	{
		str1 = "return";
		if (WIN == sceneType)
		{
			str2 = "YOU WIN";
		}
		else
		{
			str2 = "YOU LOSE";
		}
	}

	//���ð�ť��������ʾ��ǩ
	auto label = Label::createWithSystemFont(str1, "��������", 32);
	label->setPosition(button->getPosition());
	myScene->addChild(label);

	//������Ϣ��ʾ��ǩ
	auto infoLabel = Label::createWithSystemFont(str2, "Arial Black", 50);
	infoLabel->setPosition(button->getPosition() + Vec2(0, 400));
	myScene->addChild(infoLabel);

	button->addTouchEventListener([myScene, sceneType](Ref* sender, ui::Widget::TouchEventType type) {
		if (type == ui::Widget::TouchEventType::ENDED)
		{
			if (CONTINUE == sceneType)
			{
				//������Ϸ
				Director::getInstance()->popScene();
			}
			else
			{
				//���ز˵�
				float vol = SimpleAudioEngine::getInstance()->getBackgroundMusicVolume();
				SimpleAudioEngine::getInstance()->stopBackgroundMusic();
				SimpleAudioEngine::getInstance()->playBackgroundMusic("music.mp3", true);
				SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(vol);
				auto meunScene = MenuDemo::create();
				Director::getInstance()->replaceScene(meunScene);
			}
		}
		});

	return myScene;
}


