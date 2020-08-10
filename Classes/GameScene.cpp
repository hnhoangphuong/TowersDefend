#include "GameScene.h"
//#include "SimpleAudioEngine.h"

USING_NS_CC;

CScene* GameScene::createScene()
{   
    
    return GameScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!CScene::init())
    {
        return false;
    }

    auto closeItem = MenuItemImage::create(
        "UI/button_close.png",
        "button_close.png",
        CC_CALLBACK_1(GameScene::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    //auto label = Label::createWithTTF("Game Scene", "fonts/Marker Felt.ttf", 24);
    //====================================================================================
    
    map= new MyMap();
    map->initMap();
    map->initMap1();

    // float mapRatio;
    // if(map->getMapTMX()->getContentSize().height>=this->visibleSize.height)
    // {
    //     mapRatio=this->visibleSize.height/map->getMapTMX()->getContentSize().height;
    // }else
    // {
    //     mapRatio=map->getMapTMX()->getContentSize().height/this->visibleSize.height;
    // }
    // map->setScale(mapRatio);
 
    map->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
    map->setPosition(Vec2(origin.x,origin.y));
    this->addChild(map);

    enemy1 = new Enemy();
    enemy1->setScale(0.5f);
    enemy1->spawnEnemy("4_enemy.png",Vec2(origin.x + 120 ,origin.y + 500));
    this->addChild(enemy1);

    // map->placeTower(); 
    
    this->scheduleUpdate();

    
    

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan,this);
    this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener,this);
    return true;
}   

void GameScene::update(float dt)
{
    
	// enemy1->actionMove(map->getPoint(0));       
}

void GameScene::menuCloseCallback(Ref* pSender)
{
    
    SceneManager::getInstance()->replaceScene(LEVEL_SCENE);

   
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    CCLOG("onTouchBegan x =%f,y= %f", touch->getLocation().x+origin.x, touch->getLocation().y+origin.y);
    return true;
}

