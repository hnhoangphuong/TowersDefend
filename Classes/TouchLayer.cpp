#include "TouchLayer.h"


void TouchLayer::placeTower()
{   
    setTower = EventListenerTouchOneByOne::create();
    setTower->onTouchBegan = [&](Touch*touch,Event* event)
    {
      
        auto tg = static_cast<Sprite*>(event->getCurrentTarget());
        
        Point tgPos = tg->convertTouchToNodeSpace(touch);
        tg->setVisible(false);
        Tower* tower = new Tower();
        tower->setTower("18.png",touch->getLocation());
        this->addChild(tower,2);
        // 
        return true;
    };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(setTower,this);
}