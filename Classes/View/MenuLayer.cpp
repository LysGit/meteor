//
//  MenuLayer.cpp
//  meteor
//
//  Created by 罗耀生 on 14-6-29.
//
//

#include "MenuLayer.h"
#include "../Data/Configure.h"

USING_NS_CC;

MenuLayer::MenuLayer(){
    
    _bSwipe = false;
}
MenuLayer::MenuLayer(bool Swipe){
    _bSwipe = Swipe;
}
MenuLayer::~MenuLayer(){
    
}

MenuLayer* MenuLayer::create(bool Swipe){
    
    MenuLayer *pRet = new MenuLayer( Swipe );
    if (pRet && pRet->init())
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

bool MenuLayer::init(){
    
    if ( !TouchLayer::init() ){
		return false;
	}
    
    return true;
}

void MenuLayer::swipeUp(){
    CCLOG("向上！");
    
    CCNotificationCenter::getInstance()->postNotification(NF_SHOOT_BULLET, NULL);
}
void MenuLayer::swipeDown(){
    CCLOG("向下！");
    CCNotificationCenter::getInstance()->postNotification(NF_SHOOT_BULLET, NULL);
}
void MenuLayer::swipeLeft(){
    CCLOG("向左！");
    CCNotificationCenter::getInstance()->postNotification(NF_SHOOT_BULLET, NULL);
}
void MenuLayer::swipeRight(){
    CCLOG("向右！");
    CCNotificationCenter::getInstance()->postNotification(NF_SHOOT_BULLET, NULL);
}

void MenuLayer::autochthonous(){
    CCLOG("非滑动！");
}

void MenuLayer::menuCloseCallback(Ref* pSender)
{
    CCLOG("I can touch it!");
}

