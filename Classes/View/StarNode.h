//
//  StarNode.h
//  meteor
//
//  Created by lys on 14-6-29.
//
//

#ifndef __meteor__StarNode__
#define __meteor__StarNode__

#include "cocos2d.h"
#include "../Model/StarModel.h"


class StarNode : public cocos2d::Node{
public:
    
    bool init();
    StarNode(StarRef *);
    ~StarNode();
    
    static StarNode* create(StarRef *);
    CC_SYNTHESIZE( StarRef *, _starRef, StarRef);
    
    //Data
    cocos2d::Rect getRect();
    
    //UI
    void UI_addParticle();
    
    //Action
    void callback2(cocos2d::Ref* pSender);
    
    void UI_moving();
    
private:
    cocos2d::Rect _rect;
};

#endif /* defined(__meteor__StarNode__) */
