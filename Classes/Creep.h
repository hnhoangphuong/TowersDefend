#ifndef __CREEP_H__
#define __CREEP_H__

#include "cocos2d.h"

class Creep 
{
private:
        cocos2d::Sprite* Rect;
        cocos2d::Size visibleSize;
        cocos2d::Vec2 origin;

public:
    Creep();
    void spawnCreep(cocos2d::Layer* layer);


};

#endif // __CREEP_H__