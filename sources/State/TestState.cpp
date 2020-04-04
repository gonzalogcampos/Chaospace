#include "TestState.h"
#include <Render.h>
#include <iostream>

 void TestState::initState()
{
    std::cout<<"Estoy en el init\n";
    type = State::TEST;

} 


void TestState::update(float dt)
{
    std::cout<<"Estoy en el update\n";
}


void TestState::clear()
{

}