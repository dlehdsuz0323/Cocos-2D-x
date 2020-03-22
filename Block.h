#pragma once
#include "cocos2d.h"
#include <iostream>
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace std;
using namespace CocosDenshion;

class Block
{
public:
	Block();
	~Block();

	void Create_Block(Ref *_ref, Vec2 _pos);
	bool CollisionCheck(Rect _ballRect);
	Rect Get_Rect();
	void Set_Position(Vec2 _speed);
	bool GetBlockActive();
	int  GetBlockActiveNum(Ref *_ref, Vec2 _pos);


private:
	Ref		 *m_Ref;
			 
	Vec2	 m_ScreenSize;

	Sprite	*m_Block;
	Sprite	*m_HpSprite;
	bool 	 b_BlockActive;
	int  	 i_BlockActiveNum;
	int		 m_Hp;

};