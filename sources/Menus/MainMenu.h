#pragma once

//Headers
#include <Menu.h>


class MainMenu : public Menu
{
    public:
        MainMenu() : Menu()
        {   
            //Buttons
            Button* button = new Button(1, (char*)"resources/MenuElements/PLAY2.png", 
                                                (char*)"resources/MenuElements/PLAY1.png", 540, 300);

            buttons.push_back(button);            

            button = new Button(2, (char*)"resources/MenuElements/EXIT2.png",
                                                (char*)"resources/MenuElements/EXIT1.png", 540, 420);
            buttons.push_back(button);
            
            buttons.at(focus)->focus();

            titulo = Render::getInstance() -> createSprite("resources/Titulo.png");
        }

        ~MainMenu()
        {
        }

};