#ifndef __COBJECT_H__
#define __COBJECT_H__


#include "cocos2d.h"

USING_NS_CC;

class CObject: public cocos2d::Node
{
public:
    CObject();
    virtual bool init();
    virtual void updateObject(float deltaTime);
    virtual void run(float deltaTime)=0;
    
    cocos2d::Rect getRect();

    virtual void createPhysicBody(bool dynamic = true, bool rotationEnabale=true);

    virtual void onCollisionEnEnter(CObject* gameObject){}
    virtual void onCollisionExit(CObject* gameObject){}
    virtual void onCollisionPreEnter(CObject* gameObject){}
    virtual void onCollisionPosExit(CObject* gameObject){}
protected:
    bool _isAlive;
};

#endif // __COBJECT_H__