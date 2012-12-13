//
//  Poker.h
//  Test
//
//  Created by shin on 12/13/12.
//
//

#ifndef __Test__Poker__
#define __Test__Poker__

#include "CCPlatformMacros.h"

enum PokerType {//黑红梅方
    kSPADE,
    kHEART,
    kCLUB,
    kDIAMOND,
};

class Poker {
    
public:
    Poker(int value,int type){ m_value = value; m_type = type; };
    ~Poker();
    
    CC_SYNTHESIZE(int, m_value, Value);
    CC_SYNTHESIZE(int, m_type, Type);

};



#endif /* defined(__Test__Poker__) */
