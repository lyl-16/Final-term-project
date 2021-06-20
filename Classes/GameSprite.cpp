/*
���ߣ�������
ѧ�ţ�2051970
���䣺3188001246@qq.com
������ڣ�2021��6��20��
*/
#include "GameSprite.h"

Animation* GameAction::createAnimation(const string& plist, float delayPerUnit)
{
	if (plist.empty()) return nullptr;

	//����Plist �� SpriteFrameCache
	auto cache = SpriteFrameCache::getInstance();
	cache->addSpriteFramesWithFile(plist);

	//��ȡ�ֵ�
	string fullPath = FileUtils::getInstance()->fullPathForFilename(plist);
	ValueMap dict = FileUtils::getInstance()->getValueMapFromFile(fullPath);
	//�������е�֡
	ValueMap& frames = dict["frames"].asValueMap();
	auto animation = Animation::create();
	for (auto item : frames)
	{
		auto frame = cache->getSpriteFrameByName(item.first);
		animation->addSpriteFrame(frame);
	}

	//���ö����Ĳ��ż��
	animation->setDelayPerUnit(delayPerUnit);
	animation->setRestoreOriginalFrame(true);
	return animation;
}
