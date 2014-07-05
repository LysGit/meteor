//
//  OptimizeTouchLayer.h
//  meteor
//
//  Created by lys on 14-7-1.
//
//

#ifndef __meteor__OptimizeTouchLayer__
#define __meteor__OptimizeTouchLayer__

#include "cocos2d.h"

class OptimizeTouchLayer : public cocos2d::LayerColor {
public:
    virtual bool init();
    CREATE_FUNC( OptimizeTouchLayer );

    virtual void addTouchEvent() final;
    virtual void close();
    
protected:
    virtual void gesture();
    
private:
    cocos2d::EventListenerTouchOneByOne *_myListener;
    cocos2d::Point _startTouch;
    cocos2d::Point _endTouch;
};

#endif /* defined(__meteor__OptimizeTouchLayer__) */
