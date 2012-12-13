//
//  SecondScene.cpp
//  Test
//
//  Created by shin on 12/10/12.
//
//

#include "SecondScene.h"
#include "HelloWorldScene.h"

using namespace cocos2d;

CCScene* SecondScene::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::node();
	
	// 'layer' is an autorelease object
	SecondScene *layer = (SecondScene *)SecondScene::node();
    
	// add layer as a child to scene
	scene->addChild(layer);
    
	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool SecondScene::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}
    
    CCSprite *sprite = CCSprite::spriteWithFile("Icon@2x.png");
    addChild(sprite);
    
    sprite->cocos2d::CCNode::setPosition(200, 200);
    
    
    
    CCMenuItemImage *menuItemImage = CCMenuItemImage::itemFromNormalImage("Icon@2x.png", "Icon@2x.png", this, menu_selector(SecondScene::back));
    
    CCMenu *menu = CCMenu::menuWithItem(menuItemImage);
    
    addChild(menu);
    
    return true;
}


void SecondScene::back(CCObject *pSender)
{
    CCDirector::sharedDirector()->popScene();
}