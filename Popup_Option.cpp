#include "Popup_Option.h"

Popup_Option::Popup_Option(ccMenuCallback _firstSel)
{
	Vec2 m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();

	m_BlackBG = Sprite::create("Images/BG_Test.png");
	m_BlackBG->setPosition(Vec2(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.5f));
	m_BlackBG->setColor(Color3B(0, 0, 0));
	m_BlackBG->setOpacity(125);
	this->addChild(m_BlackBG);

	m_BG = Sprite::create("Images/Popup_Option_BG.png");
	m_BG->setPosition(Vec2(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.5f));
	m_BG->setScale(0.7);
	this->addChild(m_BG);

	
	

	m_Bgm = MenuItemImage::create("Images/Icon_BGM_Pop.png", "Images/Icon_BGM_Push.png", CC_CALLBACK_0(Popup_Option::Set_BGM, this));
	m_Bgm->setPosition((m_BG->getContentSize().width * 0.5f) - 100, m_BG->getContentSize().height * 0.5f);
	m_Bgm->setScale(2.0f);


	m_Sound = MenuItemImage::create("Images/Icon_SoundEffect_Pop.png", "Images/Icon_SoundEffect_Push.png", CC_CALLBACK_0(Popup_Option::Set_SOUND, this));
	m_Sound->setPosition((m_BG->getContentSize().width * 0.5f) + 100, m_BG->getContentSize().height * 0.5f);
	m_Sound->setScale(2.5f);

	m_Close = MenuItemImage::create("Images/Button_Close_Pop.png", "Images/Button_Close_Push.png", _firstSel);
	m_Close->setPosition(m_BG->getContentSize().width * 0.92f, m_BG->getContentSize().height * 0.9f);
	m_Close->setScale(2.5f);

	m_Menu = Menu::create(m_Bgm, m_Sound, m_Close, nullptr);
	m_Menu->setPosition(Vec2(0, 0));
	m_BG->addChild(m_Menu);


	m_IsBgm = UserDefault::getInstance()->getBoolForKey("BGM");
	if (!m_IsBgm)
		m_Bgm->setColor(Color3B(255, 0, 0));

	m_IsSound = UserDefault::getInstance()->getBoolForKey("SOUND");
	if (!m_IsSound)
		m_Sound->setColor(Color3B(255, 0, 0));
	/*UserDefault::getInstance()->setBoolForKey("BGM", )*/
}

Popup_Option::~Popup_Option()
{
	/*((Scene*)m_Ref)->removeChild(m_Block, true);
	m_Block = nullptr;*/
}

void Popup_Option::Set_BGM()
{
	log("BGM");

	if (m_IsBgm)
	{
		m_IsBgm = false;
		UserDefault::getInstance()->setBoolForKey("BGM", m_IsBgm);
		m_Bgm->setColor(Color3B(255, 0, 0));
	}
	else
	{
		m_IsBgm = true;
		UserDefault::getInstance()->setBoolForKey("BGM", m_IsBgm);
		m_Bgm->setColor(Color3B(255, 255, 255));
	}
}

void Popup_Option::Set_SOUND()
{
	log("Sound");

	if (m_IsSound)
	{
		m_IsSound = false;
		UserDefault::getInstance()->setBoolForKey("SOUND", m_IsSound);
		m_Sound->setColor(Color3B(255, 0, 0));
	}
	else
	{
		m_IsSound = true;
		UserDefault::getInstance()->setBoolForKey("SOUND", m_IsSound);
		m_Sound->setColor(Color3B(255, 255, 255));
	}
}