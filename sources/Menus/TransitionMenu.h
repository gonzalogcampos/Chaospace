#pragma once
#include <string>
#include <iostream>

//Headers
#include <Menu.h>
#include <Hud.h>
#include <Map.h>


class TransitionMenu : public Menu
{
    public:
        TransitionMenu() : Menu()
        {
            //Buttons
            Button* button = new Button(1, (char*)"resources/MenuElements/NEXT_LEVEL2.png", 
                                                (char*)"resources/MenuElements/NEXT_LEVEL1.png", 540, 540);
            buttons.push_back(button);            
            button = new Button(2, (char*)"resources/MenuElements/EXIT2.png",
                                                (char*)"resources/MenuElements/EXIT1.png", 540, 660);
            buttons.push_back(button);
            
            buttons.at(focus)->focus();
        
            titulo = Render::getInstance() -> createSprite("resources/Titulo.png");
            background = Render::getInstance() -> createSprite("resources/MenuElements/BACKGROUND_menu2.png");
            

            fuente = new sf::Font();
            fuente->loadFromFile("resources/Minecrafter.Reg.ttf");

            texto_puntuacion1 = new sf::Text();
            texto_puntuacion1->setFont(*fuente);


            puntuacion_text2 = "SCORE " + std::to_string(Map::getInstance()->getScore());
            texto_puntuacion1->setString(puntuacion_text2);
            std::cout << texto_puntuacion1 << std::endl;
            texto_puntuacion1->setPosition((float)350, (float)350);
            
            //std::string level_text2 = "LEVEL " + std::to_string(Map::getInstance()->getLevel());
            //texto_level1->setString(level_text2);
                       

        }

        ~TransitionMenu(){}
};