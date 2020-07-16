#include "cocos2d.h"
#include "ListPoint.h"
USING_NS_CC;
class MyMap:public cocos2d::Node
{
private:
    ListPoint* map1;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
public:
MyMap(){};
~MyMap(){};
    bool initMap1();
    Vec2 getPoint(int name);
     
};
