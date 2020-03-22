#include "Ball.h"

Ball::Ball()
{
	m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();
	SimpleAudioEngine::getInstance()->preloadEffect("Sound/Jump-SoundBible.wav");
	SimpleAudioEngine::getInstance()->preloadEffect("Sound/Jump-Undertale Sound Effect.wav");
}

Ball::~Ball()
{
	/*((Scene*)m_Ref)->removeChild(m_Ball, true);
	m_Ball = nullptr;*/
}

void Ball::Create_Ball(Ref *_ref, int _index, Vec2 _pos)
{
	iBallHp = BALLHP;
	m_Ref = _ref;
	m_Index = _index;
	m_Start_Pos = _pos;

	m_Ball = Sprite::create("Images/Ball_Normal.png");
	m_Ball->setOpacity(255);
	m_Ball->setPosition(_pos);

	string _hpString = StringUtils::format("Images/Num_%d.png", iBallHp);
	spr_BallHP = Sprite::create(_hpString);
	spr_BallHP->setPosition(m_Ball->getContentSize().width * 0.5f, m_Ball->getContentSize().height * 0.6f);
	spr_BallHP->getTexture()->setAliasTexParameters();
	m_Ball->addChild(spr_BallHP);


	((Scene*)m_Ref)->addChild(m_Ball);

	m_IsBallMove = false;
}

bool Ball::CollisionCheck()
{
	if (iBallHp > 0)
	{
		//if (m_Ball->boundingBox().intersectsRect(_blockRect))
		{
			iBallHp--;

			if (iBallHp <= 0)
			{
				m_Ball->setOpacity(0);
				spr_BallHP->setOpacity(0);
				Reset();
			}
			else
			{
				string _hpString = StringUtils::format("Images/Num_%d.png", iBallHp);

				Image* img = new Image();
				img->initWithImageFile(_hpString);

				Texture2D* _texture = new Texture2D();
				_texture->setAliasTexParameters();
				_texture->initWithImage(img);

				spr_BallHP->setTexture(_texture);
			}

			return true;
		}
	}
	return false;
}

void Ball::Shoot(Vec2 _speed)
{	

	m_IsBallMove = true;
	m_BallSpeed = _speed;
	SimpleAudioEngine::getInstance()->playEffect("Sound/Undertale Sound Effect.wav");
	m_Ball->setOpacity(255);
} 

bool Ball::Move()
{
	if (m_IsBallMove)
	{
		m_Ball->setPosition(m_Ball->getPosition() - m_BallSpeed);

		Rect _rect = m_Ball->boundingBox();

		// 왼쪽 벽면 충돌
		if (0 >= _rect.origin.x && _rect.origin.y >= 0)
		{
			m_BallSpeed = Vec2(-m_BallSpeed.x, m_BallSpeed.y);
			SimpleAudioEngine::getInstance()->playEffect("Sound/Jump-SoundBible.wav");
		}
		// 오른쪽 벽면 충돌
		else if (m_ScreenSize.x <= (_rect.origin.x + _rect.size.width) &&
				 _rect.origin.y >= 0)
		{
			m_BallSpeed = Vec2(-m_BallSpeed.x, m_BallSpeed.y);
			SimpleAudioEngine::getInstance()->playEffect("Sound/Jump-SoundBible.wav");
		}
		// 위쪽 벽면 충돌
		else if ((_rect.origin.y + _rect.size.height) >= m_ScreenSize.y)
		{
			m_BallSpeed = Vec2(m_BallSpeed.x, -m_BallSpeed.y);
			SimpleAudioEngine::getInstance()->playEffect("Sound/Jump-SoundBible.wav");
		}
		// 아래쪽 벽면 충돌
		else if (_rect.origin.y <= 0)
		{
			cout << "Ball Remove" << endl;
			Reset();
			return false;
		}
	}
	return true;
}

void Ball::Reset()
{
	m_Ball->setPosition(m_Start_Pos);
	iBallHp = BALLHP;
	string _hpString = StringUtils::format("Images/Num_%d.png", iBallHp);

	Image* img = new Image();
	img->initWithImageFile(_hpString);

	Texture2D* _texture = new Texture2D();
	_texture->setAliasTexParameters();
	_texture->initWithImage(img);

	spr_BallHP->setTexture(_texture);

	m_Ball->setOpacity(255);
	spr_BallHP->setOpacity(255);
	m_IsBallMove = false;
}

bool Ball::Get_IsMove()
{
	return m_IsBallMove;
}

Rect Ball::Get_Rect()
{
	return m_Ball->getBoundingBox();
}

int Ball::GetBallNum()
{
	return BallNum;
}

Vec2 Ball::Get_Pos()
{
	return m_Ball->getPosition();
}

Vec2 Ball::Get_Speed()
{
	return m_BallSpeed;
}

void Ball::Set_Speed(Vec2 _speed)
{
	m_BallSpeed = _speed;
}

bool Ball::Get_ISBallMove()
{
	if (m_IsBallMove == true)
	{
		return true;
	}

	else if (m_IsBallMove == false)
	{
		return false;
	}
}

int Ball::Get_Index()
{
	return m_Index;
}




