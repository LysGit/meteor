//
//  ConstellationLayer.cpp
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#include "ConstellationLayer.h"
USING_NS_CC;

bool ConstellationLayer::init(){
	if ( !CCLayer::init() ){
		return false;
	}
    
	return true;
}

void ConstellationLayer::onEnter(){
    CCLayer::onEnter();
}

void ConstellationLayer::onEnterTransitionDidFinish(){
    CCLayer::onEnterTransitionDidFinish();
}
