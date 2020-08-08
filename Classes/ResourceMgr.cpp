#include "ResourceMgr.h"

ResourceMgr* ResourceMgr::instance;
ResourceMgr* ResourceMgr::getInstance()
{	
    if(instance == nullptr)
        instance = new ResourceMgr();
    return instance;
}
void ResourceMgr::Init()
{
    ssize_t size;
    log("File is json 111-------");
    string content = FileUtils::getInstance()->getStringFromFile("res.json");
    
    log("File is json  222------- %s, ", content.c_str());

    m_document.Parse(content.c_str());
    if(m_document.HasParseError())
    {
        log("File is null");
    }
    else
    {
        log("File is 4444");
        rapidjson::Value& level = m_document["Level"];
        log("File is 5555");
        assert(level.IsArray());
        for (rapidjson::Value::ConstValueIterator itr = level.Begin(); itr != level.End(); ++itr) {
            const rapidjson::Value& lv = *itr;
            assert(lv.IsObject()); // each attribute is an object
            if(lv.IsObject())
            {
                log("File is enemys - %d: towers - %d: map - %s", lv["enemys"].GetInt(), lv["towers"].GetInt(), lv["map"].GetString());
            }
        }
    }
    
}

int ResourceMgr::getNumOfEnemy()
{
    int num = m_document["Level"]["enemys"].GetInt();
    return num;
}

string ResourceMgr::getMap()
{

    return m_document["Level"]["map"].GetString();
}

string ResourceMgr::getTower(int id)
{
    return m_document["Level"]["towerSprite"][id].GetString();
}


void ResourceMgr::checkMap()
{
    if(m_document["Level"]["map"].IsString())
    {
        CCLOG("MAP address======== %s",m_document["Level"]["map"].GetString());
    }else
    {
        CCLOG("MAP address ======= null");
    }
    
}
