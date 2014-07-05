//
//  StarModel.h
//  meteor
//
//  Created by 罗耀生 on 14-6-28.
//
//

#ifndef __meteor__StarModel__
#define __meteor__StarModel__

#include "cocos2d.h"

class StarRef : public cocos2d::Node {
public:
    
    bool init();
    CREATE_FUNC( StarRef );
    
    CC_SYNTHESIZE(cocos2d::Point, _startPoint, StartPoint);
    CC_SYNTHESIZE(cocos2d::Point, _endPoint, EndPoint);
    CC_SYNTHESIZE(float, _duration, Duration);

    CC_SYNTHESIZE(int, _iState, State);
    CC_SYNTHESIZE(int, _tag, Tag);//删除时可能需要
};


class StarModel : public cocos2d::Node {
public:
    bool init();
    CREATE_FUNC( StarModel );

    cocos2d::Vector<StarRef *> _vector;
};

#endif /* defined(__meteor__StarModel__) */
