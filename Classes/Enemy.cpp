  
#include "Enemy.h"

USING_NS_CC;

Enemy::Enemy()
{
    
}



bool Enemy::spawnEnemy(const char *filename, cocos2d::Point pos)
{
	imageName = (char*)malloc(strlen(filename));
	imageName = strcpy(imageName, filename);
	Rect = Sprite::create(filename);
	//cocos2d::Texture2D *heroTexture = TextureCache::sharedTextureCache()->addImage(filename);
	Rect->setPosition(pos);

	return true;
}