//
//  StarLayer.cpp
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#include "StarLayer.h"
#include "StarNode.h"
#include "../Data/Configure.h"
#include "../Model/ShootModel.h"

#include "ShootNode.h"

#include <math.h>

USING_NS_CC;

bool StarLayer::init(){
	if ( !CCLayer::init() ){
		return false;
	}
    
	return true;
}

void StarLayer::onExit(){
    CCLayer::onExit();
    this->Notification_delObserver();
}

void StarLayer::onEnter(){
    CCLayer::onEnter();
    this->Notification_addObserver();
}

void StarLayer::onEnterTransitionDidFinish(){
    CCLayer::onEnterTransitionDidFinish();
}

void StarLayer::UI_update(){
    //事件更新处理

    CCLOG("StarLayer::UI_update:%ld ", _model->_vector.size() );
    for(auto sp : _model->_vector )
    {
        StarNode *node = StarNode::create( sp );
        node->setTag( sp->getTag() );
        this->addChild( node );
    }
}

#pragma mark - Notification
void StarLayer::Notification_addObserver(){
    
    CCNotificationCenter::getInstance()->addObserver( this,
                                                     callfuncO_selector(StarLayer::Notification_delete_starNode),
                                                     NF_DEL_STAR,
                                                     NULL);
}

void StarLayer::Notification_delObserver(){
    
//    CCNotificationCenter::getInstance()->removeObserver( this, NF_DEL_STAR);
    CCNotificationCenter::getInstance()->removeAllObservers( this );
}

void StarLayer::Notification_delete_starNode(cocos2d::Ref *obj){
    
    CCLOG("StarLayer 收到！");
    StarRef *ref = (StarRef *)obj;
    this->removeChildByTag( ref->getTag() );
}
