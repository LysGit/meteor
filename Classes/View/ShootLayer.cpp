//
//  ShootLayer.cpp
//  meteor
//
//  Created by lys on 14-7-2.
//
//

#include "ShootLayer.h"
#include "ShootNode.h"
#include "../Data/Configure.h"

#include <math.h>

USING_NS_CC;

bool ShootLayer::init(){
	if ( !CCLayer::init() ){
		return false;
	}
    
	return true;
}

void ShootLayer::onExit(){
    CCLayer::onExit();
    this->Notification_delObserver();
}

void ShootLayer::onEnter(){
    CCLayer::onEnter();
    this->Notification_addObserver();
}

void ShootLayer::onEnterTransitionDidFinish(){
    CCLayer::onEnterTransitionDidFinish();
}

void ShootLayer::UI_update(){
    //事件更新处理
    
    CCLOG("StarLayer::UI_update:%ld ", _model->_vector.size() );
    for(auto sp : _model->_vector )
    {
        ShootNode *node = ShootNode::create( sp );
        node->setTag( sp->getTag() );
        this->addChild( node );
        
        
        //清除事件
        DelayTime *delay = DelayTime::create( sp->getDuration() );
        CallFuncN *cfn = CallFuncN::create( CC_CALLBACK_1(ShootLayer::callback2, this , sp));
        Sequence *sq2 = Sequence::create( delay, cfn, NULL);
        
        this->runAction( sq2 );
    }
}

#pragma mark - Notification
void ShootLayer::Notification_addObserver(){
    
    CCNotificationCenter::getInstance()->addObserver( this,
                                                     callfuncO_selector(ShootLayer::Notification_shoot_bullet),
                                                     NF_SHOOT_BULLET,
                                                     NULL);
}

void ShootLayer::shoot_end(cocos2d::Node* pSender){
    CCNotificationCenter::getInstance()->postNotification(NF_DEL_BULLET, pSender);
}

void ShootLayer::Notification_delObserver(){
    
    //    CCNotificationCenter::getInstance()->removeObserver( this, NF_DEL_STAR);
    CCNotificationCenter::getInstance()->removeAllObservers( this );
}

void ShootLayer::Notification_shoot_bullet(cocos2d::Ref *obj){
    //发射
    ShootRef *ref = (ShootRef *)obj;
    ShootNode *shoot = ShootNode::create( ref );
    this->addChild( shoot );
}


#pragma mark - Action
void ShootLayer::callback2(Ref* pSender, cocos2d::Ref* ref){
    
    CCLOG("也要推送，将自己删除");
    
    //也要推送，将自己删除
    CCNotificationCenter::getInstance()->postNotification(NF_DEL_BULLET, ref);
}

