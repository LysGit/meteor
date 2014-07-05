//
//  MenuLayer.h
//  meteor
//
//  Created by 罗耀生 on 14-6-29.
//
//

#ifndef __meteor__MenuLayer__
#define __meteor__MenuLayer__

#include "cocos2d.h"
#include "../Utils/TouchLayer.h"

class MenuLayer : public TouchLayer {
public:
    virtual bool init();
    MenuLayer();
    MenuLayer(bool Swipe);
    ~MenuLayer();
    
    CREATE_FUNC( MenuLayer );
    static MenuLayer* create(bool Swipe);
    
    void menuCloseCallback(cocos2d::Ref* pSender);
    
protected:
    virtual void swipeUp();
    virtual void swipeDown();
    virtual void swipeLeft();
    virtual void swipeRight();
    virtual void autochthonous();
};

#endif /* defined(__meteor__MenuLayer__) */
