//
//  ShootNode.h
//  meteor
//
//  Created by lys on 14-7-1.
//
//

#ifndef __meteor__ShootNode__
#define __meteor__ShootNode__

#include "cocos2d.h"
#include "../Model/ShootModel.h"


class ShootNode : public cocos2d::Node{
public:
    
    bool init();
    ShootNode(ShootRef *);
    ~ShootNode();
    
    static ShootNode* create(ShootRef *);
    CC_SYNTHESIZE( ShootRef *, _shootRef, ShootRef);
    
    //Data
    cocos2d::Rect getRect();
    
    //UI
    void UI_addParticle();
    void UI_moving();
    
    //Action
    void callback2(cocos2d::Ref* pSender);
    
private:
    cocos2d::Rect _rect;
};

#endif /* defined(__meteor__ShootNode__) */
