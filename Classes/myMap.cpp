#include "MyMap.h"

bool MyMap::initMap1()
{
    visibleSize = Director::getInstance()->getVisibleSize();
    origin = Director::getInstance()->getVisibleOrigin();
    map1 = new ListPoint(4);
    map1->setPoint(Vec2(visibleSize.width/4+origin.x,visibleSize.height/3+origin.y),0);
    map1->setPoint(Vec2(visibleSize.width/3+origin.x,visibleSize.height/3+origin.y),1);
    map1->setPoint(Vec2(visibleSize.width/3+origin.x,visibleSize.height/2+origin.y),2);
    map1->setPoint(Vec2(visibleSize.width*0.2+origin.x,visibleSize.height/2+origin.y),3);
    this->addChild(map1);
    mapTMX =TMXTiledMap::create("MapProject/Map_1.tmx");
    // mapTMX->setMapSize(visibleSize);
    Vector<MenuItem*> MenuItems;
    terrain[0] = MenuItemImage::create("MAP1_SET/dot.png","tower_1.png",[&](Ref* sender){placeTower(sender);});
    terrain[0]->setPosition(origin.x + 460,origin.y + 550);
    // terrain[1] = Sprite::create("MAP1_SET/dot.png");
    // terrain[1]->setPosition(origin.x + 1130,origin.y + 550);
    // terrain[2] = Sprite::create("MAP1_SET/dot.png");
    // terrain[2]->setPosition(origin.x + 200,origin.y + 164);
    // terrain[3] = Sprite::create("MAP1_SET/dot.png");
    // terrain[3]->setPosition(origin.x + 825,origin.y + 164);
    // terrain[4] = Sprite::create("MAP1_SET/dot.png");
    // terrain[4]->setPosition(origin.x + 1580,origin.y + 210 );
    MenuItems.pushBack(terrain[0]);
    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    // for(int i=1;i<5;i++)
    // {
    //     terrain[i]->setAnchorPoint(Point::ANCHOR_MIDDLE);
    //     this->addChild(terrain[i],2);
    // }
    this->addChild(mapTMX,0,99);
    return true;
}

Vec2 MyMap::getPoint(int name)
{
    return map1->getPoint(name);
}
TMXTiledMap* MyMap::getMapTMX()
{
    return mapTMX;
}


bool MyMap::initMap()
{
    maprcs->getInstance()->Init();
    return true;
}
// Sprite* MyMap::getTowerPosition(int towerName)
// {   
//     return terrain[towerName];
// }
void MyMap::deleteTerrain(int name)
{
    delete terrain[name];
}
bool MyMap::placeTower(cocos2d::Ref* sender)
{
    
    setTower = EventListenerTouchOneByOne::create();
    setTower->onTouchBegan = [&](Touch*touch,Event* event)
    {
        auto target = static_cast<Sprite*>(event->getCurrentTarget());
        Point locationInNode = target->convertTouchToNodeSpace(touch);
        Tower* tower = new Tower();
        Size size = target->getContentSize();
	    Rect rect = Rect(0, 0, size.width, size.height);
	if (rect.containsPoint(locationInNode))
	{  	
        tower->setTower("18.png",touch->getLocation());
        this->addChild(tower,3);
        
         return true;
    }
    };
    
    _eventDispatcher->addEventListenerWithSceneGraphPriority(setTower,this);
}

