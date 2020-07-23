#include "MyMap.h"

bool MyMap::initMap1()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    map1 = new ListPoint(4);
    map1->setPoint(Vec2(visibleSize.width/4+origin.x,visibleSize.height/3+origin.y),0);
    map1->setPoint(Vec2(visibleSize.width/3+origin.x,visibleSize.height/3+origin.y),1);
    map1->setPoint(Vec2(visibleSize.width/3+origin.x,visibleSize.height/2+origin.y),2);
    map1->setPoint(Vec2(visibleSize.width*0.2+origin.x,visibleSize.height/2+origin.y),3);
    this->addChild(map1);
    mapTMX =TMXTiledMap::create("MapProject/Map_1.tmx");
    mapTMX->setMapSize(visibleSize);
    addChild(mapTMX,0,99);
    return true;
}
Vec2 MyMap::getPoint(int name)
{
    return map1->getPoint(name);
}
TMXTiledMap* MyMap::getMapTMX()
{
    return mapTMX;
}

