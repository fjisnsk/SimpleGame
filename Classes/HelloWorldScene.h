#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;


class HelloWorld : public cocos2d::CCLayerColor
{
public:
    int score = 0;
    int highScore = 1;
	
    CCLabelTTF* scoreLabel;
    CCLabelTTF* highScoreLabel;
    
    HelloWorld();
	~HelloWorld();

	virtual bool init();

	static cocos2d::CCScene* scene();

	virtual void menuCloseCallback(cocos2d::CCObject* pSender);

	CREATE_FUNC(HelloWorld);

	void spriteMoveFinished(cocos2d::CCNode* sender);

	void gameLogic(float dt);

	void updateGame(float dt);

	void registerWithTouchDispatcher();
	void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    
protected:
	cocos2d::CCArray *_targets;
	cocos2d::CCArray *_projectiles;
	int _projectilesDestroyed;

	void addTarget();


};

#endif  // __HELLOWORLD_SCENE_H__