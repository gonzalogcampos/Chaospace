#pragma once

//Headers
#include <State.h>

//Forward declarations

class NextLevelState : public State 
{
    private: 
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