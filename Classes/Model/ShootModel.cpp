//
//  ShootModel.cpp
//  meteor
//
//  Created by lys on 14-7-1.
//
//

#include "ShootModel.h"
USING_NS_CC;

bool ShootRef::init(){
    
    if ( !CCNode::init() ){
		return false;
	}

    _startPoint = Point();
    _endPoint = Point();
    _duration = 3.0f;
    _tag = 1;
    _iState = 0;
    return true;
};

bool ShootModel::init(){
    
    if ( !CCNode::init() ){
		return false;
	}
    
    return true;
};
