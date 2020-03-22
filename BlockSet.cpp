#include "BlockSet.h"


BlockSet::BlockSet()
{
	m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
}

BlockSet::~BlockSet()
{
	m_BlockList.clear();
}

void BlockSet::Create_Block(Ref *_ref, int _line)
{
	i_ActiveBlock = 0;
	m_Ref = _ref;
	m_BlockList.clear();
	// Width Block
	for (int i = 0; i < BLOCKWIDTH; i++)
	{ 
		Block* _block = new Block();
		_block->Create_Block(m_Ref, Vec2(m_ScreenSize.x*0.26f - 100 + (50 * i), m_ScreenSize.y*0.26f - (30 * _line)));

		m_BlockList.push_back(_block);
	}

	// 씬에 뿌려진 객체 삭제(BlockSet 클래스안에는 생성된 블럭 그대로 있음)
	// 파괴된 블럭들만 씬에서 삭제후 모두 파괴되면 새로운 블럭셋 조합해서 씬에 뿌림
	//ClearBlockSet();
}

void BlockSet::Create_MainMenuBlockSet(Ref * _ref, int _line)
{
	i_ActiveBlock = 0;
	m_Ref = _ref;
	m_BlockList.clear();
	// Width Block
	for (int i = 0; i < 15; i++)
	{
		Block* _block = new Block();
		_block->Create_Block(m_Ref, Vec2(m_ScreenSize.x*0.26f - 120 + (50 * i), m_ScreenSize.y*0.26f - (30 * _line)));

		m_BlockList.push_back(_block);
	}
}

bool BlockSet::Block_ColliderCheck(Ball* _ball)
{
	list<Block*>::iterator iter;
	IsCollision = false;

	for (iter = m_BlockList.begin(); iter != m_BlockList.end(); iter++)
	{
		if ((*iter)->CollisionCheck(_ball->Get_Rect()))
		{
			Rect _blockRect = (*iter)->Get_Rect();
			Vec2 _ballPos = _ball->Get_Pos();
			Vec2 _speed = _ball->Get_Speed();

			// 윗면 충돌
			if (_speed.y > 0 &&
				_ballPos.y >= (_blockRect.origin.y + _blockRect.size.height))
			{
				_speed = Vec2(_speed.x, -_speed.y);
				IsCollision = true;
			}

			// 아랫면 충돌
			else if (_speed.y < 0 &&
				_ballPos.y <= _blockRect.origin.y)
			{
				_speed = Vec2(_speed.x, -_speed.y);
				IsCollision = true;
			}

			// 왼쪽면 충돌
			else if (_speed.x < 0 &&
				_ballPos.x <= _blockRect.origin.x)
			{
				_speed = Vec2(-_speed.x, _speed.y);
				IsCollision = true;
			}

			// 오른쪽면 충돌
			else if (_speed.x > 0 &&
				_ballPos.x >= (_blockRect.origin.x + _blockRect.size.width))
			{
				_speed = Vec2(-_speed.x, _speed.y);
				IsCollision = true;
			}

			_ball->Set_Speed(_speed);

			if (IsCollision == true)
			{
				IsCollision = false;
				return true;
				break;
			}



			/*_ball->Reset();*/
		}
	}
}



int BlockSet::ClearBlockSet(Ref *_ref, int _line)
{
	i_ActiveBlock = 0;

	m_Ref = _ref;
	//m_BlockList.clear();

	//for (auto iter = m_BlockList.begin(); iter != m_BlockList.end(); iter++)
	{
		//if ((*iter)->GetBlockActive() == false)
		{
			i_ActiveBlock++;
		//	if (i_ActiveBlock == BLOCKWIDTH)
			{
				for (int i = 0; i < BLOCKWIDTH; i++)
				{
					Block* _block = new Block();
					_block->Create_Block(m_Ref, Vec2(m_ScreenSize.x*0.26f - 100 + (50 * i), m_ScreenSize.y*0.26f - (30 * _line)));

					m_BlockList.push_back(_block);
				}
				return i_ActiveBlock;
			}
		}
	}
}




void BlockSet::Move(Vec2 _speed)
{
	list<Block*>::iterator iter;

	for (iter = m_BlockList.begin(); iter != m_BlockList.end(); iter++)
	{
		(*iter)->Set_Position(_speed);
	}
}