#pragma once
#include "State.h"

class PlayState : public State 
{
    private:
        bool loaded; 
        PlayState(){}         
    public:

         static PlayState* getInstance(){
            static PlayState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
};