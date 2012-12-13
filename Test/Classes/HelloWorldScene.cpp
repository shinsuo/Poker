#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
//#include "SecondScene.h"
#include "Poker.h"

using namespace cocos2d;
using namespace CocosDenshion;

CCScene* HelloWorld::scene()
{
	// 'scene' is an autorelease object
	CCScene *scene = CCScene::node();
	
	// 'layer' is an autorelease object
	HelloWorld *layer = HelloWorld::node();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
	//////////////////////////////
	// 1. super init first
	if ( !CCLayer::init() )
	{
		return false;
	}

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	CCMenuItemImage *pCloseItem = CCMenuItemImage::itemFromNormalImage(
										"CloseNormal.png",
										"CloseSelected.png",
										this,
										menu_selector(HelloWorld::menuCloseCallback) );
	pCloseItem->setPosition( ccp(CCDirector::sharedDirector()->getWinSize().width - 20, 20) );

	// create menu, it's an autorelease object
	CCMenu* pMenu = CCMenu::menuWithItems(pCloseItem, NULL);
	pMenu->setPosition( CCPointZero );
	this->addChild(pMenu, 1);
    CCLog("%s",cocos2dVersion());

	/////////////////////////////
	// 3. add your codes below...

	// add a label shows "Hello World"
	// create and initialize a label
	CCLabelTTF* pLabel = CCLabelTTF::labelWithString("Hello World", "Thonburi", 34);

	// ask director the window size
	CCSize size = CCDirector::sharedDirector()->getWinSize();

	// position the label on the center of the screen
	pLabel->setPosition( ccp(size.width / 2, size.height - 20) );

	// add the label as a child to this layer
	this->addChild(pLabel, 1);

	// add "HelloWorld" splash screen"
	CCSprite* pSprite = CCSprite::spriteWithFile("HelloWorld.png");

	// position the sprite on the center of the screen
	pSprite->setPosition( ccp(size.width/2, size.height/2) );

	// add the sprite as a child to this layer
	this->addChild(pSprite, 0);
    
    
    
//    CCSprite *tempSprite = CCSprite::spriteWithFile("Icon@2x.png");
//    addChild(tempSprite);
//    tempSprite->setPosition(CCPoint(size.width/2,size.height/2));
    
    
    CCSpriteBatchNode *spriteBatchNode = CCSpriteBatchNode::batchNodeWithFile("Icon@2x.png", 100);
    addChild(spriteBatchNode);
    spriteBatchNode->setPosition(-100, -100);
    
    
    m_menu= CCMenu::node();
    
    for (int i = 0; i < 100; i++) {
//        CCSprite *sprite = CCSprite::spriteWithFile("ttt.png");
//        spriteBatchNode->addChild(sprite);
        
        CCMenuItemImage *tCloseItem = CCMenuItemImage::itemFromNormalImage(
                                                                           "CloseNormal.png",
                                                                           "CloseSelected.png",
                                                                           this,
                                                                           menu_selector(HelloWorld::menuCloseCallback) );
        
        m_menu->addChild(tCloseItem, i);
        tCloseItem->setTag(i);
        tCloseItem->setPosition(i*20, 50);
        tCloseItem->setSelected(0);
        
        CCSprite *temp = CCSprite::spriteWithFile("6.png");
        tCloseItem->addChild(temp);
        temp->cocos2d::CCNode::setPosition(10, 60);
        
//        sprite->setIsVisible(1);
    }
    
    addChild(m_menu);
    m_menu->setPosition(10, 10);
    
    
    
    CCSprite *user1 = CCSprite::spriteWithFile("Icon.png");
    CCSprite *user2 = CCSprite::spriteWithFile("Icon.png");
    CCSprite *user3 = CCSprite::spriteWithFile("Icon.png");
    CCSprite *user4 = CCSprite::spriteWithFile("Icon.png");

    user1->cocos2d::CCNode::setPosition(40, 280);
    user2->cocos2d::CCNode::setPosition(440, 280);
    user3->cocos2d::CCNode::setPosition(40, 120);
    user4->cocos2d::CCNode::setPosition(440, 120);

    
    addChild(user1);
    addChild(user2);
    addChild(user3);
    addChild(user4,1,10);

    
    CCMenu* menu2 = CCMenu::node();
    CCLabelTTF *labelTTF = CCLabelTTF::labelWithString("shuffle", "Thonburi", 18);
    CCMenuItemLabel *label = CCMenuItemLabel::itemWithLabel(labelTTF, this, menu_selector(HelloWorld::shuffle));
    menu2->addChild(label, 1);
//    label->setPosition(240, 10);
//    label->setString("shuffle");
    addChild(menu2);
    
    
    
    
//    CCArray *spriteArray = spriteBatchNode->getDescendants();
//    
//    for (int i = 0; i < spriteArray->count(); i++) {
//        CCSprite *tt = (CCSprite *)spriteArray->objectAtIndex(i);
////        CCLog("tt:%d",tt->getAtlasIndex());
//        
//        menu->addChild(tt, i);
//    }
    
    
    Poker *pk = new Poker(1, kHEART);
    CCLog("pk:%i,%i",pk->getValue(),pk->getType());
    
	this->schedule(schedule_selector(HelloWorld::update),1);
	return true;
}

