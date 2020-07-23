#ifndef _GAMEMANAGER_H_
#define _GAMEMANAGER_H_

#include "cocos2d.h"
#include "Enemy.h"
USING_NS_CC;

class GameManager
{
public:
    void CreateGameManager(int slot);
	static void eraseAll();
	
    Vector<Enemy*> enemyVector;
    static GameManager* getInstance();
	void setInstance(int tag);

    char SLOTX_ISEXIT[20];

    
	char LEVELX_ISDOWN[20];

	
	char LEVELX_STARNUM[20];
	
	char SLOTX_STARLEFT[20];
	
	char SLOTX_DOWNCOUNT[20];

	
	char LEVELX_NEWDOWN[20];

	
	char SLOTX_STAR[20];


	char SLOTX_SHOP[20];

	
	char SLOTX_GEM[20];
	int SLOTNUM;
	
	int MONEY;
	
	int LIFE;
	
	int LEVEL;

private:
	static GameManager * instance;

};

#endif //_GAMEMANAGER_H_