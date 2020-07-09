#include "CObject.h"

USING_NS_CC;

class Tower : public CObject
{
private:
    cocos2d::Sprite* towerSprite;

public:
Tower();
~Tower();
    bool createTower( std::string  filename,cocos2d::Vec2 pos);
      bool init(){return false;};
     void updateObject(float deltaTime){};
     void run(float deltaTime){};
};