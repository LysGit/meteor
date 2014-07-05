//
//  CreateRandom.cpp
//  meteor
//
//  Created by lys on 14-7-2.
//
//

#include "CreateRandom.h"

static CreateRandom *m_Singleton = nullptr;

CreateRandom *CreateRandom::getInstance()
{
    if (!m_Singleton)
    {
        m_Singleton = new CreateRandom();
    }
    return m_Singleton;
}
