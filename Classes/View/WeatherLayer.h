//
//  WeatherLayer.h
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#ifndef __meteor__WeatherLayer__
#define __meteor__WeatherLayer__

#include "cocos2d.h"

class WeatherLayer : public cocos2d::Layer
{
public:
    
	virtual bool init();
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
	
	CREATE_FUNC( WeatherLayer );
    
    
    void delSymbol();
};

#endif /* defined(__meteor__WeatherLayer__) */
