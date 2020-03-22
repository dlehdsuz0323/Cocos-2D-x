#pragma once
#include "cocos2d.h"
#include "Ball.h"
#include <math.h>
#include <list>
#include <iostream>

using namespace std;

USING_NS_CC;
using namespace std;

class BallManager
{
private:
	BallManager();
	~BallManager();

	static BallManager* instance;

	Vec2 m_ScreenSize;

	int			  m_MaxCount = 5;
	int			  i_ShootEnableBall;
	int			  m_CurCountIndex;
	list<Ball*>   m_BallList;
	int			  iScore;
	float		  f_Gage_In;

	Sprite*		  Spr_BallNum;
	Sprite*		  Spr_Gage_BG;
	Sprite*		  Spr_Gage_In;
				 
	Label*		  BallNumLabel;
	Label*		  Lab_BallEnableBall;
	Label*		  Lab_BallEnableBallNum;
	Ref*		  m_Ref;


public:
	static BallManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new BallManager();
			atexit(release_instance);
		}
		return instance;
	}

	static void release_instance() {
		if (instance) {
			delete instance;
			instance = nullptr;
		}
	}

	void   Create_BallNum(Ref *_ref);
	void   Set_BallNum(int _score);		   
	void   Create_BallList(Ref *_ref);
	void   SetBallHP();
	void   Shoot_Ball(Vec2 _speed);
	int    GageIn();
	void   BallNumberOfScreen();

	void Loop();
};



