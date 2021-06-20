/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#pragma once
#include"AnimalAction.h"

//�����ؿ���
//�麯������������ؿ��ļ̳�
class StandardGame 
{
private:
	const int targetScore = 700;

protected:

	//��ָ��
	static StandardGame* instance;

	//�������С
	Position size;

	//������ָ��
	Layer* pL;

	vector<vector<BlockElem> > gameArray;//ֱ���þ���������

	//����ͼ��ָ��
	Sprite* blockBackground; 

	//��ʼλ�ã�ȷ����Ϸͼ�������λ��
	Vec2 startPosition;

	//���趯����ʵ��
	AnimalAction* animalAction;

	int score;

	int moveTime;

	int targetBearNum;

	//�������������������ͱ����ĺ���
	template<typename T>
	void exchange(T* pT1, T* pT2);

public:

	static StandardGame* getInstance();
	static void destroyInstance();
	StandardGame();
	~StandardGame();

	//��ʼ�����ú���
	void set(int col, int row, int time, Layer* layer, Vec2 leftBottomPosition)
	{
		size.col = col;
		size.row = row;
		moveTime = time;
		pL = layer;
		startPosition = leftBottomPosition;
	};

	//��ȡ��ǰ����
	int getScore();

	//��ȡʣ���ƶ�����
	int getMoveTime();

	//��ȡʣ��Ŀ����
	virtual int getTargetNum();

	//��ȡĿ�����
	virtual int getTargetScore();

	//������Ϸ�ľ���������
	virtual void build();

	//��������ʼ��
	virtual bool init();

	int checkLinkedBlocksInOneDirection(const Position* p, const int logicNum, const int direction);  //�ж������ĳ�����ж��ٸ���ͬ�ĺ���

	int countLinkedBlocks(const Position* p);  //ȷ��������������

	virtual Position getClickLocation(Vec2 clickBegan);  //��ȡ���������λ��

	virtual int getMoveDirection(Vec2 clickBegan, Vec2 clickEnded);  //��ȡ�ƶ�����

	//��ȫ����
	virtual void commonClear(const Position p);

	//���������Ŀ�
	virtual void commonLinkBlocksClear(const Position p, int flag, bool ifClearItself = true);

	//��������
	virtual void colClear(const Position p, bool ifClearItself = true);

	//��������
	virtual void rowClear(const Position p, bool ifClearItself = true);

	//��ը����
	virtual void boomClear(const Position p, bool ifClearItself = true);

	//˫ħ��������
	virtual void twoMagicClear(const Position p1, const Position p2);

	virtual void magicClear(const Position p, int direction = 0);//����ħ����

	//����������
	virtual void oneBlockClear(const Position p, bool ifClearItself = true);

	//����ȫ�ֽ�������
	virtual void clearBlocks();

	//�����µ������
	virtual void generateSpecialBlocks(const Position p, int type);

	//��Ч��������
	virtual bool multipleClear(const Position p1, int direction);

	//��һ�����򽻻�������
	virtual bool exchangeTwoBlocksInOneDirection(const Position p1, int direction);

	//ͨ����ȡ����¼����п���ƶ�
	virtual bool exchangeTwoBlocks(Vec2 clickBegan, Vec2 clickEnded);

	virtual void dropOneCol(int col);  //����һ��

	virtual void drop();  //ȫ������

	virtual bool checkContinue(); //����Ƿ���䲢�������

	//��Ϸ��ʼ
	void gameBegin();
	
	//��Ϸ�Ƿ�������
	virtual int checkEnded();

	//��Ϸ���
	virtual void playGame(Vec2 v1, Vec2 v2);

};

template<typename T>
inline void StandardGame::exchange(T* pT1, T* pT2)
{
	T temp;
	temp = *pT1;
	*pT1 = *pT2;
	*pT2 = temp;
	return;
}
