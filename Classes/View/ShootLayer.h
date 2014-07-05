//
//  ShootLayer.h
//  meteor
//
//  Created by lys on 14-7-2.
//
//

#ifndef __meteor__ShootLayer__
#define __meteor__ShootLayer__

#include "cocos2d.h"
#include "../Model/ShootModel.h"

class ShootLayer : public cocos2d::Layer
{
public:
    
	virtual bool init();
    virtual void onExit();
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
	
	CREATE_FUNC( ShootLayer );
    
    CC_SYNTHESIZE_RETAIN( ShootModel *, _model, Model);
    
    void UI_update();
    
    void shoot_end(cocos2d::Node* pSender);//考虑类型是否能正确转化呢？！！！
    
    //Action
    void callback2(cocos2d::Ref* pSender, cocos2d::Ref* ref);
    
protected:
    void Notification_addObserver();
    void Notification_delObserver();
    void Notification_shoot_bullet(cocos2d::Ref *obj);
};

#endif /* defined(__meteor__ShootLayer__) */
