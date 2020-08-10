#ifndef _MENUSCENE_H_
#define _MENUSCENE_H_

#include "SceneMgr.h"

class MenuScene : public CScene
{
public:
    static CScene* createScene();
    void goToGameScene(cocos2d::Ref* pSender);
    void goToSettingScene(cocos2d::Ref* pSender);
    void goToCreditScene(cocos2d::Ref* pSender);
    bool touchLocation(cocos2d::Touch* touch,cocos2d::Event* event);
    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
};

#endif // _MENUSCENE_H_