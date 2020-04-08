#pragma once

//Headers
#include <State.h>


class TestState : public State 
{
    private:
        TestState(){}
    public:

         static TestState* getInstance(){
            static TestState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};