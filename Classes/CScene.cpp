
#include "CScene.h"

USING_NS_CC;

// on "init" you need to initialize your instance
bool CScene::init()
{
	if (!Scene::init())
	{
		return false;
	}


    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();

	return true;
}

void CScene::update(float deltaTime)
{
    
}
