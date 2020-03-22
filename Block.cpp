#include "Block.h"
#include "ScoreManager.h"
#include "MainMenuScene.h"
#include "EndingScene.h"

//#include "BlockManager.h"
//#include "BallManager.h"

Block::Block()
{	
	SimpleAudioEngine::getInstance()->preloadEffect("Sound/Buzzer Wrong Answer.wav");
	//m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	//srand((unsigned int(time(NULL))));
}

Block::~Block()
{
	/*((Scene*)m_Ref)->removeChild(m_Block, true);
	m_Block = nullptr;*/
}

void Block::Create_Block(Ref *_ref, Vec2 _pos)
{
	m_Ref = _ref;
	i_BlockActiveNum = 0;

	int _randBlock = rand() % 5;
	int i_RandHp = rand()  % 9 + 1;

	m_Hp = i_RandHp;

	if (_randBlock == 0)
		m_Block = Sprite::create("Images/Nomal_Block_1x1.png");
	else if (_randBlock == 1)
		m_Block = Sprite::create("Images/Nomal_Block_1x1_2.png");
	else if (_randBlock == 2)
		m_Block = Sprite::create("Images/Nomal_Block_1x1_3.png");
	else if (_randBlock == 3)
		m_Block = Sprite::create("Images/Nomal_Block_1x1_4.png");
	else if (_randBlock == 4)
		m_Block = Sprite::create("Images/Nomal_Block_1x1_5.png");


	m_Block->setOpacity(255);
	m_Block->setPosition(_pos);
	b_BlockActive = true;

	((Scene*)m_Ref)->addChild(m_Block);

	string _hpString = StringUtils::format("Images/Num_%d.png", m_Hp);
	m_HpSprite = Sprite::create(_hpString);
	m_HpSprite->setPosition(m_Block->getContentSize().width * 0.5f, m_Block->getContentSize().height * 0.6f);
	m_HpSprite->getTexture()->setAliasTexParameters();

	m_Block->addChild(m_HpSprite);
}

bool Block::CollisionCheck(Rect _ballRect)
{
	if (m_Hp > 0)
	{
		if (m_Block->boundingBox().intersectsRect(_ballRect))
		{
			m_Hp--;

			if (m_Hp <= 0)
			{
				ScoreManager::GetInstance()->Set_Score(1);
				m_Block->setOpacity(0);
				m_HpSprite->setOpacity(0);
				b_BlockActive = false;
				i_BlockActiveNum++;

			}
			else
			{
				string _hpString = StringUtils::format("Images/Num_%d.png", m_Hp);

				Image* img = new Image();
				img->initWithImageFile(_hpString);

				Texture2D* _texture = new Texture2D();
				_texture->setAliasTexParameters();
				_texture->initWithImage(img);

				m_HpSprite->setTexture(_texture);
			}

			return true;
		}
	}

	return false;
}

Rect Block::Get_Rect()
{
	return m_Block->boundingBox();
}

void Block::Set_Position(Vec2 _speed)
{
	m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();

	if (m_Hp > 0)
	{
		m_Block->setPosition(m_Block->getPosition() + _speed);
	
		if (m_Block->getBoundingBox().origin.y + m_Block->getBoundingBox().size.height >= m_ScreenSize.y * 0.7f)
		{
			auto _InGmaeScene = EndingScene::createScene();
			Director::getInstance()->replaceScene(_InGmaeScene); // 이전 씬이 삭제대고 새로운씬이 대체 됨

			// Block Line 5 == GameOver
			cout << "Gema Over" << endl;
			SimpleAudioEngine::getInstance()->playEffect("Sound/Buzzer Wrong Answer.wav");
			SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
		}
	}
}

bool Block::GetBlockActive()
{
	if (b_BlockActive == false)
	{
		return false;
	}

	else if (b_BlockActive == true)
	{
		return true;
	}
}

int Block::GetBlockActiveNum(Ref *_ref, Vec2 _pos)
{
	m_Ref = _ref;
	m_Block->setOpacity(255);
	m_Block->setPosition(_pos);
	b_BlockActive = true;

	((Scene*)m_Ref)->addChild(m_Block);

	//cout << i_BlockActiveNum << endl;
	return b_BlockActive;
}
