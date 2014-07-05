//
//  StarrySkyController.h
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#ifndef __meteor__StarrySkyController__
#define __meteor__StarrySkyController__

#include "cocos2d.h"

#include "../View/ConstellationLayer.h"
#include "../View/StarLayer.h"
#include "../View/ShootLayer.h"
#include "../View/WeatherLayer.h"
#include "../View/MenuLayer.h"
#include "../View/OptimizeTouchLayer.h"

#include "../Model/StarModel.h"
#include "../Model/ShootModel.h"

class StarrySkyController : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
	virtual bool init();
    virtual void onExit();
    virtual void onEnter();
    virtual void onEnterTransitionDidFinish();
	CREATE_FUNC( StarrySkyController );
    
    void DATA_init();
    void UI_init();
    
    void update(float delta);
    
protected:
    void Notification_addObserver();
    void Notification_delObserver();
    void Notification_delete_starNode(cocos2d::Ref *obj);
    void Notification_shoot_bullet(cocos2d::Ref *obj);
    void Notification_delete_shoot(cocos2d::Ref *obj);
    
    void Notification_menu_refresh(cocos2d::Ref *obj);
    void Notification_menu_recover(cocos2d::Ref *obj);
    void Notification_menu_share(cocos2d::Ref *obj);
    
private:
    
    //layer
    ConstellationLayer *_constellationLayer;
    StarLayer *_starLayer;
    ShootLayer  *_shootLayer;
    WeatherLayer *_weatherLayer;
    MenuLayer *_menuLayer;
    OptimizeTouchLayer *_optimizeTouchLayer;
    
    //model
    StarModel *_starModel;
    ShootModel *_shootModel;
};

#endif /* defined(__meteor__StarrySkyController__) */
