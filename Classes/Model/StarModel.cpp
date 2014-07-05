//
//  StarModel.cpp
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#include "StarModel.h"
USING_NS_CC;

bool StarRef::init(){
    
    if ( !CCNode::init() ){
		return false;
	}
    
    _startPoint = Point(100, 100);
    _endPoint = Point(100, 300);
    _duration = 3.0f;
    _tag = 1;
    _iState = 0;
    
    return true;
};

bool StarModel::init(){
    
    if ( !CCNode::init() ){
		return false;
	}
    
    return true;
};
