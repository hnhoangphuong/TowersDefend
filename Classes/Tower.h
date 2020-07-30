#ifndef _TOWER_H_
#define _TOWER_H_
#include "CObject.h"
#include "Enemy.h"
#include "GameManager.h"

USING_NS_CC;

class Tower : public CObject
{
protected:
    cocos2d::Sprite* actionSprite;
	cocos2d::Sprite* sprite;
    cocos2d::Sprite* rangeSprite;
	cocos2d::Sprite* sprite1;
	cocos2d::Sprite* sprite2;
	cocos2d::Sprite* sprite3;
	cocos2d::Sprite* sprite4;
    int _money;
    int _damage;
    int _maxDamage;
    float _interval;
    bool moneySufficent;
    bool isShowing;
    char* imageName;
    virtual void getClosestTarget();
    virtual void fire(){}
    virtual void fireReady(){}
    virtual void fireNow(){}
    void show();
    void unShow();
    Enemy* closestEnemy;
public:

    Tower();
    virtual ~Tower();
    virtual bool initWithFileAndRange(const char *filename,int ran);
    bool setTower( const char *filename, cocos2d::Vec2 pos);
    bool init(){return false;};
    void updateObject(float deltaTime){};
    void run(float deltaTime){};
    CC_SYNTHESIZE(float, scope, Scope);
    CC_SYNTHESIZE(int, _range, Range);
    CC_SYNTHESIZE(int, _level, Level);
    CC_SYNTHESIZE_RETAIN(Enemy*, _target, Target);

};
#endif //_TOWER_H_