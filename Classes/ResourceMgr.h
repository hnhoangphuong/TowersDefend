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

private:
	static ResourceMgr * instance;

};
