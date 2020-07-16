#include "CObject.h"

USING_NS_CC;

class Tower : public CObject
{
private:

    char* imageName;
public:
Tower();
~Tower();
    bool setTower( const char *filename, cocos2d::Vec2 pos);
    bool init(){return false;};
    void updateObject(float deltaTime){};
    void run(float deltaTime){};
};