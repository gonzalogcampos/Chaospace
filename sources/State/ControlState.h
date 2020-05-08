#pragma once

//Headers
#include <State.h>

//Forward declarations
class Menu;

class ControlState : public State 
{
    private: 
        Menu* menu;
        ControlState(){}
    public:

        static ControlState* getInstance(){
            static ControlState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
        virtual void draw();

};