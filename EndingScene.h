#pragma once
#include "cocos2d.h"
#include <iostream>
#include "ScoreManager.h"

USING_NS_CC;
using namespace std;

class EndingScene: public cocos2d::Scene
{
private:
	static EndingScene* instance;

	Vec2			     m_ScreenSize;
	MenuItemImage		*M_MainMenuSceneChange;
	Menu		    	*m_Menu;
	Sprite			    *m_BG;

	Label			    *m_Title_Score;
	Label			    *m_Score;
	int				     m_ScoreNum;
					    
	Label			    *Title_HighScore;
	Label			    *HighScore;
	int				     HighScoreNum;
public:
#pragma region Singleton
	static EndingScene* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new EndingScene();
			atexit(release_instance);
		}
		return instance;
	}

	static void release_instance()
	{
		if (instance)
		{
			delete instance;
			instance = nullptr;
		}
	}
#pragma endregion

	static Scene* createScene();
	CREATE_FUNC(EndingScene);

	bool init();
	void SetMainMenu();
};

