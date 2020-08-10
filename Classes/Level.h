#ifndef _LEVEL_H_
#define _LEVEL_H_

#include "SceneMgr.h"
USING_NS_CC;

class Level: public CScene
{
private:
    bool _isEnable;
public:
~Level(){};
    static CScene* createScene();
    bool init();
    bool touchLocation(cocos2d::Touch* touch,cocos2d::Event* event);
    void menuCloseCallback(cocos2d::Ref* pSender);
    void goToGameScene(cocos2d::Ref* pSender);
    CREATE_FUNC(Level);   
};

#endif // _LEVEL_H_