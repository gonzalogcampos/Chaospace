#pragma once
#include "State.h"

class MenuState : public State 
{
    private: 
        MenuState(){}         
    public:

        static MenuState* getInstance(){
            static MenuState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};