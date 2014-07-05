//
//  TouchLayer.cpp
//  meteor
//
//  Created by 罗耀生 on 14-6-29.
//
//

#include "TouchLayer.h"
USING_NS_CC;

TouchLayer::TouchLayer(){
    
    _bSwipe = false;
}
TouchLayer::TouchLayer(bool Swipe){
    _bSwipe = Swipe;
}
TouchLayer::~TouchLayer(){
    
}

TouchLayer* TouchLayer::create(bool Swipe){
    
    TouchLayer *pRet = new TouchLayer( Swipe );
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

bool TouchLayer::init(){

    if ( !CCLayerColor::init() ){
		return false;
	}
    
    this->addTouchEvent();
    
    return true;
}

void TouchLayer::appear(){
    
}
void TouchLayer::disappear(){
    
}

void TouchLayer::close(){
    
    _eventDispatcher->removeEventListener( _myListener );
}

void TouchLayer::addTouchEvent()
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
        if ( !_bSwipe ) {
            this->autochthonous();
        }else{
            Point endTouch=touch->getLocation();
            Point delta = _startTouch - endTouch;
            if(abs(delta.x) > abs(delta.y))
            {
                //手势左右判断
                if(delta.x > 15)
                {
                    this->swipeLeft();
                }
                else if (delta.x < -15)
                {
                    this->swipeRight();
                }
            }
            else
            {
                //手势上下判断
                if(delta.y > 15)
                {
                    this->swipeDown();
                }
                else if (delta.y < -15)
                {
                    this->swipeUp();
                }
            }
        }
    };
    
    //注册监听  
    auto dispatcher = Director::getInstance()->getEventDispatcher();
    dispatcher->addEventListenerWithFixedPriority( _myListener, 200);
}

void TouchLayer::swipeUp(){
    CCLOG("向上！");
}
void TouchLayer::swipeDown(){
    CCLOG("向下！");
}
void TouchLayer::swipeLeft(){
    CCLOG("向左！");
}
void TouchLayer::swipeRight(){
    CCLOG("向右！");
}

void TouchLayer::autochthonous(){
    CCLOG("非滑动！");
}
