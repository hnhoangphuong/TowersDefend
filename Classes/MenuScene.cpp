#include "MenuScene.h"

USING_NS_CC;

CScene* MenuScene::createScene()
{
    return MenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MenuSceneScene.cpp\n");
}

void MenuScene::goToSettingScene(cocos2d::Ref* pSender)
{
    SceneManager::getInstance()->replaceScene(SETTING_SCENE);
}

void MenuScene::goToCreditScene(cocos2d::Ref* pSender)
{
    SceneManager::getInstance()->replaceScene(CREDIT_SCENE);
}

void MenuScene::goToGameScene(cocos2d::Ref* pSender)
{
    SceneManager::getInstance()->replaceScene(GAMEPLAY_SCENE);
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!CScene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto closeItem = MenuItemImage::create(
                                           "button_close.png",
                                           "button_close.png",
                                           CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
    
    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'button_close.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }

    // create menu, it's an autorelease object
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    //Background
    auto backGround = Sprite::create("UI/back_ground.png");
    backGround->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    backGround->setPosition(Vec2((0 + origin.x), 0 + origin.y));
    this->addChild(backGround, 0);
    //BUTTONS
    auto playBt = MenuItemImage::create("UI/play_button.png","UI/play_button.png", CC_CALLBACK_1(MenuScene::goToGameScene, this));
    playBt->setPosition(Vec2((origin.x + visibleSize.width / 2), (origin.y + visibleSize.height / 2)));
    auto settingBt = MenuItemImage::create("UI/play_button.png", "UI/play_button.png", CC_CALLBACK_1(MenuScene::goToSettingScene, this));
    settingBt->setPosition(Vec2((origin.x + visibleSize.width - settingBt->getContentSize().width / 2), (origin.y + visibleSize.height - settingBt->getContentSize().height / 2)));
    auto creditBt = MenuItemImage::create("UI/play_button.png", "UI/play_button.png", CC_CALLBACK_1(MenuScene::goToCreditScene, this));
    creditBt->setPosition(Vec2((origin.x + visibleSize.width / 2), (origin.y + visibleSize.height / 2 - 200)));
    this->addChild(playBt, 2);
    this->addChild(settingBt, 2);
    this->addChild(creditBt, 2);
    return true;
}


void MenuScene::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    /*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() as given above,instead trigger a custom event created in RootViewController.mm as below*/

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);



}
