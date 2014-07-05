//
//  StarNode.cpp
//  meteor
//
//  Created by lys on 14-6-29.
//
//

#include "StarNode.h"
#include "../Data/Configure.h"
USING_NS_CC;

bool StarNode::init(){
    
	if ( !CCNode::init() ){
		return false;
	}
    
    this->UI_addParticle();
    this->UI_moving();
    
	return true;
}

StarNode::StarNode(StarRef *ref ){
    
    this->setStarRef( ref );
}
StarNode::~StarNode(){
    
}

StarNode* StarNode::create(StarRef *ref ){
    
    StarNode *pRet = new StarNode( ref );
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

Rect StarNode::getRect(){
    
    _rect = Rect(this->getPosition().x, this->getPosition().y, 64, 64);
    return _rect;
}

void StarNode::UI_addParticle(){
    
    Point delta = _starRef->getStartPoint() - _starRef->getEndPoint();
    
    //出一个星星试试
    ParticleSystemQuad *particle = CCParticleSystemQuad::create("Shoot.plist");
    this->addChild( particle );
    particle->setDuration( _starRef->getDuration() ); //持续时间
    particle->setPosition( Point() );
    
    //上270下90左0右180
    float x = delta.x;
    float y = delta.y;
    
    float angle ;
    
    if ( ( delta.x > -0.01 || delta.x < 0.01 ) ) {
        angle = 270;
    }else{
        angle = fabs( atanf( delta.y/delta.x ) *180/3.1415 );
    }

    if ( x >= 0 && y > 0) {
        
    }else if ( x < 0 && y >= 0 ){
        angle += 90;
    }else if ( x < 0 && y <= 0 ){
        angle += 180;
    }else if ( x >= 0 && y < 0 ){
        angle += 270;
    }
    
    particle->setAngle( angle );
    particle->setAngleVar( 0 );
}

void StarNode::callback2(Ref* pSender){
    
    //也要推送，将自己删除
    CCNotificationCenter::getInstance()->postNotification(NF_DEL_STAR, _starRef);
}

void StarNode::UI_moving(){
    
    Point pt0 = Point();
    Point pt1 = Point( Director::getInstance()->getWinSize().width, Director::getInstance()->getWinSize().height );
    
    float f0 = _starRef->getStartPoint().getDistance( _starRef->getEndPoint() );
    float f1 = pt0.getDistance( pt1 );
    float duration = f0/f1 *_starRef->getDuration();
    
    this->setPosition( _starRef->getStartPoint() );
    MoveTo *to = MoveTo::create( duration, _starRef->getEndPoint() );
//    this->runAction( to );
    _starRef->setState( PSQ_Moving );
    
    
    //清除事件
    CallFuncN *cfn = CallFuncN::create( CC_CALLBACK_1(StarNode::callback2, this ));
    Sequence *sq2 = Sequence::create( to, cfn, NULL);
    
    this->runAction( sq2 );
    
//    CCNotificationCenter::getInstance()->postNotification(NF_ADD_STAR, this);
}

/*
 Sprite *sp = Sprite::create( "star.png" );
 sp->setPosition( Point( _starRef->getBeginX(), _starRef->getBeginY() ) );
 this->addChild( sp );
 
 //闪烁事件
 FadeTo *in = FadeTo::create(3, 76);
 FadeTo *out = FadeTo::create(3, 255);
 Sequence *sq = Sequence::create( in, out, NULL);
 Repeat *rt = Repeat::create( sq, 2);
 
 //清除事件
 CallFuncN *cfn = CallFuncN::create( CC_CALLBACK_1(StarNode::callback2, this ));
 Sequence *sq2 = Sequence::create( rt, cfn, NULL);
 
 sp->runAction( sq2 );
 
 
 //    DelayTime *delay = DelayTime::create( 1 );
 //    CallFuncN *cfn = CallFuncN::create( CC_CALLBACK_1(StarNode::callback2, this ));
 //    Sequence *sq2 = Sequence::create( delay, cfn, NULL);
 //    this->runAction( sq2 );


void StarNode::callback2(Node* pSender){
    
    CCLOG("推送开始" );
    CCNotificationCenter::getInstance()->postNotification(NF_DEL_STAR, _starRef);
}
 */

