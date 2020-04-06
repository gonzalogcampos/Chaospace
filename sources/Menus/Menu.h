#pragma once
#include <iostream>
#include <vector>



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


};

class Menu
{
    protected:
        std::vector<Button*> buttons;
        std::size_t focus;
        float at;

    public:

        Menu(){focus = 0;}
        ~Menu(){clear();}
        void clear();
        void down();
        void up();
        void setBackground(char* b);
        void update(float dt);

        int click();
};



