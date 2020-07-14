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
	Sprite = Sprite::create(filename);
	//cocos2d::Texture2D *heroTexture = TextureCache::sharedTextureCache()->addImage(filename);
	Sprite->setPosition(pos);
	this->addChild(Sprite);
	return true;
}