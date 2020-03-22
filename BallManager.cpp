#include "BallManager.h"
#include "BlockManager.h"

BallManager* BallManager::instance = nullptr;

BallManager::BallManager()
{
	m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	f_Gage_In = 0;
}

BallManager::~BallManager()
{
	//m_BallList.clear();
}

void BallManager::Create_BallNum(Ref * _ref)
{
	m_Ref = _ref;

	i_ShootEnableBall = m_MaxCount;
	iScore = 0;

	//Gage_BG
	Spr_Gage_BG = Sprite::create("Images/Gage_BG.png");
	Spr_Gage_BG->setAnchorPoint(Point(0, 0));
	Spr_Gage_BG->setPosition(m_ScreenSize.x * 0.65f, m_ScreenSize.y* 0.8f);
	((Scene*)_ref)->addChild(Spr_Gage_BG);

	//Gage_IN
	Spr_Gage_In = Sprite::create("Images/Gage_In.png");
	Spr_Gage_In->setAnchorPoint(Point(0, 0));
	Spr_Gage_In->setScaleX(0);
	Spr_Gage_In->setPosition(m_ScreenSize.x * 0.65f, m_ScreenSize.y* 0.803f);
	((Scene*)_ref)->addChild(Spr_Gage_In);

	//BallSpr
	Spr_BallNum = Sprite::create("Images/Ball_Normal.png");
	Spr_BallNum->setPosition(m_ScreenSize.x * 0.65f, m_ScreenSize.y* 0.86f);
	((Scene*)_ref)->addChild(Spr_BallNum);

	//ScreenNumberOfBall
	BallNumLabel = Label::createWithSystemFont("0", "", 30, Size(800, 200)/*, TextHAlignment::RIGHT, TextVAlignment::CENTER*/);
	BallNumLabel->setColor(Color3B(0, 0, 0));
	BallNumLabel->enableBold();
	BallNumLabel->setPosition(m_ScreenSize.x * 0.49f, m_ScreenSize.y* 0.7f);
	BallNumLabel->setAnchorPoint(Vec2(0, 0));
	((Scene*)_ref)->addChild(BallNumLabel);

	//BallEnableLabel
	Lab_BallEnableBall = Label::createWithSystemFont("BALL", "", 30, Size(800, 200)/*, TextHAlignment::RIGHT, TextVAlignment::CENTER*/);
	Lab_BallEnableBall->setColor(Color3B(0, 0, 0));
	Lab_BallEnableBall->enableBold();
	Lab_BallEnableBall->setPosition(m_ScreenSize.x * 0.7f, m_ScreenSize.y* 0.67f);
	Lab_BallEnableBall->setAnchorPoint(Vec2(0, 0));
	((Scene*)_ref)->addChild(Lab_BallEnableBall);

	//BallEnableNumber
	Lab_BallEnableBallNum = Label::createWithSystemFont("0", "", 30, Size(800, 200)/*, TextHAlignment::RIGHT, TextVAlignment::CENTER*/);
	Lab_BallEnableBallNum->setColor(Color3B(0, 0, 0));
	Lab_BallEnableBallNum->enableBold();
	Lab_BallEnableBallNum->setPosition(m_ScreenSize.x * 0.85f, m_ScreenSize.y* 0.67f);
	Lab_BallEnableBallNum->setAnchorPoint(Vec2(0, 0));
	((Scene*)_ref)->addChild(Lab_BallEnableBallNum);

}

void BallManager::Set_BallNum(int _score)
{	
	iScore += _score;

	string _scoreString = StringUtils::format("%d", iScore);

	BallNumLabel->setString(_scoreString);
}

void BallManager::Create_BallList(Ref *_ref)
{
	m_BallList.clear();

	for (int i = 0; i < m_MaxCount; i++)
	{
		Ball *_Ball = new Ball();
		_Ball->Create_Ball(_ref, i, Vec2(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.8f));

		m_BallList.push_back(_Ball);
	}
}

void BallManager::SetBallHP()
{
}

void BallManager::Shoot_Ball(Vec2 _speed)
{
	// 2018 12 15 Shoot Delay ¡¶¿€¡ﬂ...
	list<Ball*>::iterator iter;

	for (iter = m_BallList.begin(); iter != m_BallList.end(); iter++) 
	{
		if (GageIn() == 1)
		{
			if ((*iter)->Get_IsMove() == false)
			{
				(*iter)->Shoot(_speed);
				f_Gage_In = 0;
				break;
			}
		}
	}
}

int BallManager::GageIn()
{
	//if (i_Num > 10)
	{
		if (f_Gage_In <= 1.0f)
		{
			Spr_Gage_In->setScaleX(f_Gage_In);
			f_Gage_In += 0.01;
		}

		else
		{
			Spr_Gage_In->setScaleX(f_Gage_In);
		}
	}
	//i_Num++;

	return f_Gage_In;
}

void BallManager::BallNumberOfScreen()
{
	int    BallNum = 0;
	i_ShootEnableBall = m_MaxCount;
	stringstream sstr;
	string str = sstr.str();

	stringstream sstr_BallEnableNum;
	string str_BallEnableNum = sstr_BallEnableNum.str();

	for (auto iter = m_BallList.begin(); iter != m_BallList.end(); iter++)
	{
		if ((*iter)->Get_ISBallMove() == true)
		{
			BallNum++;
		}

		sstr.str("");
		sstr << BallNum;
		string str = sstr.str();
		BallNumLabel->setString(str);
	}

	i_ShootEnableBall -= BallNum;

	sstr_BallEnableNum.str("");
	sstr_BallEnableNum << i_ShootEnableBall;
	string strBallNum = sstr_BallEnableNum.str();
	Lab_BallEnableBallNum->setString(strBallNum);

}

void BallManager::Loop()
{
	
	GageIn();
	BallNumberOfScreen();

	list<Ball*>::iterator iter;
	for (iter = m_BallList.begin(); iter != m_BallList.end(); iter++)
	{
		(*iter)->Move();
		BlockManager::GetInstance()->Block_ColliderCheck((*iter));
	}
}