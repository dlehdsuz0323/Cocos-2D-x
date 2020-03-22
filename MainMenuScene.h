#include "cocos2d.h"
#include "Popup_Option.h"

USING_NS_CC;
using namespace std;

class MainMenuScene : public cocos2d::Scene
{
private:
	Vec2 m_ScreenSize;

	Sprite* m_BG;

	Sprite* m_Title_D;
	Sprite* m_Title_R;
	Sprite* m_Title_O;
	Sprite* m_Title_B;
	Sprite* m_Title_A;
	Sprite* m_Title_L;
	Sprite* m_Title_L2;

	MenuItemImage *m_PlayButton;
	MenuItemImage *m_OptionButton;
	Menu *m_Menu;

	Popup_Option *m_Popup_Option;

public:
	static Scene* createScene();

	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MainMenuScene);

	void Set_Play();
	void Show_Option();
	void Close_Option();

	
	/*cocos2d::EventListenerTouchOneByOne* listener;

	void onEnter();
	void onExit();
	bool onTouchBegan(Touch* touch, Event *event);
	void onTouchMoved(Touch* touch, Event *event);
	void onTouchEnded(Touch* touch, Event *event);

	float getAngle(float x1, float y1, float x2, float y2);*/
};