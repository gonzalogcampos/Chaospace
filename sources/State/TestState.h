#pragma once
#include "State.h"

class TestState : public State 
{
    private:
        TestState(){}
        unsigned int sprite1, sprite2, sprite3; 
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