#pragma once
#include "Menu.h"

class MainMenu : public Menu
{
    public:
        MainMenu() : Menu()
        {
            //Buttons
            Button* button = new Button(1, (char*)"resources/MenuElements/PLAY1.png", 
                                                (char*)"resources/MenuElements/PLAY2.png",400, 100);
            buttons.push_back(button);            
            button = new Button(2, (char*)"resources/MenuElements/EXIT1.png",
                                                (char*)"resources/MenuElements/EXIT2.png" ,400, 200);
            buttons.push_back(button);
            buttons.at(focus)->focus();
        


        }

        ~MainMenu(){}
};