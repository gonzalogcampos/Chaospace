#pragma once

//Headers
#include <Menu.h>
#include <Map.h>


class FinalMenu : public Menu
{
    private:
        unsigned int titulo;
        unsigned int over;
        sf::Text *final_texto_puntuacion1;
        sf::Text *final_texto_level1;
        sf::Font *final_fuente;
        sf::Font *final_fuente2;
        std::string final_puntuacion_text;
        std::string final_nivel_text;
    
    public:
        FinalMenu() : Menu()
        {
            //Buttons
            Button* button = new Button(1, (char*)"resources/MenuElements/MAINMENU2.png", 
                                                (char*)"resources/MenuElements/MAINMENU1.png", 540, 500);
            buttons.push_back(button);            
            button = new Button(2, (char*)"resources/MenuElements/EXIT2.png",
                                                (char*)"resources/MenuElements/EXIT1.png", 540,620);
            buttons.push_back(button);
            
            buttons.at(focus)->focus();
        
            titulo = Render::getInstance() -> createSprite("resources/Titulo.png");
            background = Render::getInstance() -> createSprite("resources/MenuElements/BACKGROUND_menu.png");
            over = Render::getInstance() -> createSprite("resources/MenuElements/Game_Over.png");

            final_fuente = new sf::Font();
            final_fuente->loadFromFile("resources/Long_Shot.ttf");

            final_fuente2 = new sf::Font();
            final_fuente2->loadFromFile("resources/Minecrafter.Reg.ttf");

            final_texto_puntuacion1 = new sf::Text();
            final_texto_puntuacion1->setFont(*final_fuente2);


            final_puntuacion_text = "YOUR SCORE WAS " + std::to_string(Map::getInstance()->getScore());
            final_texto_puntuacion1->setString(final_puntuacion_text);
            final_texto_puntuacion1->setPosition((float)250, (float)350);
            final_texto_puntuacion1->setCharacterSize(50);
            //texto_puntuacion1->setColor(sf::Color::Black);
          

        }

        ~FinalMenu(){}
        
        void draw(){
            Menu::draw();
            Render::getInstance()->drawSprite(titulo, Rvect(900,650), 0.f, 0.6, true);
            Render::getInstance()->drawSprite(over, Rvect(550,150), 0.f, 0.8, true);
            Render::getInstance()->drawText(*final_texto_puntuacion1);
            //Render::getInstance()->drawText(*final_texto_level1);
        }

        void clear(){
            Menu::clear();
            Render::getInstance()->deleteSprite(titulo);
        }
};