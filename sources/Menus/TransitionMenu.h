#pragma once

//Headers
#include <Menu.h>
#include <Hud.h>


class TransitionMenu : public Menu
{
    public:
        TransitionMenu() : Menu()
        {
            //Buttons
            Button* button = new Button(1, (char*)"resources/MenuElements/START2.png", 
                                                (char*)"resources/MenuElements/START1.png", 540, 540);
            buttons.push_back(button);            
            button = new Button(2, (char*)"resources/MenuElements/EXIT2.png",
                                                (char*)"resources/MenuElements/EXIT1.png", 540, 660);
            buttons.push_back(button);
            
            buttons.at(focus)->focus();
        
            titulo = Render::getInstance() -> createSprite("resources/Titulo.png");
            background = Render::getInstance() -> createSprite("resources/MenuElements/BACKGROUND_menu.png");


        }

        ~TransitionMenu(){}
};