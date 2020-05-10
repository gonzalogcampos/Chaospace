#pragma once

//Headers
#include <Menu.h>


class ControlMenu : public Menu
{
    public:
        ControlMenu() : Menu()
        {
            //Buttons
        
            background = Render::getInstance() -> createSprite("resources/MenuElements/CONTROLES.png");
            

        }

        ~ControlMenu(){}

        void draw(){
            Menu::draw();
        }

        void clear(){
            Menu::clear();
        }
};