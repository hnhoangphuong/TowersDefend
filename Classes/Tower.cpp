#include "Tower.h"

Tower::Tower()
{

}
Tower::~Tower()
{

}


bool Tower::setTower(const char *filename, cocos2d::Vec2 pos)
{
	imageName = (char*)malloc(strlen(filename));
	imageName = strcpy(imageName, filename);
	objectSprite = Sprite::create(filename);
	//cocos2d::Texture2D *heroTexture = TextureCache::sharedTextureCache()->addImage(filename);
	objectSprite->setPosition(pos);
	this->addChild(objectSprite);
	return true;
}

bool Tower::initWithFileAndRange(const char* filename,int range)
{
	bool bRet=false;
	do
	{
		sprite=Sprite::create(filename);
		this->addChild(sprite);

		this->setRange(range);

		_level = 1;
		_target = NULL;
		isShowing=false;

		bRet= true;
	} while (0);
return bRet;
}

void Tower::getClosestTarget()
{
	auto instance = GameManager::getInstance();
	auto enemyVector = instance->enemyVector;
	auto currMinDistant = this->scope;

	Enemy* enemyTemp= NULL;
	for(int i = 0;i<enemyVector.size();i++)
	{
		auto enemy = enemyVector.at(i);
		double distance = this->getParent()->getPosition().getDistance(enemy->objectSprite->getPosition());
		if(distance < currMinDistant )
			{
				currMinDistant=distance;
				enemyTemp=enemy;
			}
		closestEnemy=enemyTemp;
	}
	
}

