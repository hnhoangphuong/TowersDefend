#include "cocos2d.h"
class MenuScene : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    bool PlayClick(cocos2d::Touch* touch, cocos2d::Event* event);
    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
};