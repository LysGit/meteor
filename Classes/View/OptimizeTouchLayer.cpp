//
//  OptimizeTouchLayer.cpp
//  meteor
//
//  Created by lys on 14-7-1.
//
//

#include "OptimizeTouchLayer.h"
#include "../Data/Configure.h"
#include "../Model/ShootModel.h"

USING_NS_CC;

bool OptimizeTouchLayer::init(){
    
    if ( !CCLayerColor::init() ){
		return false;
	}
    
    this->addTouchEvent();
    
    return true;
}

void OptimizeTouchLayer::close(){
    
    _eventDispatcher->removeEventListener( _myListener );
}

void OptimizeTouchLayer::addTouchEvent()
{
    _myListener = EventListenerTouchOneByOne::create();
    _myListener->setSwallowTouches( true );
    _myListener->onTouchBegan = [=](Touch* touch,Event* event)
    {
        _startTouch = touch->getLocation(); //（坐标原点在左下角）
        return true;
    };
    _myListener->onTouchEnded = [=](Touch* touch,Event* event)
    {

            _endTouch = touch->getLocation();
            Point delta = _startTouch - _endTouch;
        if ( abs( delta.x )> 15 || abs( delta.y )> 15 ) {
            this->gesture();
        }
    };
    
    //注册监听
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithFixedPriority( _myListener, 200);
}

void OptimizeTouchLayer::gesture(){
    
    ShootRef *ref = ShootRef::create();
    ref->setStartPoint( _startTouch );
    ref->setEndPoint( _endTouch );
    
    CCNotificationCenter::getInstance()->postNotification(NF_SHOOT_BULLET, ref);
}