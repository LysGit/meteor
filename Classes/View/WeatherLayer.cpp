//
//  WeatherLayer.cpp
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#include "WeatherLayer.h"
USING_NS_CC;

bool WeatherLayer::init(){
	if ( !CCLayer::init() ){
		return false;
	}
    
	return true;
}

void WeatherLayer::onEnter(){
    CCLayer::onEnter();
}

void WeatherLayer::onEnterTransitionDidFinish(){
    CCLayer::onEnterTransitionDidFinish();
    
    Size mSize = Director::getInstance()->getWinSize();
    
//    ParticleSystemQuad *system = CCParticleSystemQuad::create("Galaxy.plist");
//    system->setPosition( Point( mSize.width, mSize.height ));
//    this->addChild(system, 1);
//    
//    MoveTo *to = MoveTo::create(2, Point(mSize.width, 0) );
//    system->runAction( to );
    
//    ParticleSystemQuad *rain = CCParticleSystemQuad::create("Rain.plist");
//    rain->setPosition( Point( mSize.width *0.5, mSize.height  ));
//    rain->setScale( 2 );
//    this->addChild( rain);
    
//    ParticleSystemQuad *snow = CCParticleSystemQuad::create("Snow.plist");
//    snow->setPosition( Point( mSize.width *0.5, mSize.height  ));
//    this->addChild( snow );
    
//    ParticleSystemQuad *eilpticalGalaxy = CCParticleSystemQuad::create("EilpticalGalaxy.plist");
//    eilpticalGalaxy->setPosition( Point( mSize.width *0.5, mSize.height *0.5 ));
//    this->addChild( eilpticalGalaxy );
//    eilpticalGalaxy->setDuration(10);
    
//    ParticleSystemQuad *cloud = CCParticleSystemQuad::create("Cloud.plist");
//    cloud->setPosition( Point( mSize.width, mSize.height*0.5  ));
//    this->addChild( cloud );
    
//    ParticleSystemQuad *starrySky = CCParticleSystemQuad::create("StarrySky.plist");
//    starrySky->setPosition( Point( mSize.width*0.5, mSize.height*0.5  ));
//    this->addChild( starrySky );
    
//    ParticleSystemQuad *snowySlow = CCParticleSystemQuad::create("SnowySlow.plist");
//    snowySlow->setPosition( Point( mSize.width*0.5, mSize.height  ));
//    this->addChild( snowySlow );
    
//    ParticleSystemQuad *narrowRain = CCParticleSystemQuad::create("NarrowRain.plist");
//    narrowRain->setPosition( Point( mSize.width*0.5, mSize.height  ));
//    this->addChild( narrowRain );
    
//    ParticleSystemQuad *fireballMagic = CCParticleSystemQuad::create("FireballMagic.plist");
//    fireballMagic->setPosition( Point( mSize.width*0.5, mSize.height*0.5  ));
//    this->addChild( fireballMagic );
    
//    MoveTo *to = MoveTo::create(2, Point( 200, 20) );
//    fireballMagic->runAction( to );
    
    Sprite *sp = Sprite::create("wind.png");
    sp->setPosition( Point( mSize.width*0.5, mSize.height*0.5) );
    sp->setTag( 10086 );
    
    this->addChild( sp );
    

    DelayTime *delay = DelayTime::create( 1.5 );
    MoveTo *mTo = MoveTo::create(1.5, Point( mSize.width*0.5, mSize.height) );
//    RotateTo *rTo = RotateTo::create(1.5, 270);
//    Repeat *repeate = Repeat::create(rTo, 3);
    
    DelayTime *delay2 = DelayTime::create( 1.5 );
    
//    Spawn *spawn = Spawn::create(mTo,rTo, NULL);
    
    CallFunc *cf = CallFunc::create( CC_CALLBACK_0(WeatherLayer::delSymbol, this));
    Sequence *sq = Sequence::create( delay, mTo, delay2, cf, NULL);
    this->runAction( sq );

}

void WeatherLayer::delSymbol(){
    
    Node *sp = this->getChildByTag( 10086 );
    sp->removeFromParentAndCleanup( true );
    
    //慢慢出现天气
    
    //爆炸声
}
