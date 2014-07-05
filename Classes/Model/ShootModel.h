//
//  ShootModel.h
//  meteor
//
//  Created by lys on 14-7-1.
//
//

#ifndef __meteor__ShootModel__
#define __meteor__ShootModel__

#include "cocos2d.h"

class ShootRef : public cocos2d::Node {
public:
    
    bool init();
    CREATE_FUNC( ShootRef );
    
    CC_SYNTHESIZE(cocos2d::Point, _startPoint, StartPoint);
    CC_SYNTHESIZE(cocos2d::Point, _endPoint, EndPoint);
    CC_SYNTHESIZE(float, _duration, Duration);
    
    CC_SYNTHESIZE(int, _iState, State);
    CC_SYNTHESIZE(int, _tag, Tag);//删除时可能需要
};

class ShootModel : public cocos2d::Node {
public:
    bool init();
    CREATE_FUNC( ShootModel );
    
    cocos2d::Vector<ShootRef *> _vector;
};

#endif /* defined(__meteor__ShootModel__) */
