
#ifndef __SPLASH_SCENE_H__
#define __SPLASH_SCENE_H__
#include "cocos2d.h"
class Splash : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    void goToMainMenu(float dt);
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    // implement the "static create()" method manually
    CREATE_FUNC(Splash);
};

#endif // __SPLASH_SCENE_H__