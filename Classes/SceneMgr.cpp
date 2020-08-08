
#include "SceneMgr.h"



USING_NS_CC;

SceneManager* SceneManager::_instance = nullptr;

SceneManager* SceneManager::getInstance()
{
	if (_instance != nullptr)
		return _instance;

	_instance = new SceneManager();
	return _instance;
}

SceneManager::SceneManager()
	:_score(0)
	, _scoreLabel(nullptr)
{
    
}

CScene* SceneManager::createScene(int screenId)
{
	switch (screenId)
	{
    case EScene::SPLASH_SCENE:
        return HelloWorld::createScene();

	case EScene::GAMEPLAY_SCENE:
		return GameScene::createScene();

	case EScene::MENU_SCENE:
		return MenuScene::createScene();

	/*case EScene::GAMEOVER_SCENE:
		return GameoverScene::createScene();

	case EScene::UI_SCENE:
		return UIScene::createScene();
	case EScene::SETTING_SCENE:
		return SettingScene::createScene();
	case EScene::CREDIT_SCENE:
		return CreditScene::createScene();*/

	}

	return nullptr;
}

CScene* SceneManager::createStartScene()
{
	return createScene(EScene::MENU_SCENE);
}

void SceneManager::replaceScene(int sceneId)
{
	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_SCENE_DURATION, createScene(sceneId)));
}

void SceneManager::pushScene(int sceneId)
{
	Director::getInstance()->pushScene(TransitionFade::create(TRANSITION_SCENE_DURATION, createScene(sceneId)));
}

void SceneManager::popLastScene()
{
	Director::getInstance()->popScene();
}

CScene* SceneManager::getCurrentScene()
{
	return dynamic_cast<CScene*>(Director::getInstance()->getRunningScene());
}

void SceneManager::increaseScore()
{

}

void SceneManager::reset()
{
	_score = 0;
}
