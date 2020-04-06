#pragma once
#include "State.h"

class Physics;
class TestState : public State 
{
    private:
        TestState(){}
        Physics* p;
        float rot = 0;      
    public:

         static TestState* getInstance(){
            static TestState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};