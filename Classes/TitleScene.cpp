//
//  TitleScene.cpp
//  SimpleGame
//
//  Created by Shinsaku Fujii on 2014/03/15.
//
//

#include "TitleScene.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* Title::scene()
{
	CCScene * scene = NULL;
	do
	{
		// 'scene' is an autorelease object
		scene = CCScene::create();
		CC_BREAK_IF(! scene);
        
		// 'layer' is an autorelease object
		Title *layer = Title::create();
		CC_BREAK_IF(! layer);
        
		// add layer as a child to scene
		scene->addChild(layer);
	} while (0);
    
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool Title::init()
{
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    bool bRet = false;
    
    do {
        // [テキスト] タイトル
        CCLabelTTF* titleTxt = CCLabelTTF::create("Title Scene", "Arial", 30.0);
        titleTxt->setPosition(ccp(winSize.width/2,winSize.height-titleTxt->getContentSize().height));
        this->addChild(titleTxt);

        // [ボタン] スタートボタン
        CCMenuItemImage *menuStart = CCMenuItemImage::create(
                                                             "button_orange.png",
                                                             "button_orange.png",
                                                             this,
                                                             menu_selector(Title::pushStart));
        CCMenu* pMenu = CCMenu::create(menuStart, NULL);
        pMenu->setPosition(ccp(winSize.width/2,winSize.height/2));
        this->addChild(pMenu);

        // [ボタン] スタートボタンテキスト
        CCLabelTTF* startLabel = CCLabelTTF::create("Play", "Arial", 16.0);
        startLabel->setColor(ccc3(200,100,100));
        startLabel->setPosition(ccp(winSize.width/2,winSize.height/2));
        this->addChild(startLabel);
        
        bRet = true;
        
    } while (0);
    
	return bRet;
}

/**
 スタートボタン押下時の処理
 */
void Title::pushStart(CCObject* pSender)
{
    CCDirector::sharedDirector()->replaceScene( HelloWorld::scene() );
}

