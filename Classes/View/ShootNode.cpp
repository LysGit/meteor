//
//  ShootNode.cpp
//  meteor
//
//  Created by lys on 14-7-1.
//
//

#include "ShootNode.h"
#include "../Data/Configure.h"
USING_NS_CC;

bool ShootNode::init(){
    
	if ( !CCNode::init() ){
		return false;
	}

    this->UI_addParticle();
    this->UI_moving();
    
	return true;
}

ShootNode::ShootNode(ShootRef *ref ){
    
    this->setShootRef( ref );
}
ShootNode::~ShootNode(){
    
}

ShootNode* ShootNode::create(ShootRef *ref ){
    
    ShootNode *pRet = new ShootNode( ref );
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

Rect ShootNode::getRect(){
    
    _rect = Rect(this->getPosition().x, this->getPosition().y, 64, 64);
    return _rect;
}

void ShootNode::UI_addParticle(){
    
    Point pt0 = Point();
    Point pt1 = Point( Director::getInstance()->getWinSize().width, Director::getInstance()->getWinSize().height );
    
    float f0 = _shootRef->getStartPoint().getDistance( _shootRef->getEndPoint() );
    float f1 = pt0.getDistance( pt1 );
    float duration = f0/f1 *_shootRef->getDuration();
    
    
    Point delta = _shootRef->getStartPoint() - _shootRef->getEndPoint();
    
    //出一个星星试试
    ParticleSystemQuad *particle = CCParticleSystemQuad::create("Shoot.plist");
    this->addChild( particle );
    particle->setDuration( duration ); //持续时间
    particle->setPosition( Point() );
    
    //上270下90左0右180
    float x = delta.x;
    float y = delta.y;
    
    float angle ;
    
    if (  delta.x == 0.0f ) {
        if ( delta.y >= 0.0f ) {
            angle = 90;
        }else{
            angle = 270;
        }
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
    
    
    //以下为测试部分
//    particle->setSpeed( duration );
    particle->setStartColor( Color4F(1, 0.65, 0.32, 1) );
    particle->setEndColor( Color4F(0, 0, 0.32, 1) );
}

void ShootNode::UI_moving(){
    
    Point pt0 = Point();
    Point pt1 = Point( Director::getInstance()->getWinSize().width, Director::getInstance()->getWinSize().height );
    
    float f0 = _shootRef->getStartPoint().getDistance( _shootRef->getEndPoint() );
    float f1 = pt0.getDistance( pt1 );
    float duration = f0/f1 *_shootRef->getDuration();
    
    this->setPosition( _shootRef->getStartPoint() );
    MoveTo *to = MoveTo::create( duration, _shootRef->getEndPoint() );
    this->runAction( to );
    
    //    CCNotificationCenter::getInstance()->postNotification(NF_BULLET_MOVING, this);
}

void ShootNode::callback2(Ref* pSender){

    //也要推送，将自己删除
//    CCNotificationCenter::getInstance()->postNotification(NF_DEL_STAR, _starRef);
}
