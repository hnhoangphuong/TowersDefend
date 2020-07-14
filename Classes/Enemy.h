#ifndef __CREEP_H__
#define __CREEP_H__

#include "cocos2d.h"
#include "CObject.h"

class Enemy :public CObject
{
private:
        cocos2d::Sprite* Rect;
        cocos2d::Size visibleSize;
        cocos2d::Vec2 origin;
		char *imageName;
public:
    Enemy();
    //void run(float deltaTime){};
    bool runEnemy(cocos2d::Vec2* listPoint);
    bool spawnEnemy(const char* filename,cocos2d::Point pos);
};

#endif // __CREEP_H__