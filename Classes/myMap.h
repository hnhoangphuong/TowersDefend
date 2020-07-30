#include "cocos2d.h"
#include "EnemyPath.h"
USING_NS_CC;
class MyMap:public cocos2d::Layer
{
private:
    ListPoint* map1;
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
    cocos2d::Sprite* terrain[5];
public:
MyMap(){};
~MyMap(){};
    CREATE_FUNC(MyMap);
    bool initMap1();
    Vec2 getPoint(int name);
    cocos2d::TMXTiledMap* mapTMX;
    cocos2d::Sprite* mapSprite;
    TMXTiledMap* getMapTMX();
    
protected:
    int wave;
    int maxWave;
    int level;
    
};
