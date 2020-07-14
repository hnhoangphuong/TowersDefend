#include "cocos2d.h"

USING_NS_CC;
class ListPoint
{
private:
    cocos2d::Vec2 mapPoint[];
public:
    ~ListPoint(){}
    ListPoint(int numOfPoint)
        {
            for(int i=0; i++;i<=numOfPoint)
            {
                mapPoint[i]=Vec2(0,0);
            }
        }
    void setPoint(cocos2d::Vec2 pos,int name)
        {
            mapPoint[name]=pos;
        }
    Vec2 getPoint(int name)
        {
            return mapPoint[name];
        }
};

class myMap
{
private:
    ListPoint map1;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
public:
myMap();
~myMap();
    ListPoint createMap(ListPoint thisMap,int numOfPoint);
    
    
};