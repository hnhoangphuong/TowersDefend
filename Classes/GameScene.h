#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"
#include "Creep.h"
class GameScene : public cocos2d::Scene
{
private:

    cocos2d::Sprite* spriteBall;

    
public:
    static cocos2d::Scene* createScene();
    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    void spawn
    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);


};

#endif // __GAME_SCENE_H__
