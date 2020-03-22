#pragma once
#include "cocos2d.h"
#include "Option.h"
#include <iostream>

USING_NS_CC;
using namespace std;

class MainMenu : public cocos2d::Scene
{
private:

	static MainMenu* instance;

	Vec2			 m_ScreenSize;
	
	Sprite			*m_BG;
		
	MenuItemImage	*m_PlayButton;
	MenuItemImage	*m_OptionButton;
	Menu			*m_Menu;
	Sprite			*Spr_MainTitle[7];

	Option			*m_OptionPopup;
public:
#pragma region Sigleton
	static MainMenu* GetInstance()
	{
		if(instance == nullptr)
		{
			instance = new MainMenu();
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
	CREATE_FUNC(MainMenu);

	virtual bool init();

	void Set_Play();
	void Show_Option();
	void Close_Option();
	void Show_BackGround(float t);
};