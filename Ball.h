#pragma once

#include "cocos2d.h"
#include "SimpleAudioEngine.h"
#include <iostream>

#define BALLHP 9

USING_NS_CC;
using namespace CocosDenshion;
using namespace std;

class Ball
{
public:
	Ball();
	~Ball();
	void Create_Ball(Ref *_ref, int _index, Vec2 _pos);
	void Shoot(Vec2 _speed);

	bool Move();
	void Reset();


	Rect Get_Rect();
	int GetBallNum();
	bool Get_IsMove();
	Vec2 Get_Pos();
	Vec2 Get_Speed();
	bool Get_ISBallMove();
	int  Get_Index();

	void Set_Speed(Vec2 _speed);
	bool CollisionCheck();

private:

	Vec2 m_ScreenSize;

	Ref *m_Ref;
	int m_Index;
	Vec2 m_Start_Pos;

	Vec2 m_BallSpeed;
	int  iBallHp;
	int   BallNum;

	bool m_IsBallMove;

	Sprite* m_Ball;
	Sprite* spr_BallHP;
};