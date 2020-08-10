#pragma once
#include "cocos2d.h"
#include "EnemyPath.h"
#include "ResourceMgr.h"
#include "Tower.h"
USING_NS_CC;
class MyMap:public cocos2d::Layer
{
private:
    ListPoint* map1;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::MenuItemImage* terrain[5];
    EventListenerTouchOneByOne* setTower;
    ResourceMgr* maprcs;
public:
MyMap(){};
~MyMap(){};
    CREATE_FUNC(MyMap);
    bool initMap1();
    Vec2 getPoint(int name);
    cocos2d::TMXTiledMap* mapTMX;
    cocos2d::Sprite* mapSprite;
    TMXTiledMap* getMapTMX();
    void deleteTerrain(int name);
    bool initMap();
    // Sprite* getTowerPosition(int towerName);
    // Sprite* getGroupTerrain();
    bool placeTower(cocos2d::Ref* sender);
protected:
    int wave;
    int maxWave;
    int level;
    
};
