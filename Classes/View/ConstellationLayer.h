//
//  ConstellationLayer.h
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#ifndef __meteor__ConstellationLayer__
#define __meteor__ConstellationLayer__

#include "cocos2d.h"

class ConstellationLayer : public cocos2d::Layer
{
public:
    
	virtual bool init();
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
	
	CREATE_FUNC( ConstellationLayer );
};

#endif /* defined(__meteor__ConstellationLayer__) */
