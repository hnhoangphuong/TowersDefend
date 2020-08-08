#ifndef _SETTING_SCENE_H_
#define _SETTING_SCENE_H_

#include "SceneMgr.h"
USING_NS_CC;

class SettingScene : public CScene
{
public:
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);
    static CScene* createScene();
    // implement the "static create()" method manually
    CREATE_FUNC(SettingScene);
};
#endif //_SETTING_SCENE_H_