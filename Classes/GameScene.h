#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "CObject.h"
#include "CScene.h"
#include "Enemy.h"

class GameScene : public CScene
{
private:
    cocos2d::Sprite* spriteBall;
    float time=1;
    float fps=0;
public:
    static CScene* createScene();
  
    virtual bool init();
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    // implement the "static create()" method manually
    void gameUpdate(float dt);
    CREATE_FUNC(GameScene);
    
    
};

#endif // __GAME_SCENE_H__
