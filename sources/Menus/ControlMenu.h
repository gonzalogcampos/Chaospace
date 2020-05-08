#pragma once

//Headers
#include <Menu.h>


class ControlMenu : public Menu
{
    public:
        ControlMenu() : Menu()
        {
            //Buttons
        
            //titulo = Render::getInstance() -> createSprite("resources/Titulo.png");
            background = Render::getInstance() -> createSprite("resources/MenuElements/CONTROLES.png");
            

        }

        ~ControlMenu(){}
};