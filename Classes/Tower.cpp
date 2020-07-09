#include "Tower.h"

Tower::Tower()
{

}
Tower::~Tower()
{

}

bool Tower::createTower(std::string filename,cocos2d::Vec2 pos )
{
    towerSprite = cocos2d::Sprite::create(filename);
    towerSprite->setPosition(pos);
    this->addChild(towerSprite);
}