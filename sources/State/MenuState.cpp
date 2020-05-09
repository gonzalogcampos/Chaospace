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

    if(Render::getInstance()->isEnterPressed()==true){
        switch (menu->click()){
            case 1: 
                /*PLAY*/
                delete menu; 
                Render::getInstance() -> setEnterPressed(false);
                Game::getInstance()->setState(State::stateType::PLAY);
                break;

            case 2: 
                /*EXIT*/
                delete menu; 
                Render::getInstance() -> setEnterPressed(false);
                Render::getInstance()->close();
                break;

            case 3: 
                /*EXIT*/
                delete menu; 
                Render::getInstance() -> setEnterPressed(false);
                Game::getInstance()->setState(State::stateType::CONTROLES);
                break;    
            
            default: break;
        }

    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        Render::getInstance()->close();
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        menu->up();   
    }
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        menu->down();   
    }
    
}


void MenuState::draw()
{
    menu->draw();
}

void MenuState::clear()
{

}