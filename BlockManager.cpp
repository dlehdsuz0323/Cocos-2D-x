#include "BlockManager.h"
BlockManager* BlockManager::instance = nullptr;

BlockManager::BlockManager()
{
	//m_IsGameOver = false;
	i_BlockHEIGHT = 1;
	num = 1;
}

BlockManager::~BlockManager()
{
	//m_BlockSetList.clear();
	//delete m_BlockSet;
	//m_BlockSet = NULL;
}

void BlockManager::Create_BlockSet(Ref *_ref)
{
	m_BlockSetList.clear();

	for (int i = 0; i < 2; i++)
	{
		BlockSet* _BlockSet = new BlockSet();
		_BlockSet->Create_Block(_ref, i);

		m_BlockSetList.push_back(_BlockSet);
	}
}

void BlockManager::Block_ColliderCheck(Ball* _ball)
{
	/*if (m_IsGameOver)
		return;*/
	list<BlockSet*>::iterator iter;

	for (iter = m_BlockSetList.begin(); iter != m_BlockSetList.end(); iter++)
	{
		if ((*iter)->Block_ColliderCheck(_ball) == true)
		{
			_ball->CollisionCheck();
		}
	}
}

void BlockManager::ClearBolck(Ref *_ref)
{
	//CCAction *action_1 = CCDelayTime::create(3.0f);    // ½Ã°£
	CCDelayTime *delay = CCDelayTime::create(25.0f);

	

	//for (auto iter = m_BlockSetList.begin(); iter != m_BlockSetList.end(); iter++)
	{
		//m_BlockSetList.clear();
		//cout << "BLOCK CLEAR!!" << endl;
		
	
		if (isOn == true)
		{
			if(num > 70)
			//for (int i = 1; i < 3; i++)
			{
				num = 0;
				i_BlockHEIGHT++;
				BlockSet* _BlockSet = new BlockSet();
				_BlockSet->ClearBlockSet(_ref, i_BlockHEIGHT);

				m_BlockSetList.push_back(_BlockSet);
			}
			//isOn = false;
		}
		num++;

	}
}

void BlockManager::Move(Ref *_ref)
{
	if (m_IsGameOver == true)
		return;

	ClearBolck(_ref);

	list<BlockSet*>::iterator iter; 

	for (iter = m_BlockSetList.begin(); iter != m_BlockSetList.end(); iter++)
	{
		(*iter)->Move(Vec2(0, 0.1f));
	}
	
	

	//if (isOn = true)
	//{
	//	Ref *ref;
	//	BlockSet* _BlockSet = new BlockSet();
	//	_BlockSet->Create_Block(ref, 1);
	//	m_BlockSetList.push_back(_BlockSet);
	//	isOn = false;
	//}

	//m_BlockSetList
}

void BlockManager::Create_MainMenuBlock(Ref * _ref)
{
	m_BlockSetList.clear();

	for (int i = 0; i < 10; i++)
	{
		BlockSet* _BlockSet = new BlockSet();
		//_BlockSet->Create_Block(_ref, i);
		_BlockSet->Create_MainMenuBlockSet(_ref, i);

		m_BlockSetList.push_back(_BlockSet);
	}

//		BlockManager::Move(_ref);
	
}
