//
//  TransitionLayer.cpp
//  meteor
//
//  Created by lys on 14-6-30.
//
//

#include "TransitionLayer.h"
USING_NS_CC;

bool TransitionLayer::init(){
	if ( !LayerColor::initWithColor(Color4B( 0, 0, 0, 255) ) ){
		return false;
	}
    
	return true;
}

void TransitionLayer::onEnter(){
    CCLayer::onEnter();
    
    Size mSize = Director::getInstance()->getWinSize();
    
    ParticleSystemQuad *eilpticalGalaxy = CCParticleSystemQuad::create("EilpticalGalaxy.plist");
    eilpticalGalaxy->setPosition( Point( mSize.width *0.5, mSize.height *0.5 ));
    this->addChild( eilpticalGalaxy );
    eilpticalGalaxy->setDuration( 3 );

    DelayTime *delay = DelayTime::create( 1.5 );
    FadeTo *in = FadeTo::create( 1.5, 0);
    CallFunc *cf = CallFunc::create( CC_CALLBACK_0(TransitionLayer::close, this));
    Sequence *sq = Sequence::create( delay, in, cf, NULL);
    this->runAction( sq );
}

void TransitionLayer::close(){
    this->removeFromParentAndCleanup( true );
}
