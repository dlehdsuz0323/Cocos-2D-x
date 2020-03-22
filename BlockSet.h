#pragma once

#include "cocos2d.h"
#include "Block.h"
#include "Ball.h"
#include <list>
#include <iostream> 

#define BLOCKWIDTH 10

USING_NS_CC;
using namespace std;

class BlockSet	
{
public:
	BlockSet();
	~BlockSet();

	void Create_Block(Ref *_ref, int _line);
	void Create_MainMenuBlockSet(Ref *_ref, int _line);
	bool Block_ColliderCheck(Ball* _ball);
	int ClearBlockSet(Ref *_ref, int _line);
	void Move(Vec2 _speed);

private:

	bool		   IsCollision;
	Vec2		   m_ScreenSize;
	Ref			  *m_Ref;
	list<Block*>   m_BlockList;
	int			   i_ActiveBlock;

	//int m_Hp;
};