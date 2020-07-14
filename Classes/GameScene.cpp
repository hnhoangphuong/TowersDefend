
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
        "CloseNormal.png",
        "CloseSelected.png",
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

    auto label = Label::createWithTTF("Game Scene", "fonts/Marker Felt.ttf", 24);
    if (label == nullptr)
    {
        problemLoading("'fonts/Marker Felt.ttf'");
    }
    else
    {
        // position the label on the center of the screen
        label->setPosition(Vec2(origin.x + visibleSize.width / 2,
            origin.y + visibleSize.height - label->getContentSize().height));

        // add the label as a child to this layer
        this->addChild(label, 1);
    }
    enemy1 = new Enemy;
    enemy1->spawnEnemy("4_enemy.png",Vec2(visibleSize.width/2+origin.x -45,visibleSize.height-100+origin.y));
    enemy1->setScale(0.3f);
    this->addChild(enemy1);

    tower1=new Tower();
    tower1->setTower("18.png", Vec2(visibleSize.width/2+origin.x,visibleSize.height/2));
    tower1->setScale(0.6f);
    this->addChild(tower1);

    return true;
}   

void GameScene::gameUpdate(float dt)
{
  
    
    
}

void GameScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
    CCLOG("onTouchBegan x =%f,y= %f", touch->getLocation().x, touch->getLocation().y);
    auto actionMoveTo = MoveTo::create(2, Vec2(touch->getLocation().x,touch->getLocation().y));
    spriteBall->runAction(actionMoveTo); 
    return true;
}

