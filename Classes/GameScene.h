#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class GameScene : public cocos2d::Scene
{
private:
    cocos2d::PhysicsWorld* pWorld;
    void setPhysicsWorld(cocos2d::PhysicsWorld* m_pWorld)
    {
        pWorld = m_pWorld;
    }
public:
    static cocos2d::Scene* createScene();
  
    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif // __GAME_SCENE_H__
