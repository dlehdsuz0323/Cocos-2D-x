#pragma once
#include "cocos2d.h"
#include <iostream>
USING_NS_CC;
using namespace std;

class ScoreManager
{
private:
	ScoreManager();
	~ScoreManager();

	static ScoreManager* instance;

	Ref *m_Ref;
	Vec2 m_ScreenSize;
	FILE *file;

	Label *m_Title_Score;
	Label *m_Score;
	int m_ScoreNum;

	Label *Title_HighScore;
	Label *HighScore;
	int HighScoreNum;

public:
	static ScoreManager* GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new ScoreManager();
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

	void Create_Score(Ref *_ref);
	void Set_Score(int _score);
	void Set_HighScore(int _score);
	int Get_Score();
	int Get_HighScore();
};


