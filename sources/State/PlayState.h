#pragma once

//Headers
#include <State.h>

//Forward declarations
class Map;
class Hud;
class Render;

namespace sf
{
class RectangleShape;
class Color;
}


class PlayState : public State 
{
    private:
        bool loaded; 
        Map* map;
        bool paused;
        unsigned int sprite_pausa;
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