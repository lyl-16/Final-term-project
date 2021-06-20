#pragma once
/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include"StandardMode.h"

struct Snow
{
	Sprite* sprite;
	Position location;
	int logicNumber;
};

//�ڶ��ؼ̳е�һ�أ�������ĳЩ����
class SpecialGame : public StandardGame
{
private:
	static SpecialGame* instance;

	//Ŀ�����
	const int targetscore = 2000;

	//����Ҫ������ѩ������
	int snowNum;

	vector<vector<Snow> > snowArray;//ֱ���þ���������

public:
	static SpecialGame* getInstance();
	SpecialGame();

	//��Ҫ��д�ĺ���
	int getTargetNum();

	int getTargetScore();

	void build();

	bool init();

	void commonClear(const Position p);

	int checkEnded();
};