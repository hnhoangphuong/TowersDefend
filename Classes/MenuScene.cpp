#include "MenuScene.h"
#include "SimpleAudioEngine.h"
#include "GameScene.h"

USING_NS_CC;

Scene*MenuScene::createScene()
{
    return MenuScene::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in mnMenu.cpp\n");
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Scene::init())
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
        "CloseNormal.png",
        "CloseSelected.png",
        CC_CALLBACK_1(MenuScene::menuCloseCallback, this));
    auto playBt=MenuItemImage::create("blue_button11.png","blue_button12.png",CC_CALLBACK_1(MenuScene::PlayClick,this));
    playBt->setPosition(Vec2(visibleSize.height/2,visibleSize.width/2));
    
  
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width / 2;
        float y = origin.y + closeItem->getContentSize().height / 2;
        closeItem->setPosition(Vec2(x, y));
    
    
    // create menu, it's an autorelease object
    auto menu2=Menu::create(playBt,NULL);
    menu2->setPosition(Vec2::ZERO);
    this->addChild(menu2,1);
    auto menu = Menu::create(closeItem,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

    auto label = Label::createWithTTF("MAIN MENU", "fonts/Marker Felt.ttf", 30);
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

    // add "Splash" splash screen"

   /* auto TouchListener = EventListenerTouchOneByOne::create();
    TouchListener->onTouchBegan = CC_CALLBACK_2(MenuScene::PlayClick, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(TouchListener,this);
    */
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
void MenuScene::PlayClick(Ref* pSender)
{
    auto mnsc = GameScene::createScene();
    Director::getInstance()->replaceScene(mnsc);
}