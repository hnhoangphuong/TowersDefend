  
#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy()
{
    visibleSize=Director::getInstance()->getVisibleSize();
    origin= Director::getInstance()->getVisibleSize();
}



void Enemy::spawnEnemy(cocos2d::Layer* layer)
{
    Rect = Sprite::create("crate.png");
    auto random= CCRANDOM_0_1();
    Rect->setPosition(Vec2(random*visibleSize.height+origin.y,random*visibleSize.width+origin.x));
    layer->addChild(Rect);
}