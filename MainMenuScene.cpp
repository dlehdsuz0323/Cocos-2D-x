#include "MainMenuScene.h"
#include "SimpleAudioEngine.h"
#include "BlockManager.h"
#include "HelloWorldScene.h"
#include "Popup_Option.h"

Scene* MainMenuScene::createScene()
{
	return MainMenuScene::create();
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
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


	/*m_Title_D = Sprite::create("Images /Icon_ShopMark.png");
	m_Title_R = Sprite::create("Images /Icon_ShopMark.png");
	m_Title_O = Sprite::create("Images /Icon_ShopMark.png");
	m_Title_B = Sprite::create("Images /Icon_ShopMark.png");
	m_Title_A = Sprite::create("Images /Icon_ShopMark.png");
	m_Title_L = Sprite::create("Images /Icon_ShopMark.png");
	m_Title_L2 = Sprite::create("Images/Icon_ShopMark.png");

	m_Title_D->setPosition(Vec2((m_ScreenSize.x * 0.5f) - 195, m_ScreenSize.y * 0.8f));
	m_Title_R->setPosition(Vec2((m_ScreenSize.x * 0.5f) - 130, m_ScreenSize.y * 0.8f));
	m_Title_O->setPosition(Vec2((m_ScreenSize.x * 0.5f) - 65, m_ScreenSize.y * 0.8f));
	m_Title_B->setPosition(Vec2((m_ScreenSize.x * 0.5f), m_ScreenSize.y * 0.7f));
	m_Title_A->setPosition(Vec2((m_ScreenSize.x * 0.5f) + 65, m_ScreenSize.y * 0.7f));
	m_Title_L->setPosition(Vec2((m_ScreenSize.x * 0.5f) + 130, m_ScreenSize.y * 0.7f));
	m_Title_L2->setPosition(Vec2((m_ScreenSize.x * 0.5f) + 195, m_ScreenSize.y * 0.7f));
	
	this->addChild(m_Title_D);
	this->addChild(m_Title_R);
	this->addChild(m_Title_O);
	this->addChild(m_Title_B);
	this->addChild(m_Title_A);
	this->addChild(m_Title_L);
	this->addChild(m_Title_L2);*/


	m_PlayButton = MenuItemImage::create("Images/Button_Play_Pop.png", "Images/Button_Play_Push.png", CC_CALLBACK_0(MainMenuScene::Set_Play, this));
	((Sprite*)m_PlayButton->getNormalImage())->getTexture()->setAliasTexParameters();
	((Sprite*)m_PlayButton->getSelectedImage())->getTexture()->setAliasTexParameters();
	m_PlayButton->setPosition(m_ScreenSize.x * 0.5f, m_ScreenSize.y * 0.3f);
	m_PlayButton->setScale(1.5f);

	m_OptionButton = MenuItemImage::create("Images/Icon_Option_Pop.png", "Images/Icon_Option_Push.png", CC_CALLBACK_0(MainMenuScene::Show_Option, this));
	((Sprite*)m_OptionButton->getNormalImage())->getTexture()->setAliasTexParameters();
	((Sprite*)m_OptionButton->getSelectedImage())->getTexture()->setAliasTexParameters();
	m_OptionButton->setPosition(m_ScreenSize.x * 0.92f, m_ScreenSize.y * 0.95f);

	m_Menu = Menu::create(m_PlayButton, m_OptionButton, nullptr);
	m_Menu->setPosition(Vec2(0, 0));
	m_Menu->setTouchEnabled(true);
	this->addChild(m_Menu);

	

	return true;
}

void MainMenuScene::Set_Play()
{
	if (!m_Menu->isTouchEnabled())
		return;

	auto _InGmaeScene = HelloWorld::createScene();
	/*Director::getInstance()->replaceScene(_InGmaeScene);*/ // 이전 씬이 삭제대고 새로운씬이 대체 됨
	Director::getInstance()->replaceScene(_InGmaeScene); // 이전 씬이 그대로 남아있고 새로운 씬위 위에 덮어 써짐 PopScene을하면 이전 씬으로 돌아감
}

void MainMenuScene::Show_Option()
{
	if (!m_Menu->isTouchEnabled())
		return;

	m_Menu->setTouchEnabled(false);

	m_Popup_Option = new Popup_Option(CC_CALLBACK_0(MainMenuScene::Close_Option, this));
	this->addChild(m_Popup_Option);
	/*Director::getInstance()->replaceScene(InGameScn)Set_Play*/
}

void MainMenuScene::Close_Option()
{
	m_Menu->setTouchEnabled(true);

	this->removeChild(m_Popup_Option);
	m_Popup_Option = nullptr;
	/*Director::getInstance()->replaceScene(InGameScn)Set_Play*/
}