//
//  SecondScene.h
//  Test
//
//  Created by shin on 12/10/12.
//
//

#ifndef __Test__SecondScene__
#define __Test__SecondScene__

#include "cocos2d.h"

class SecondScene : public cocos2d::CCLayer
{
public:
	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();
    
	// there's no 'id' in cpp, so we recommand to return the exactly class pointer
	static cocos2d::CCScene* scene();
    LAYER_NODE_FUNC(SecondScene);
    
    virtual void back(CCObject *pSender);
};

#endif /* defined(__Test__SecondScene__) */
