/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#pragma once
#include"cocos2d.h"
USING_NS_CC;
using namespace std;

//�����Ϸ������������Ϊһ��������࣬���ڶ���ĳ�������Ķ�������������һ������Щ�鹲�е�����
//����ûʱ��д̫������飬���������ûʲô��
class GameAction : public Ref  //�̳�ref�����������н����ڴ����
{
protected:
	//ʹ��ͼ�����������ĺ���
	Animation* createAnimation(const string& plist, float delayPerUnit);
public:
	Action* clearOneTimeAction;

	virtual void createClearOneTimeAction() = 0;
};

