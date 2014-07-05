//
//  TransitionLayer.h
//  meteor
//
//  Created by lys on 14-6-30.
//
//

#ifndef __meteor__TransitionLayer__
#define __meteor__TransitionLayer__

#include "cocos2d.h"

class TransitionLayer : public cocos2d::LayerColor
{
public:
    
	virtual bool init();
    virtual void onEnter();
	CREATE_FUNC( TransitionLayer );
    
    void close();
};

#endif /* defined(__meteor__TransitionLayer__) */
