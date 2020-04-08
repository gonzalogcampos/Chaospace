#pragma once

//Headers
#include <State.h>

//Forward declarations
class Clock;

class Game
{
    private:
        Clock* clock;
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