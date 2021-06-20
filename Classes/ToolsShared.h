#pragma once
/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
/*
��ͷ�ļ����ڴ�Ų�ͬcpp����Ҫʹ�õ��ĺ궨��ͽṹ��
*/
#include"cocos2d.h"
#include"uiSharedLayer.h"

//�����������ҵ��߼�ֵ
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

//������ͨ���ﾫ����߼�ֵ
#define NO_BLOCK 0
#define BEAR_COMMON_BLOCK 10
#define CHICK_COMMON_BLOCK 20
#define FOX_COMMON_BLOCK 30
#define FROG_COMMON_BLOCK 40
#define HORSE_COMMON_BLOCK 50

#define BEAR_UP_AND_DOWN_BLOCK 11
#define BEAR_LEFT_AND_RIGHT_BLOCK 12
#define BEAR_BRIGHT_BLOCK 13

#define CHICK_UP_AND_DOWN_BLOCK 21
#define CHICK_LEFT_AND_RIGHT_BLOCK 22
#define CHICK_BRIGHT_BLOCK 23

#define FOX_UP_AND_DOWN_BLOCK 31
#define FOX_LEFT_AND_RIGHT_BLOCK 32
#define FOX_BRIGHT_BLOCK 33

#define FROG_UP_AND_DOWN_BLOCK 41
#define FROG_LEFT_AND_RIGHT_BLOCK 42
#define FROG_BRIGHT_BLOCK 43

#define HORSE_UP_AND_DOWN_BLOCK 51
#define HORSE_LEFT_AND_RIGHT_BLOCK 52
#define HORSE_BRIGHT_BLOCK 53

//��������������ֵ
#define COMMON_BLOCK 0
#define UP_AND_DOWN_BLOCK 1
#define LEFT_AND_RIGHT_BLOCK 2
#define BRIGHT_BLOCK 3
#define COLOURFUL_BLOCK 8

//������Ӯ�ͼ�����Ϸ���߼�ֵ
#define CONTINUE 0
#define WIN 1
#define LOSE 2

//��������ѩ����߼�ֵ
#define NO_SNOW 0
#define SNOW 1

USING_NS_CC;
using namespace std;


struct Position
{
	int row;
	int col;
};

struct BlockElem
{
	Sprite* sprite;
	Position location;
	int logicNumber;
	bool bIfMoved;//������¼�Ƿ������ƶ�
	
	void createSprite()
	{
		if (BEAR_COMMON_BLOCK == logicNumber)
		{
			sprite = Sprite::create("sprite/bear/bear.png");
		}
		else if (CHICK_COMMON_BLOCK == logicNumber)
		{
			sprite = Sprite::create("sprite/chick/chick.png");
		}
		else if (FOX_COMMON_BLOCK == logicNumber)
		{
			sprite = Sprite::create("sprite/fox/fox.png");
		}
		else if (FROG_COMMON_BLOCK == logicNumber)
		{
			sprite = Sprite::create("sprite/frog/frog.png");
		}
		else if (HORSE_COMMON_BLOCK == logicNumber)
		{
			sprite = Sprite::create("sprite/horse/horse.png");
		}
		return;
	}
};