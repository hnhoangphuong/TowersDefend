#ifndef _CREDIT_SCENE_H_
#define _CREDIT_SCENE_H_

#include "SceneMgr.h"
USING_NS_CC;

class CreditScene : public CScene
{
public:
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    static CScene* createScene();
    // implement the "static create()" method manually
    CREATE_FUNC(CreditScene);
    bool touchLocation(cocos2d::Touch* touch,cocos2d::Event* event);
};
#endif //_CREDIT_SCENE_H_