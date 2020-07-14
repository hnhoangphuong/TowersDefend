#include "myMap.h"

ListPoint myMap::createMap(ListPoint thisMap,int numOfPoint)
{
    thisMap = ListPoint(numOfPoint);
    thisMap.setPoint(Vec2(visibleSize.width/4+origin.x,visibleSize.height/3+origin.y),0);
    thisMap.setPoint(Vec2(visibleSize.width/3+origin.x,visibleSize.height/3+origin.y),1);
    thisMap.setPoint(Vec2(visibleSize.width/3+origin.x,visibleSize.height/2+origin.y),2);
    thisMap.setPoint(Vec2(visibleSize.width*0.2+origin.x,visibleSize.height/2+origin.y),3);
    map1=thisMap;
    return map1;
}
