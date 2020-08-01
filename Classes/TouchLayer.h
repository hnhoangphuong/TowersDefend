#ifndef _TOUCHLAYER_H_
#define _TOUCHLAYER_H_
#include "cocos2d.h"
#include "Tower.h"
#include "MyMap.h"
USING_NS_CC;

class TouchLayer : public cocos2d::Node
{
private:
public:
TouchLayer(){};
~TouchLayer(){};
    CREATE_FUNC(TouchLayer);
    EventListenerTouchOneByOne* listener;
    EventListenerTouchOneByOne* touchListener;
    EventListenerTouchOneByOne* setTower;

    void placeTower();
};
#endif // _TOUCHLAYER_H_