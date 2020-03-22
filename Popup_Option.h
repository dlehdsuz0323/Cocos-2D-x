#pragma once
#include "cocos2d.h"
#include <list>

USING_NS_CC;
using namespace std;

class Popup_Option : public cocos2d::CCLayer
{
public:
	Popup_Option(ccMenuCallback _firstSel);
	~Popup_Option();

	//void Show_Popup();
	void Close();
private:
	static Popup_Option* instance;	

	bool m_IsBgm;
	bool m_IsSound;

	Sprite *m_BlackBG;
	Sprite *m_BG;

	MenuItemImage *m_Bgm;
	MenuItemImage *m_Sound;
	MenuItemImage *m_Close;
	Menu *m_Menu;

	void Set_BGM();
	void Set_SOUND();
};