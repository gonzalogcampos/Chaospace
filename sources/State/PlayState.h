#pragma once

//Headers
#include <State.h>

//Forward declarations
class Map;
class Hud;


class PlayState : public State 
{
    private:
        bool loaded; 
        Map* map;
        bool paused;
        PlayState(){}         
    public:
         static PlayState* getInstance(){
            static PlayState only_instance;
            return &only_instance;
        }
        virtual void initState();
        virtual void update(float dt);
        virtual void clear();
        virtual void draw();

};