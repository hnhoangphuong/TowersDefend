#include "CreditScene.h"
USING_NS_CC;

CScene* CreditScene::createScene()
{
    return CreditScene::create();
}
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in MenuSceneScene.cpp\n");
}
bool CreditScene::init()
{
    //////////////////////////////
    // 1. super init first
    if (!CScene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

   
    Vector<MenuItem*> MenuItems;
   
    //Background
    auto backGround = Sprite::create("UI/back_ground.png");
    backGround->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
    backGround->setPosition(Vec2((0 + origin.x), 0 + origin.y));
    this->addChild(backGround, 0);
    auto header=Sprite::create("UI/button_google.png");
    header->setPosition(Vec2((origin.x+header->getContentSize().width),(origin.y+visibleSize.height/2)));
    this->addChild(header,1);
    //BUTTONS
  
    

    
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
    

    auto menu = Menu::createWithArray(MenuItems);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);



    return true;
}

void CreditScene::menuCloseCallback(Ref* pSender)
{
    SceneManager::getInstance()->replaceScene(MENU_SCENE);
}