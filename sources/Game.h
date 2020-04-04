#pragma once
#include <State.h>


class Game
{
    private:;
        State* state;
        Game(){}
    public:
        static Game* getInstance(){
            static Game only_instance;
            return &only_instance;
        }
        
        void run();
        void setState(State::stateType type);
        void inicio();
};