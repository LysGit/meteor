//
//  StarrySkyController.cpp
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#include "StarrySkyController.h"
#include "../Data/Configure.h"
#include "../View/TransitionLayer.h"
#include "../View/GameOverLayer.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* StarrySkyController::createScene(){
    
	Scene *scene = Scene::create();
	StarrySkyController *layer = StarrySkyController::create();
	scene->addChild(layer);
	return scene;
}

bool StarrySkyController::init(){
	if ( !CCLayer::init() ){
		return false;
	}
    
    //更新函数
//    scheduleUpdate();
    
    this->DATA_init();
    this->UI_init();
    
	return true;
}

void StarrySkyController::update(float delta){

    if ( _starModel->_vector.size() <= 0 && _shootModel->_vector.size() <= 0 ) {
        CCLOG(" 哦 ");
    }else{
        CCLOG(" 检测碰撞 ");
    }
}

void StarrySkyController::onExit(){
    CCLayer::onExit();
    
    _starModel->release();
    _shootModel->release();
    
    this->Notification_delObserver();
}

void StarrySkyController::onEnter(){
    CCLayer::onEnter();
    this->Notification_addObserver();
}

void StarrySkyController::onEnterTransitionDidFinish(){
    CCLayer::onEnterTransitionDidFinish();
    
    TransitionLayer *layer = TransitionLayer::create();
    this->addChild( layer );
}
void StarrySkyController::DATA_init(){
    
    _starModel = StarModel::create();
    _starModel->retain();
    
    _shootModel = ShootModel::create();
    _shootModel->retain();
    
    //测试
    _starModel->_vector.pushBack( StarRef::create() );
    
}

void StarrySkyController::UI_init(){


    //添加基本层
//    _constellationLayer = ConstellationLayer::create();
//    this->addChild( _constellationLayer );
    
    _starLayer = StarLayer::create();
    _starLayer->setModel( _starModel );
    this->addChild( _starLayer );
    
    _shootLayer = ShootLayer::create();
    _shootLayer->setModel( _shootModel );
    this->addChild( _shootLayer );
    
//    _weatherLayer = WeatherLayer::create();
//    this->addChild( _weatherLayer );
    
//    _menuLayer = MenuLayer::create( true );
//    this->addChild( _menuLayer );

    _optimizeTouchLayer = OptimizeTouchLayer::create();
    this->addChild( _optimizeTouchLayer );

    _starLayer->UI_update();
    _shootLayer->UI_update();

    
    GameOverLayer *gameOverLayer = GameOverLayer::create();
    this->addChild( gameOverLayer );
}

void StarrySkyController::Notification_addObserver(){
    
    CCNotificationCenter::getInstance()->addObserver( this,
                                                     callfuncO_selector(StarrySkyController::Notification_delete_starNode),
                                                     NF_DEL_STAR,
                                                     NULL);
    CCNotificationCenter::getInstance()->addObserver( this,
                                                     callfuncO_selector(StarrySkyController::Notification_shoot_bullet),
                                                     NF_SHOOT_BULLET,
                                                     NULL);
    CCNotificationCenter::getInstance()->addObserver( this,
                                                     callfuncO_selector(StarrySkyController::Notification_delete_shoot),
                                                     NF_DEL_BULLET,
                                                     NULL);
    
    CCNotificationCenter::getInstance()->addObserver( this,
                                                     callfuncO_selector(StarrySkyController::Notification_menu_refresh),
                                                     NF_MENU_REFRESH,
                                                     NULL);
    CCNotificationCenter::getInstance()->addObserver( this,
                                                     callfuncO_selector(StarrySkyController::Notification_menu_recover),
                                                     NF_MENU_RECOVER,
                                                     NULL);
    CCNotificationCenter::getInstance()->addObserver( this,
                                                     callfuncO_selector(StarrySkyController::Notification_menu_share),
                                                     NF_MENU_SHARE,
                                                     NULL);
}
void StarrySkyController::Notification_delObserver(){
    
//    CCNotificationCenter::getInstance()->removeObserver( this, NF_DEL_STAR);
    CCNotificationCenter::getInstance()->removeAllObservers( this );
}

void StarrySkyController::Notification_delete_starNode(cocos2d::Ref *obj){
    
    CCLOG("StarrySkyController 收到！");
//    StarRef *ref = (StarRef *)obj;
    _starModel->_vector.clear();
    CCLOG("处理:%ld" , _starModel->_vector.size() );
    
    _starLayer->UI_update();
}

void StarrySkyController::Notification_shoot_bullet(cocos2d::Ref *obj){
    //发射
    CocosDenshion::SimpleAudioEngine::getInstance()->playEffect( "rush.mp3" );
    
    ShootRef *ref = (ShootRef *)obj;
    _shootModel->_vector.pushBack( ref );
    _shootLayer->UI_update();
}

void StarrySkyController::Notification_delete_shoot(cocos2d::Ref *obj){
    
    CCLOG("删除");
    ShootRef *ref = (ShootRef *)obj;
    _shootModel->_vector.eraseObject( ref );
}

void StarrySkyController::Notification_menu_refresh(cocos2d::Ref *obj){
    CCLOG("新建");
    
    auto scene = StarrySkyController::createScene();
    Director::getInstance()->replaceScene( scene );
    
}
void StarrySkyController::Notification_menu_recover(cocos2d::Ref *obj){
    CCLOG("恢复");
}
void StarrySkyController::Notification_menu_share(cocos2d::Ref *obj){
    CCLOG("分享");
}
