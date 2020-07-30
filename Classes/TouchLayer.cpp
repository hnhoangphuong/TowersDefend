#include "TouchLayer.h"


void TouchLayer::placeTower(Tower* tower)
{   
    
    this->tower=tower;
    
    setTower = EventListenerTouchOneByOne::create();
    setTower->onTouchBegan = [&](Touch*touch,Event* event)
    {
        this->tower->setTower("18.png",touch->getLocation());
        return true;
    };
}