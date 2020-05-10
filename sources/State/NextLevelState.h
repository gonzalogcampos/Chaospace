#pragma once

//Headers
#include <State.h>

//Forward declarations
class Menu;

class NextLevelState : public State 
{
    private: 
        Menu* menu;
        unsigned int cursor; 
        NextLevelState(){}         
    public:

        static NextLevelState* getInstance(){
            static NextLevelState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
        virtual void draw();

};