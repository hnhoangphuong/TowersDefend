#ifndef __TOWERDEFEND_WAVE__
#define __TOWERDEFEND_WAVE__
#include "Enemy.h"

USING_NS_CC;
class Wave :public cocos2d::Node
{
public:
	bool initWithEnemySpawnRate(float spawnrate);
	Wave* create(float spawnrate);

	
protected:
	CC_SYNTHESIZE(int, _numOfEnemy, numOfEnemy);
	CC_SYNTHESIZE(float, _spawnRate, SpawnRate);
	
};

#endif //