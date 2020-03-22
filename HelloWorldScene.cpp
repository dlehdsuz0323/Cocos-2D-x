#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "BallManager.h"
#include "BlockManager.h"
#include "ScoreManager.h"

using namespace CocosDenshion;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

	//BlockManager::GetInstance();
	SimpleAudioEngine::getInstance()->playBackgroundMusic("Sound/Tido Kang.mp3", true);
	m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();

	auto m_LayerColor = LayerColor::create(Color4B(255, 255, 255, 255));
	this->addChild(m_LayerColor);

	m_BG = Sprite::create("Images/BG_Test.png");
	m_BG->setPosition(Vec2(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.5f));
	m_BG->setColor(Color3B(255, 255, 255));
	m_BG->setOpacity(150);
	this->addChild(m_BG);

	for (int i = 0; i < 20; i++)
	{
		m_DieLine[i] = Sprite::create("Images/Block_Die_Line.png");
		m_DieLine[i]->setPosition(Vec2((30 * i), m_ScreenSize.y * 0.7f));
		m_DieLine[i]->setColor(Color3B(255, 255, 255));

		m_DieLine[i]->getTexture()->setAliasTexParameters();
		this->addChild(m_DieLine[i]);
	}
	
	cout << m_ScreenSize.y * 0.7f << endl;


	for (int i = 0; i<5; i++)
		m_ShootLine[i] = Sprite::create("Images/Button_Circle_Push.png");

	this->addChild(m_ShootLine[0]);
	m_ShootLine[0]->setPosition(Vec2(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.8f));	
	m_ShootLine[0]->setColor (Color3B (0, 0, 255));
	m_ShootLine[0]->setOpacity(255);

	m_ShootLine[0]->addChild(m_ShootLine[1]);
	m_ShootLine[1]->setPosition(Vec2(m_ShootLine[0]->getTextureRect().size.width * 0.5f , m_ShootLine[0]->getTextureRect().size.height * 0.5f -50));
	m_ShootLine[1]->setColor(Color3B(0, 0, 255));
	m_ShootLine[1]->setOpacity(200);

	m_ShootLine[0]->addChild(m_ShootLine[2]);
	m_ShootLine[2]->setPosition(Vec2(m_ShootLine[0]->getTextureRect().size.width * 0.5f, m_ShootLine[0]->getTextureRect().size.height * 0.5f -100));
	m_ShootLine[2]->setColor(Color3B(0, 0, 255));
	m_ShootLine[2]->setOpacity(150);

	m_ShootLine[0]->addChild(m_ShootLine[3]);
	m_ShootLine[3]->setPosition(Vec2(m_ShootLine[0]->getTextureRect().size.width * 0.5f, m_ShootLine[0]->getTextureRect().size.height * 0.5f -150));
	m_ShootLine[3]->setColor(Color3B(0, 0, 255));
	m_ShootLine[3]->setOpacity(100);

	m_ShootLine[0]->addChild(m_ShootLine[4]);
	m_ShootLine[4]->setPosition(Vec2(m_ShootLine[0]->getTextureRect().size.width * 0.5f, m_ShootLine[0]->getTextureRect().size.height * 0.5f -200));
	m_ShootLine[4]->setColor(Color3B(0, 0, 255));
	m_ShootLine[4]->setOpacity(50);


	BallManager::GetInstance()->Create_BallList(this);
	BlockManager::GetInstance()->Create_BlockSet(this);


	// �� �����Ӹ��� ����
	this->schedule(schedule_selector(HelloWorld::Loop));


	ScoreManager::GetInstance()->Create_Score(this);
	BallManager::GetInstance()->Create_BallNum(this);

    return true;
}

void HelloWorld::onEnter()
{
	Scene::onEnter();

	// �̱���ġ���� ��ġ������ ���
	listener = EventListenerTouchOneByOne::create();

	// false�� �����ϸ� �̺�Ʈ�� ���Ű� ������� ��������Ʈ�� ��ġ �̺�Ʈ ����
	listener->setSwallowTouches(true);

	listener->onTouchBegan = CC_CALLBACK_2(HelloWorld::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(HelloWorld::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(HelloWorld::onTouchEnded, this);

	// ��ġ�������� �켱������ ȭ�鿡 �׷��� �������
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

void HelloWorld::onExit()
{
	_eventDispatcher->removeEventListener(listener);

	Scene::onExit();
}

bool HelloWorld::onTouchBegan(Touch* touch, Event *event)
{
	auto touchPoint = touch->getLocation();

	

	// Touch Check
	bool _isTouch = CCRect(0, 0, m_ScreenSize.x, m_ScreenSize.y).containsPoint(touchPoint);

	if (_isTouch)
	{
		//log("onTouchBegan id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);
	}

	return true;
}

void HelloWorld::onTouchMoved(Touch* touch, Event *event)
{
	auto touchPoint = touch->getLocation();

	// Touch Check
	bool _isTouch = CCRect(0, 0, m_ScreenSize.x, m_ScreenSize.y).containsPoint(touchPoint);

	if (_isTouch)
	{

		m_Angle = getAngle(m_ShootLine[0]->getPosition().x, m_ShootLine[0]->getPosition().y, touchPoint.x, touchPoint.y);

		m_ShootLine[0]->setRotation(m_Angle);
		//log("onTouchMoved id = %d, x = %f, y = %f", touch->getID(), touchPoint.x, touchPoint.y);


		/*m_ShootLine[0]->*/
	}
}

void HelloWorld::onTouchEnded(Touch* touch, Event *event)
{
	auto touchPoint = touch->getLocation();

	// Touch Check
	bool _isTouch = CCRect(0, 0, m_ScreenSize.x, m_ScreenSize.y).containsPoint(touchPoint);

	if (_isTouch)
	{
		float _x = 15.0f * sin(CC_DEGREES_TO_RADIANS(m_Angle));
		float _y = 15.0f * cos(CC_DEGREES_TO_RADIANS(m_Angle));
			
		m_BallSpeed = Vec2(_x, _y);
		BallManager::GetInstance()->Shoot_Ball(m_BallSpeed);
	}
}

float HelloWorld::getAngle(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;

	float dy = y2 - y1;

	float rad = atan2(dy, dx);

	float degree = (float)CC_RADIANS_TO_DEGREES(rad);

	return 270 - degree;
}

void HelloWorld::Loop(float f)
{
	BallManager::GetInstance()->Loop();
	BlockManager::GetInstance()->Move(this);
}