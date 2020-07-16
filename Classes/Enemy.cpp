  
#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy()
{
    
}

bool Enemy::spawnEnemy(const char *filename, cocos2d::Vec2 pos)
{
	imageName = (char*)malloc(strlen(filename));
	imageName = strcpy(imageName, filename);
	Sprite = Sprite::create(filename);
	Sprite->setPosition(pos);
	this->addChild(Sprite);
	return true;
}
void Enemy::actionMove(Vec2 nextPos)
{
	moveTo=MoveTo::create(2,nextPos);
	
	
	
}