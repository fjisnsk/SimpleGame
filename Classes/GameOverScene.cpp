#include "GameOverScene.h"
#include "HelloWorldScene.h"
#include "TitleScene.h"

using namespace cocos2d;

bool GameOverScene::init()
{
	if( CCScene::init() )
	{
		this->_layer = GameOverLayer::create();
		this->_layer->retain();
		this->addChild(_layer);
        

        // [ボタン] タイトルへ
        CCMenuItemImage *menuTitle = CCMenuItemImage::create(
                                                             "button_green.png",
                                                             "button_green.png",
                                                             this,
                                                             menu_selector(GameOverScene::pushTitle));
        
        CCMenu* pMenu = CCMenu::create(menuTitle, NULL);
        CCSize winSize = CCDirector::sharedDirector()->getWinSize();
        pMenu->setPosition(ccp(winSize.width/2,winSize.height/2 - 100));
        this->addChild(pMenu);

		// [テキスト(ボタン用)] タイトルへ
        CCLabelTTF* lblToTitle = CCLabelTTF::create("タイトルへ", "Arial", 16.0);
        lblToTitle->setPosition(ccp(winSize.width/2,winSize.height/2 - 100));
        this->addChild(lblToTitle);
        
        return true;
	}

    return false;
	
}

GameOverScene::~GameOverScene()
{
	if (_layer)
	{
		_layer->release();
		_layer = NULL;
	}
}


bool GameOverLayer::init()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    bool bRet = false;
    
    do {

        CC_BREAK_IF(!CCLayerColor::initWithColor( ccc4(255,255,255,255) ) );
        
        // [テキスト] You Win or You Lose
        this->_label = CCLabelTTF::create("","Artial", 32);
        CC_BREAK_IF(! _label);
        _label->retain();
        _label->setColor( ccc3(0, 0, 0) );
        _label->setPosition( ccp(winSize.width/2, winSize.height/2) );
        this->addChild(_label);

        // [テキスト] スコア＆ハイスコア
        this->_labelResult = CCLabelTTF::create("","Artial", 32);
        CC_BREAK_IF(! _labelResult);
        _labelResult->retain();
        _labelResult->setColor( ccc3(0, 0, 0) );
        _labelResult->setPosition( ccp(winSize.width/2, winSize.height/2 + 100) );
        this->addChild(_labelResult);
        
        bRet = true;
        
    } while (0);
    
    return bRet;
}


GameOverLayer::~GameOverLayer()
{
	if (_label)
	{
		_label->release();
		_label = NULL;
	}
}

/**
 スコア、ハイスコアを設定する
 ゲームオーバー時に呼ばれる
 */
void GameOverLayer::setResult(int score)
{
    // ハイスコアを超えたらハイスコアへ保存
    int highScore = CCUserDefault::sharedUserDefault()->getIntegerForKey("highScore",2);
    if (score > highScore)
    {
        highScore = score;
        CCUserDefault::sharedUserDefault()->setIntegerForKey("highScore", highScore);
        CCUserDefault::sharedUserDefault()->flush();
    }
    
    CCString* highScoreStr = CCString::createWithFormat("スコア %d ハイスコア %d",score,highScore);
    _labelResult->setString(highScoreStr->getCString());
}

/**
 「タイトルへ」ボタン押下時の処理
 */
void GameOverScene::pushTitle(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene( CCTransitionCrossFade::create(1.0, Title::scene()) );
}