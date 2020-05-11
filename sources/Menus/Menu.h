#pragma once

//External headers
#include <vector>
#include <string>
#include <SFML/Audio.hpp>

namespace sf
{
class Font;
class Text;
class RectangleShape;
}

class Button
{
    private:
        unsigned int sprite;
        float x, y;
        unsigned int spritenormal;
        unsigned int spritefocus;
        int id;
        
        

    public:

        Button(int id, char* pathnormal, char* pathfocus, float x, float y);
        ~Button();
      
        int getID(){return id;}


        void focus();
        void unfocus();
        void setPosition(float x, float y);
        void update();
        void draw();


};

class Menu
{
    protected:
        std::vector<Button*> buttons;
        std::size_t focus;
        float at;
        unsigned int background;
        sf::Sound sound;
        sf::SoundBuffer buffer;
        

    public:

        Menu(){focus = 0;}
        ~Menu(){clear();}
        void clear();
        void down();
        void up();
        void update(float dt);
        void draw();

        int click();
};



