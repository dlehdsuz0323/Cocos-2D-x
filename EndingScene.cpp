#include "EndingScene.h"
#include "MainMenu.h"

Scene* EndingScene::createScene()
{
	return EndingScene::create();
}


bool EndingScene::init()
{
	if (!Scene::init())
	{
		return false;
	}

	m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();

	M_MainMenuSceneChange = MenuItemImage::create("Images/Button_Play_Pop.png",
		"Images/Button_Play_Push.png",
		CC_CALLBACK_0(EndingScene::SetMainMenu, this));
	M_MainMenuSceneChange->setPosition(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.3f);
	M_MainMenuSceneChange->setScale(2.0f);

	m_BG = Sprite::create("Images/BG_Test.png");
	m_BG->setPosition(Vec2(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.5f));
	m_BG->setColor(Color3B(255, 255, 255));
	this->addChild(m_BG);

	m_Menu = Menu::create(M_MainMenuSceneChange, nullptr);
	m_Menu->setPosition(Vec2(0, 0));
	m_Menu->setTouchEnabled(true);


	m_Title_Score = Label::createWithSystemFont("Score", "", 30, Size(300, 200), TextHAlignment::LEFT, TextVAlignment::CENTER);
	m_Title_Score->setColor(Color3B(0, 0, 0));
	m_Title_Score->enableBold();
	m_Title_Score->setPosition(m_ScreenSize.x * 0.49f, m_ScreenSize.y* 0.7f);
	m_Title_Score->setAnchorPoint(Vec2(0, 0));
	this->addChild(m_Title_Score);

	m_Score = Label::createWithSystemFont("0", "", 30, Size(300, 200), TextHAlignment::LEFT, TextVAlignment::CENTER);
	m_Score->setColor(Color3B(0, 0, 0));
	m_Score->enableBold();
	m_Score->setPosition(m_ScreenSize.x * 0.5f, m_ScreenSize.y* 0.65f);
	m_Score->setAnchorPoint(Vec2(0, 0));

	Title_HighScore = Label::createWithSystemFont("High Score", "", 30, Size(300, 200), TextHAlignment::LEFT, TextVAlignment::CENTER);
	Title_HighScore->setColor(Color3B(0, 0, 0));
	Title_HighScore->enableBold();
	Title_HighScore->setPosition(m_ScreenSize.x * 0.49f, m_ScreenSize.y* 0.6f);
	Title_HighScore->setAnchorPoint(Vec2(0, 0));
	this->addChild(Title_HighScore);

	HighScore = Label::createWithSystemFont("0", "", 30, Size(300, 200), TextHAlignment::LEFT, TextVAlignment::CENTER);
	HighScore->setColor(Color3B(0, 0, 0));
	HighScore->enableBold();
	HighScore->setPosition(m_ScreenSize.x * 0.5f, m_ScreenSize.y* 0.55f);
	HighScore->setAnchorPoint(Vec2(0, 0));

	stringstream Strs_Score;
	string       Str_Score = Strs_Score.str();

	stringstream Strs_HighScore;
	string		 Str_HighScore= Strs_HighScore.str();

	Strs_Score.str("");
	Strs_Score << ScoreManager::GetInstance()->Get_Score();
	Str_Score = Strs_Score.str();
	m_Score->setString(Str_Score);

	Strs_HighScore.str("");
	Strs_HighScore << UserDefault::getInstance()->getIntegerForKey("HighScore", HighScoreNum);
	Str_HighScore = Strs_HighScore.str();
	HighScore->setString(Str_HighScore);


	this->addChild(m_Score);
	this->addChild(HighScore);



	this->addChild(m_Menu);

	return true;
}

void EndingScene::SetMainMenu()
{
	auto _InGmaeScene = MainMenu::createScene();
	Director::getInstance()->replaceScene(_InGmaeScene);
}
