//Main header
#include <MenuState.h>

//Headers
#include <Game.h>
#include <Menu.h>
#include <Render.h>
#include <MainMenu.h>


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


void MenuState::initState(){
    
    type = State::MENUINICIAL;

     menu = new MainMenu();
} 


void MenuState::update(float dt){


    menu->update(dt);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
        switch (menu->click()){
            case 1: 
                /*PLAY*/
                delete menu; 
                Game::getInstance()->setState(State::stateType::PLAY);
                break;

            case 2: 
                /*EXIT*/
                delete menu; 
                Render::getInstance()->close();
                break;
            
            default: break;
        }

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        Render::getInstance()->close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        menu->down();   
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        menu->up();   
    }
    
}

void MenuState::clear(){}