void HelloWorld::menuCloseCallback(CCObject* pSender)
{
    CCMenuItemImage *item = (CCMenuItemImage *)m_menu->m_pSelectedItem;
    CCLog("select:%d,%d",item->getTag(),item->getSelected());
    if (!item->getSelected()) {
        item->setPosition(item->getPositionX(), item->getPositionY()+20);
        item->setSelected(1);
    }else{
        item->setPosition(item->getPositionX(), item->getPositionY()-20);
        item->setSelected(0);
    }
    
//    SecondScene *secondScene = (SecondScene *)SecondScene::scene();
//    CCDirector::sharedDirector()->pushScene((CCScene *)secondScene);
    
    return;
	CCDirector::sharedDirector()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void HelloWorld::shuffle(CCObject *pSender)
{
    CCPoint *pt1 = new CCPoint(40, 120);
    CCPoint *pt2 = new CCPoint(40, 280);
    CCPoint *pt3 = new CCPoint(440, 280);
    CCPoint *pt4 = new CCPoint(440, 120);
    
    
    CCSprite *user1 = CCSprite::spriteWithFile("Icon.png");
    CCSprite *user2 = CCSprite::spriteWithFile("Icon.png");
    CCSprite *user3 = CCSprite::spriteWithFile("Icon.png");

    
    user1->cocos2d::CCNode::setPosition(440, 120);
    user2->cocos2d::CCNode::setPosition(440, 120);
    user3->cocos2d::CCNode::setPosition(440, 120);
    
    CCAction *act1 = CCMoveTo::actionWithDuration(0.3, *pt1);
    CCAction *act2 = CCMoveTo::actionWithDuration(0.5, *pt2);
    CCAction *act3 = CCMoveTo::actionWithDuration(0.3, *pt3);
    CCAction *act4 = CCMoveTo::actionWithDuration(0.0001, *pt4);

    
    CCArray *actArray = CCArray::array();
    actArray->addObject(act1);
    actArray->addObject(act4);
    actArray->addObject(act2);
    actArray->addObject(act4);
    actArray->addObject(act3);
    actArray->addObject(act4);
    
    CCAction *seq = CCSequence::actionsWithArray(actArray);
    //*/
    CCRepeat *repeat1 = CCRepeat::actionWithAction((CCFiniteTimeAction *)seq, 3);
    
    CCCallFunc *calFunc = CCCallFunc::actionWithTarget(this, callfunc_selector(HelloWorld::shuffleDone));
    
    CCAction *seq2 = CCSequence::actions((CCFiniteTimeAction *)repeat1,calFunc,act1,NULL);

//    CCRepeat *repeat1 = CCRepeat::actionWithAction((CCFiniteTimeAction *)act1, 3);
//    CCRepeat *repeat2 = CCRepeat::actionWithAction((CCFiniteTimeAction *)act2, 3);
//    CCRepeat *repeat3 = CCRepeat::actionWithAction((CCFiniteTimeAction *)act3, 3);

    
    user1->runAction(seq2);
//    user2->runAction(repeat2);
//    user3->runAction(repeat3);
    
    addChild(user1);
//    addChild(user2);
//    addChild(user3);
}

void HelloWorld::update(ccTime dt)
{
//    CCLog("dt:%d",dt);
}

void HelloWorld::shuffleDone()
{
    removeChildByTag(10, 1);
}
