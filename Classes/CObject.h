#ifndef __COBJECT_H__
#define __COBJECT_H__


#include "cocos2d.h"

USING_NS_CC;

class CObject: public cocos2d::Node
{
public:
    CObject();
    virtual ~CObject(){};
    // virtual bool init();
    // virtual void updateObject(float deltaTime);
    // virtual void run(float deltaTime)=0;
    
    cocos2d::Rect getRect();
    cocos2d::Sprite *objectSprite;
    //virtual void createPhysicBody(bool dynamic = true, bool rotationEnabale=true);

    // virtual void onCollisionEnEnter(CObject* gameObject){}
    // virtual void onCollisionExit(CObject* gameObject){}
    // virtual void onCollisionPreEnter(CObject* gameObject){}
    // virtual void onCollisionPosExit(CObject* gameObject){}
protected:
    bool _isAlive;
    
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;
};

#endif // __COBJECT_H__