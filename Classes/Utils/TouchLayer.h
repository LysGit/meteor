//
//  TouchLayer.h
//  meteor
//
//  Created by 罗耀生 on 14-6-29.
//
//

#ifndef __meteor__TouchLayer__
#define __meteor__TouchLayer__

#include "cocos2d.h"

class TouchLayer : public cocos2d::LayerColor {
public:
    virtual bool init();
    TouchLayer();
    TouchLayer(bool Swipe);
    ~TouchLayer();
    
    CREATE_FUNC( TouchLayer );
    static TouchLayer* create(bool Swipe);
    
    virtual void appear();
    virtual void disappear();
    virtual void close();
    
    virtual void addTouchEvent() final;
    virtual void swipeUp();
    virtual void swipeDown();
    virtual void swipeLeft();
    virtual void swipeRight();
    virtual void autochthonous();
    
protected:
    cocos2d::EventListenerTouchOneByOne *_myListener;
    cocos2d::Point _startTouch;
    bool _bSwipe;
};

#endif /* defined(__meteor__TouchLayer__) */
