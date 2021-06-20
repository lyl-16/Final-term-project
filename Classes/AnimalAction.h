/* 
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#pragma once
#include"GameSprite.h"
#include "ToolsShared.h"
using namespace std;

class AnimalAction : public GameAction  //�̳ж����ļ�����GameAction
{
private:
	//�����С(�߳�)
	float blockSize;

	//���ڳ�ʼ�������ĺ���
	void createClearOneTimeAction();
	Animate* createAnimateUpAndDown(string name);
	Animate* createAnimateLeftAndRight(string name);
	Animate* createAnimateBright(string name);
	void createActionMoveLeft();
	void createActionMoveRight();
	void createActionMoveUp();
	void createActionMoveDown();


public:

	CREATE_FUNC(AnimalAction);

	virtual bool init();

	//��Ч����Ķ���
	Animate* bearAnimateUAD;
	Animate* chickAnimateUAD;
	Animate* foxAnimateUAD;
	Animate* frogAnimateUAD;
	Animate* horseAnimateUAD;

	Animate* bearAnimateLAR;
	Animate* chickAnimateLAR;
	Animate* foxAnimateLAR;
	Animate* frogAnimateLAR;
	Animate* horseAnimateLAR;

	Animate* bearAnimateBright;
	Animate* chickAnimateBright;
	Animate* foxAnimateBright;
	Animate* frogAnimateBright;
	Animate* horseAnimateBright;

	//�ƶ��Ķ���
	Action* actionMoveLeft;
	Action* actionMoveRight;
	Action* actionMoveUp;
	Action* actionMoveDown;

	//ͨ���߼�ֵ�õ������ķ���
	Animate* getAnimateUpAndDownByNum(int logicNum);
	Animate* getAnimateLeftAndRightByNum(int logicNum);
	Animate* getAnimateBrightByNum(int logicNum);

	void setBlockSize(float sideLength);

};