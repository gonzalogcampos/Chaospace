#pragma once

//Headers
#include <State.h>

//Forward declarations
class Menu;

class FinalState : public State 
{
    private: 
        Menu* menu;
        FinalState(){}         
    public:

        static FinalState* getInstance(){
            static FinalState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
        virtual void draw();

};