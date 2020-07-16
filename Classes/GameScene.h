#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "CObject.h"
#include "CScene.h"
#include "Enemy.h"
#include "Tower.h"
#include "MyMap.h"

class GameScene : public CScene
{
private:
    cocos2d::Sprite* spriteBall;
    
    float time=1;
    float fps=0;
    
public:
    Tower* tower1;
    Enemy* enemy1;
    MyMap* map;

    static CScene* createScene();
    
    virtual bool init();
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    void update(float dt);
    CREATE_FUNC(GameScene);
    
    
};

#endif // __GAME_SCENE_H__
