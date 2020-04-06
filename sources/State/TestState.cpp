#include "TestState.h"
#include <Render.h>
#include <iostream>
#include <Physics.h>

 void TestState::initState()
{
    type = State::TEST;
    p = new Physics();
} 


void TestState::update(float dt)
{
    p->update(dt);
}


void TestState::clear()
{
    delete p;
}