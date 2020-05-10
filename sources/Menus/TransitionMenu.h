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
        
            //titulo = Render::getInstance() -> createSprite("resources/Titulo.png");
            background = Render::getInstance() -> createSprite("resources/MenuElements/BACKGROUND_menu2.png");
            

            fuente = new sf::Font();
            fuente->loadFromFile("resources/Long_Shot.ttf");

            fuente2 = new sf::Font();
            fuente2->loadFromFile("resources/Minecrafter.Reg.ttf");

            texto_puntuacion1 = new sf::Text();
            texto_puntuacion1->setFont(*fuente2);


            puntuacion_text2 = "SCORE " + std::to_string(Map::getInstance()->getScore());
            texto_puntuacion1->setString(puntuacion_text2);
            texto_puntuacion1->setPosition((float)320, (float)330);
            texto_puntuacion1->setCharacterSize(70);
            //texto_puntuacion1->setColor(sf::Color::Black);

            texto_level1 = new sf::Text();
            texto_level1->setFont(*fuente);

            nivel_text2 = "LEVEL " + std::to_string(Map::getInstance()->getLevel()+1)+ " COMPLETED";
            texto_level1->setString(nivel_text2);
            texto_level1->setPosition((float)220, (float)100);
            texto_level1->setCharacterSize(110);
                       

        }

        ~TransitionMenu(){}
};