#ifndef __SCENE_MANAGER_H__
#define __SCENE_MANAGER_H__
 
#include "Definition.h"
#include "CScene.h"
#include "HelloWorldScene.h"
#include "GameScene.h"


enum EScene
{
    SPLASH_SCENE,
	GAMEPLAY_SCENE,
	MENU_SCENE,
	UI_SCENE,
	GAMEOVER_SCENE,
};

class SceneManager
{
protected:
	static SceneManager* _instance;

	SceneManager();
	SceneManager(const SceneManager& other) {}
	virtual ~SceneManager() {}

public:
	static SceneManager* getInstance();

	CScene* createScene(int sceneId);
	CScene* createStartScene();
	CScene* getCurrentScene();
	
	void replaceScene(int sceneId);
	void pushScene(int sceneId);
	void popLastScene();
	void increaseScore();

	void reset();

	CC_SYNTHESIZE_READONLY(int, _score, Score);
	CC_SYNTHESIZE(cocos2d::Label*, _scoreLabel, ScoreLabel);
};

#endif // __SCENE_MANAGER_H__
