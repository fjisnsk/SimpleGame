//
//  TitleScene.h
//  SimpleGame
//
//  Created by Shinsaku Fujii on 2014/03/15.
//
//

#ifndef __SimpleGame__TitleScene__
#define __SimpleGame__TitleScene__


#include "cocos2d.h"

class Title : public cocos2d::CCLayer
{
public:
    
	virtual bool init();
    
	static cocos2d::CCScene* scene();
    
	virtual void pushStart(cocos2d::CCObject* pSender);
    
	CREATE_FUNC(Title);
    
};
#endif /* defined(__SimpleGame__TitleScene__) */

