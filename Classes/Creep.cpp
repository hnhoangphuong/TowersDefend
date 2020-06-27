#include "Creep.h"

USING_NS_CC;

Creep::Creep()
{
    visibleSize=Director::getInstance()->getVisibleSize();
    origin= Director::getInstance()->getVisibleSize();
}

void Creep::spawnCreep(cocos2d::Layer* layer)
{
    auto rect = Sprite::create("crate.png");
    auto random= CCRANDOM_0_1();
    rect->setPosition(Vec2(random*visibleSize.height+origin.y,random*visibleSize.width+origin.x));
    layer->addChild(rect);
}
