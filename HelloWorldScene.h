#include "cocos2d.h"

USING_NS_CC;
using namespace std;

class HelloWorld : public cocos2d::Scene
{
private:
	Vec2 m_ScreenSize;

	Sprite* m_BG;
	Sprite *m_ShootLine[5];

	Sprite* m_DieLine[20];

	float m_Angle;
	Vec2 m_BallSpeed;

	int m_ScoreNum;

	void Loop(float f);
public:
    static Scene* createScene();

    virtual bool init();
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);

	EventListenerTouchOneByOne* listener;

	void onEnter();
	void onExit();
	bool onTouchBegan(Touch* touch, Event *event);
	void onTouchMoved(Touch* touch, Event *event);
	void onTouchEnded(Touch* touch, Event *event);

	float getAngle(float x1, float y1, float x2, float y2);
};