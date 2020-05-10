#pragma once

//Headers
#include <State.h>

//Forward declarations
class TransitionMenu;

class NextLevelState : public State 
{
    private: 
        TransitionMenu* menu;
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