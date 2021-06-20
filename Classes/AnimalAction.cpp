/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include "AnimalAction.h"

//һ������ʵ��
void AnimalAction::createClearOneTimeAction()
{
	clearOneTimeAction = FadeOut::create(0.1f);
	return;
}

//ͨ�����ִ������⶯���Ķ���
Animate* AnimalAction::createAnimateUpAndDown(string name)
{
	return Animate::create(createAnimation("sprite/" + name + "/" + name + "_up_and_down.plist", 0.5f));
}

Animate* AnimalAction::createAnimateLeftAndRight(string name)
{
	return Animate::create(createAnimation("sprite/" + name + "/" + name + "_left_and_right.plist", 0.5f));
}

Animate* AnimalAction::createAnimateBright(string name)
{
	return Animate::create(createAnimation("sprite/" + name + "/" + name + "Bright.plist", 0.5f));
}

//�����ƶ�����
void AnimalAction::createActionMoveLeft()
{
	actionMoveLeft = MoveBy::create(0.5f, Vec2(-blockSize, 0));
	return;
}

void AnimalAction::createActionMoveRight()
{
	actionMoveRight = MoveBy::create(0.5f, Vec2(blockSize, 0));
	return;
}

void AnimalAction::createActionMoveUp()
{
	actionMoveUp = MoveBy::create(0.5f, Vec2(0, blockSize));
	return;
}

void AnimalAction::createActionMoveDown()
{
	actionMoveDown = MoveBy::create(0.5f, Vec2(0, -blockSize));
	return;
}

Animate* AnimalAction::getAnimateUpAndDownByNum(int logicNum)
{
	if (BEAR_UP_AND_DOWN_BLOCK == logicNum)
	{
		return bearAnimateUAD;
	}
	else if (CHICK_UP_AND_DOWN_BLOCK == logicNum)
	{
		return chickAnimateUAD;
	}
	else if (FOX_UP_AND_DOWN_BLOCK == logicNum)
	{
		return foxAnimateUAD;
	}
	else if (FROG_UP_AND_DOWN_BLOCK == logicNum)
	{
		return frogAnimateUAD;
	}
	else if (HORSE_UP_AND_DOWN_BLOCK == logicNum)
	{
		return horseAnimateUAD;
	}
	return nullptr;
}

Animate* AnimalAction::getAnimateLeftAndRightByNum(int logicNum)
{
	if (BEAR_LEFT_AND_RIGHT_BLOCK == logicNum)
	{
		return bearAnimateLAR;
	}
	else if (CHICK_LEFT_AND_RIGHT_BLOCK == logicNum)
	{
		return chickAnimateLAR;
	}
	else if (FOX_LEFT_AND_RIGHT_BLOCK == logicNum)
	{
		return foxAnimateLAR;
	}
	else if (FROG_LEFT_AND_RIGHT_BLOCK == logicNum)
	{
		return frogAnimateLAR;
	}
	else if (HORSE_LEFT_AND_RIGHT_BLOCK == logicNum)
	{
		return horseAnimateLAR;
	}
	return nullptr;
}

Animate* AnimalAction::getAnimateBrightByNum(int logicNum)
{
	if (BEAR_BRIGHT_BLOCK == logicNum)
	{
		return bearAnimateBright;
	}
	else if (CHICK_BRIGHT_BLOCK == logicNum)
	{
		return chickAnimateBright;
	}
	else if (FOX_BRIGHT_BLOCK == logicNum)
	{
		return foxAnimateBright;
	}
	else if (FROG_BRIGHT_BLOCK == logicNum)
	{
		return frogAnimateBright;
	}
	else if (HORSE_BRIGHT_BLOCK == logicNum)
	{
		return horseAnimateBright;
	}
	return nullptr;
}

//���÷���߳�
void AnimalAction::setBlockSize(float sideLength)
{
	blockSize = sideLength;
	return;
}

//һ���Խ�����Ķ���ȫ����ʼ��
bool AnimalAction::init()
{
	createClearOneTimeAction();
	createActionMoveLeft();
	createActionMoveRight();
	createActionMoveUp();
	createActionMoveDown();

	bearAnimateUAD = createAnimateUpAndDown("bear");
	chickAnimateUAD = createAnimateUpAndDown("chick");
	foxAnimateUAD = createAnimateUpAndDown("fox");
	frogAnimateUAD = createAnimateUpAndDown("frog");
	horseAnimateUAD = createAnimateUpAndDown("horse");

	bearAnimateLAR = createAnimateLeftAndRight("bear");
	chickAnimateLAR = createAnimateLeftAndRight("chick");
	foxAnimateLAR = createAnimateLeftAndRight("fox");
	frogAnimateLAR = createAnimateLeftAndRight("frog");
	horseAnimateLAR = createAnimateLeftAndRight("horse");

	bearAnimateBright = createAnimateBright("bear");
	chickAnimateBright = createAnimateBright("chick");
	foxAnimateBright = createAnimateBright("fox");
	frogAnimateBright = createAnimateBright("frog");
	horseAnimateBright = createAnimateBright("horse");

	
	return true;
}


