
#include "GameScene.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
Sprite* spriteBall;
Scene* GameScene::createScene()
{   
    auto scene = Scene::createWithPhysics();
    
    auto layer = GameScene::create();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
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

    /////////////////////////////
    // 3. add your codes below...

    // add a label shows "Hello World"
    // create and initialize a label

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
   
    auto edgeBody = PhysicsBody::createEdgeBox(visibleSize,PhysicsMaterial(3,0.2,0.5),2);
    auto edgeNode = Node::create();
    edgeNode->setPosition(Vec2(visibleSize.width / 2 +origin.x, visibleSize.height / 2+origin.y));
    edgeNode->setPhysicsBody(edgeBody);
    addChild(edgeNode);
    
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
   
    spriteBall = Sprite::create("ball2small.png");
    spriteBall->setPosition(Vec2(visibleSize.width * 0.3, visibleSize.height /2));
    auto spr_bodyBall = PhysicsBody::createCircle(spriteBall->getContentSize().width/2,PhysicsMaterial(0.2,0,0.3));
    spriteBall->setPhysicsBody(spr_bodyBall);

    /*spr_bodyBall->setCollisionBitmask(1);
    spr_bodyBall->setContactTestBitmask(true);*/
    //spr_bodyBall->setGravityEnable(false);
    addChild(spriteBall);
   
    auto spriteCrate = Sprite::create("crate.png");
    spriteCrate->setPosition(Vec2(visibleSize.width * 0.6, visibleSize.height*0.8));
    auto spr_bodyCrate = PhysicsBody::createBox(spriteCrate->getContentSize(),PhysicsMaterial(3,0,0.3));
    spriteCrate->setPhysicsBody(spr_bodyCrate);
    //spr_bodyCrate->setCollisionBitmask(2);
    //spr_bodyCrate->setContactTestBitmask(true);
    addChild(spriteCrate);
    
    if (spriteBall->getPosition().x >= visibleSize.width || spriteBall->getPosition().y >= visibleSize.height)
    {
        spriteBall->setPosition(Vec2(visibleSize.width * 0.3, visibleSize.height / 2));
    }
    return true;
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
