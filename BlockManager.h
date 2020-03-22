#pragma once
#include "BlockSet.h"
#include <iostream>

using namespace std;


class BlockManager
{
private:
	BlockManager();
	~BlockManager();

	static BlockManager* instance;

	list<BlockSet*> m_BlockSetList;
	int				i_BlockHEIGHT;
	int				num;

public:
	bool m_IsGameOver = false;
	bool isOn = true;

	static BlockManager* GetInstance()
	{ 
		if (instance == nullptr)
		{
			instance = new BlockManager();
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

	void Create_BlockSet(Ref *_ref);
	void Block_ColliderCheck(Ball* _ball);
	void ClearBolck(Ref *_ref);
	void Move(Ref *_ref);
	void Create_MainMenuBlock(Ref *_ref);
};




