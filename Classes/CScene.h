#ifndef __CSCENE_H__
#define __CSCENE_H__

#include "CObject.h"

class CScene : public cocos2d::Scene
{
public:
	virtual bool init();
    virtual void update(float deltaTime);
    cocos2d::Size visibleSize;
    cocos2d::Vec2 origin;

};

#endif // __CSCENE_H__