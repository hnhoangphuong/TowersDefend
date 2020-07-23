  
#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy()
{
    
}

bool Enemy::spawnEnemy(const char *filename, cocos2d::Vec2 pos)
{
	imageName = (char*)malloc(strlen(filename));
	imageName = strcpy(imageName, filename);
	objectSprite = Sprite::create(filename);
	objectSprite->setPosition(pos);
	this->addChild(objectSprite);
	return true;
}
void Enemy::actionMove(Vec2 nextPos)
{
	moveTo=MoveTo::create(2,nextPos);
}