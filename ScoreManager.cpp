#include "ScoreManager.h"


ScoreManager* ScoreManager::instance = nullptr;

ScoreManager::ScoreManager()
{
	m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	//cout << UserDefault::getInstance()->getXMLFilePath();
}

ScoreManager::~ScoreManager()
{
	UserDefault::getInstance()->flush();

	//delete m_BlockSet;
	//m_BlockSet = NULL;
}

void ScoreManager::Create_Score(Ref *_ref)
{
	m_Ref = _ref;
	 
	m_ScoreNum = 0;

	m_Title_Score = Label::createWithSystemFont("Score", "", 30, Size(300, 200), TextHAlignment::LEFT, TextVAlignment::CENTER);
	m_Title_Score->setColor(Color3B(0, 0, 0));
	m_Title_Score->enableBold();
	m_Title_Score->setPosition(m_ScreenSize.x * 0.5f - 250, m_ScreenSize.y*0.8f);
	m_Title_Score->setAnchorPoint(Vec2(0, 0));
	((Scene*)_ref)->addChild(m_Title_Score);

	m_Score = Label::createWithSystemFont("0", "", 30, Size(300, 200), TextHAlignment::LEFT, TextVAlignment::CENTER);
	m_Score->setColor(Color3B(0, 0, 0));
	m_Score->enableBold();
	m_Score->setPosition(m_ScreenSize.x * 0.7f - 250, m_ScreenSize.y*0.8f);
	m_Score->setAnchorPoint(Vec2(0, 0));
	((Scene*)_ref)->addChild(m_Score);

	Title_HighScore = Label::createWithSystemFont("High Score", "", 30, Size(300, 200), TextHAlignment::RIGHT, TextVAlignment::CENTER);
	Title_HighScore->setColor(Color3B(0, 0, 0));
	Title_HighScore->enableBold();
	Title_HighScore->setPosition(m_ScreenSize.x * 0.3f, m_ScreenSize.y * 0.8f);
	Title_HighScore->setAnchorPoint(Vec2(0, 0));
	((Scene*)_ref)->addChild(Title_HighScore);

	HighScore = Label::createWithSystemFont("0", "", 30, Size(300, 200), TextHAlignment::RIGHT, TextVAlignment::CENTER);
	HighScore->setColor(Color3B(0, 0, 0));
	HighScore->enableBold();
	HighScore->setPosition(m_ScreenSize.x * 0.4f, m_ScreenSize.y * 0.8f);
	HighScore->setAnchorPoint(Vec2(0, 0));
	((Scene*)_ref)->addChild(HighScore);


	HighScoreNum = UserDefault::getInstance()->getIntegerForKey("HighScore", HighScoreNum);
	string _scoreString = StringUtils::format("%d", HighScoreNum);
	HighScore->setString(_scoreString);
}

void ScoreManager::Set_Score(int _score)
{
	m_ScoreNum += _score;
	string _scoreString = StringUtils::format("%d", m_ScoreNum);
	m_Score->setString(_scoreString);

	if (m_ScoreNum > HighScoreNum)
	{
		HighScoreNum = m_ScoreNum;
		string _scoreString = StringUtils::format("%d", m_ScoreNum);
		HighScore->setString(_scoreString);
		UserDefault::getInstance()->setIntegerForKey("HighScore", HighScoreNum);
	}
		
}

void ScoreManager::Set_HighScore(int _score)
{
	UserDefault::getInstance()->setIntegerForKey("HighScore", m_ScoreNum);
}

int ScoreManager::Get_Score()
{
	return m_ScoreNum;
}

int ScoreManager::Get_HighScore()
{
	return HighScoreNum;
}




