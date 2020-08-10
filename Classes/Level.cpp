#include "Level.h"
USING_NS_CC;

CScene* Level::createScene()
{
    return Level::create();
}

bool Level::init()
{
    if (!CScene::init())
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    //===========================================================
    auto levelBoard = Sprite::create("UI/levels/table.png");
    levelBoard->setPosition(Vec2(origin.x+visibleSize.width/2,origin.y+visibleSize.height/2));
    this->addChild(levelBoard,1);
    auto backGround = Sprite::create("UI/back_ground.png");
    backGround->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    backGround->setPosition(Vec2((0 + origin.x), 0 + origin.y));
    this->addChild(backGround,0);
    auto header = Sprite::create("UI/levels/header_levels.png");
    header->setAnchorPoint(Vec2::ANCHOR_MIDDLE_BOTTOM);
    header->setPosition(Vec2(origin.x+ levelBoard->getContentSize().width,origin.y+ 800));
    this->addChild(header,2);
    //616,725
    
    
    
    auto touchLocation = EventListenerTouchOneByOne::create();
    touchLocation->onTouchBegan = CC_CALLBACK_2(Level::touchLocation,this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchLocation,this);

    Vector<MenuItem*> MenuItems;
    auto btn_close = MenuItemImage::create(
                                            "UI/button_close.png",
                                            "UI/button_close.png",
                                            [&](Ref* sender){menuCloseCallback(sender);
                                        });
    
    btn_close->setPosition(Vec2(origin.x+1390,origin.y +820));
    auto icon_map1= MenuItemImage::create(   "UI/levels/icon_map1.png",
                                            "UI/levels/icon_map1.png",
                                            [&](Ref* sender){goToGameScene(sender);
                                            });
    icon_map1->setPosition(Vec2(origin.x+616,origin.y+725));
     auto icon_map2= MenuItemImage::create(   "UI/levels/icon_map2.png",
                                            "UI/levels/icon_map2.png",
                                            [&](Ref* sender){goToGameScene(sender);
                                            });
    icon_map2->setPosition(Vec2(origin.x+616 + icon_map1->getContentSize().width,origin.y+725));
     auto icon_map3= MenuItemImage::create(   "UI/levels/icon_map3.png",
                                            "UI/levels/icon_map3.png",
                                            [&](Ref* sender){goToGameScene(sender);
                                            });
    icon_map3->setPosition(Vec2(origin.x+icon_map2->getPosition().x + icon_map2->getContentSize().width,origin.y+725)); 
    MenuItems.pushBack(btn_close);
    MenuItems.pushBack(icon_map1);
    MenuItems.pushBack(icon_map2);
    MenuItems.pushBack(icon_map3);

    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    return true;
}

bool Level::touchLocation(cocos2d::Touch* touch,cocos2d::Event* event)
{
    CCLOG("onTouchBegan x =%f,y= %f", touch->getLocation().x+origin.x, touch->getLocation().y+origin.y);
    return true;
}
void Level::goToGameScene(cocos2d::Ref* psender)
{
    SceneManager::getInstance()->replaceScene(GAMEPLAY_SCENE);
}
void Level::menuCloseCallback(cocos2d::Ref* pSender)
{
    SceneManager::getInstance()->replaceScene(MENU_SCENE);
}