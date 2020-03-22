#pragma once
#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class Option : public cocos2d::CCLayer
{
public:
	Option(ccMenuCallback _firstSel);
	~Option();

	void Close();

	void Set_BGM();
	void Set_Sound();

	static Option* GetInstance()
	{
		if (instance == nullptr)
		{
			//instance = new Option();
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

private:
	static Option* instance;

	Sprite *m_BlackBG;
	Sprite *m_BG;
	
	bool m_IsBgm;
	bool m_IsSound;

	MenuItemImage *m_Bgm;
	MenuItemImage *m_Sound;
	MenuItemImage *m_Close;
	Menu *m_Menu;
};