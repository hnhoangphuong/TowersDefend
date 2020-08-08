#pragma once

#include "cocos2d.h"
#include "Enemy.h"
#include "json/rapidjson.h"
#include "json/document.h"
USING_NS_CC;
using namespace std;
using namespace rapidjson;

class ResourceMgr
{
public:
    void Init();
    static ResourceMgr* getInstance();
    int getNumOfEnemy();
    string getMap();
    string getTower(int id);
    void checkMap();
private:
	static ResourceMgr * instance;
    Document m_document;
};
