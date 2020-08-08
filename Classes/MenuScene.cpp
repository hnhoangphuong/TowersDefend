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
   
    Vector<MenuItem*> MenuItems;
    // create menu, it's an autorelease object
    // auto menu = Menu::create(closeItem, NULL);
    // menu->setPosition(Vec2::ZERO);
    // this->addChild(menu, 1);
    //Background
    auto backGround = Sprite::create("UI/back_ground.png");
    backGround->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    backGround->setPosition(Vec2((0 + origin.x), 0 + origin.y));
    this->addChild(backGround, 0);
    //BUTTONS
    auto playBt = MenuItemImage::create("UI/button_play.png","UI/button_play.png", [&](Ref* sender){
                                              goToGameScene(sender);
                                        });
    playBt->setPosition(Vec2((origin.x + visibleSize.width / 2), (origin.y + visibleSize.height / 2 - 50)));
    auto settingBt = MenuItemImage::create("UI/button_settings.png", "UI/button_settings.png", [&](Ref* sender){
                                              goToSettingScene(sender);
                                        });
    settingBt->setPosition(Vec2((origin.x + visibleSize.width - settingBt->getContentSize().width / 2), (origin.y + visibleSize.height - settingBt->getContentSize().height / 2)));
    auto creditBt = MenuItemImage::create("UI/button_credit.png", "UI/button_credit.png", CC_CALLBACK_1(MenuScene::goToCreditScene, this));
    creditBt->setPosition(Vec2((origin.x + visibleSize.width / 2), (origin.y + visibleSize.height / 2 - 300)));
    

    
    auto btn_close = MenuItemImage::create(
                                           "UI/button_close.png",
                                           "UI/button_close.png",
                                           [&](Ref* sender){
                                              menuCloseCallback(sender);
                                        });
    if (btn_close == nullptr || btn_close->getContentSize().width <= 0 || btn_close->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - btn_close->getContentSize().width/2;
        float y = origin.y + btn_close->getContentSize().height/2;
        btn_close->setPosition(Vec2(x,y));
    }
    MenuItems.pushBack(btn_close);
    MenuItems.pushBack(playBt);
    MenuItems.pushBack(settingBt);
    MenuItems.pushBack(creditBt);

    

    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);



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
