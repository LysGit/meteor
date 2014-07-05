//
//  GameOverLayer.cpp
//  meteor
//
//  Created by lys on 14-6-30.
//
//

#include "GameOverLayer.h"
#include "../Data/Configure.h"

USING_NS_CC;

bool GameOverLayer::init(){
	if ( !CCLayerColor::initWithColor( Color4B( 255*0.5, 255*0.5, 255*0.55, 255*0.6) ) ){
		return false;
	}
    
	return true; 
}

void GameOverLayer::onEnter(){
    CCLayer::onEnter();
}

void GameOverLayer::onEnterTransitionDidFinish(){
    CCLayer::onEnterTransitionDidFinish();
    
    Size size = Director::getInstance()->getWinSize();
    
    auto refreshItem = MenuItemImage::create(
                                           "refresh.png",
                                           "refresh.png",
                                           [&](Ref *sender){
                                               CCNotificationCenter::getInstance()->postNotification(NF_MENU_REFRESH, NULL);
                                           });
    refreshItem->setPosition( Point( size.width*0.5 - 100, size.height*0.5 ) );
    
    
    auto recoverItem = MenuItemImage::create(
                                             "recover.png",
                                             "recover.png",
                                             [&](Ref *sender){
                                                 CCNotificationCenter::getInstance()->postNotification(NF_MENU_RECOVER, NULL);
                                             });
    recoverItem->setPosition( Point( size.width*0.5 , size.height*0.5 ) );
    
    auto shareItem = MenuItemImage::create(
                                             "share.png",
                                             "share.png",
                                             [&](Ref *sender){
                                                 CCNotificationCenter::getInstance()->postNotification(NF_MENU_SHARE, NULL);
                                             });
    shareItem->setPosition( Point( size.width*0.5 + 100, size.height*0.5 ) );
    
    Menu *menu = Menu::create( refreshItem, recoverItem, shareItem, NULL);
    menu->setPosition( Point() );
    this->addChild( menu );
}

