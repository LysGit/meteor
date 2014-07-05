//
//  GameOverLayer.h
//  meteor
//
//  Created by lys on 14-6-30.
//
//

#ifndef __meteor__GameOverLayer__
#define __meteor__GameOverLayer__

#include "cocos2d.h"

class GameOverLayer : public cocos2d::LayerColor
{
public:
    
	virtual bool init();
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
	
	CREATE_FUNC( GameOverLayer );
};

#endif /* defined(__meteor__GameOverLayer__) */
