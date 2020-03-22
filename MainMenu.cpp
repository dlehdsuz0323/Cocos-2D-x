#include "MainMenu.h"
#include "HelloWorldScene.h"
#include "BlockManager.h"

Scene* MainMenu::createScene()
{
	return MainMenu::create();
}

bool MainMenu::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Scene::init())
	{
		return false;
	}

	m_ScreenSize = Director::getInstance()->getOpenGLView()->getDesignResolutionSize();

	m_BG = Sprite::create("Images/BG_Test.png");
	m_BG->setPosition(Vec2(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.5f));
	m_BG->setColor(Color3B(0, 200, 200));
	this->addChild(m_BG);

	for (int i = 0; i < 7; i++)
	{
		char buf[64];
		sprintf(buf, "Images/%d.png", i);
		Spr_MainTitle[i] = Sprite::create(buf);
		Spr_MainTitle[i]->setPosition(Vec2(m_ScreenSize.x * 0.1 + (i * 64), m_ScreenSize.y * 0.85));
		this->addChild(Spr_MainTitle[i]);
	}
		
	m_PlayButton = MenuItemImage::create("Images/Button_Play_Pop.png", 
										 "Images/Button_Play_Push.png", 
										 CC_CALLBACK_0(MainMenu::Set_Play, this));
	/*((Sprite*)m_PlayButton->getNormalImage())->getTexture()->setAliasTexParameters();
	((Sprite*)m_PlayButton->getSelectedImage())->getTexture()->setAliasTexParameters();*/
	m_PlayButton->setPosition(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.4f);
	m_PlayButton->setScale(1.5f);

	m_OptionButton = MenuItemImage::create("Images/Icon_Option_Pop.png", 
										   "Images/Icon_Option_Push.png", 
											CC_CALLBACK_0(MainMenu::Show_Option, this));
	/*((Sprite*)m_OptionButton->getNormalImage())->getTexture()->setAliasTexParameters();
	((Sprite*)m_OptionButton->getSelectedImage())->getTexture()->setAliasTexParameters();*/
	m_OptionButton->setPosition(m_ScreenSize.x * 0.92f, m_ScreenSize.y * 0.95f);

	m_Menu = Menu::create(m_PlayButton, m_OptionButton, nullptr);
	m_Menu->setPosition(Vec2(0, 0));
	m_Menu->setTouchEnabled(true);
	this->addChild(m_Menu);

	//Show_BackGround(this);
	this->schedule(schedule_selector(MainMenu::Show_BackGround), 1);

	return true;
}

void MainMenu::Set_Play()
{
	auto _InGmaeScene = HelloWorld::createScene();
	Director::getInstance()->replaceScene(_InGmaeScene);
}

void MainMenu::Show_Option()
{
	if (m_OptionPopup == NULL)
	{
		m_OptionPopup = new Option(CC_CALLBACK_0(MainMenu::Close_Option, this));
		this->addChild(m_OptionPopup);
	}
}

void MainMenu::Close_Option()
{
	this->removeChild(m_OptionPopup);
	m_OptionPopup = nullptr;
}

void MainMenu::Show_BackGround(float t)
{
	BlockManager::GetInstance()->Create_MainMenuBlock(this);
}
