//
//  StarLayer.h
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#ifndef __meteor__StarLayer__
#define __meteor__StarLayer__

#include "cocos2d.h"
#include "../Model/StarModel.h"

class StarLayer : public cocos2d::Layer
{
public:

	virtual bool init();
    virtual void onExit();
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
	
	CREATE_FUNC( StarLayer );

    CC_SYNTHESIZE_RETAIN( StarModel *, _model, Model);
    
    void UI_update();
    
protected:
    void Notification_addObserver();
    void Notification_delObserver();
    void Notification_delete_starNode(cocos2d::Ref *obj);
};

#endif /* defined(__meteor__StarLayer__) */
