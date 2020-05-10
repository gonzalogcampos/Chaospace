//Main header
#include <PlayState.h>

//Headers
#include <Render.h>
#include <Map.h>
#include <Game.h>
#include <Hud.h>


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


void PlayState::initState()
{
    type = State::PLAY;                       
    //if(!loaded)
    //{
    //    loaded = true;
        sprite_pausa = Render::getInstance() -> createSprite("resources/MenuElements/MENU_PAUSA.png");
        punto_mira = Render::getInstance() -> createSprite("resources/mira.png");
        
        Map::getInstance()->init();
    //}else
    //{

    //}
} 


void PlayState::update(float dt)
{
    if(Render::getInstance()->isEscapePressed())
    {
        Render::getInstance()->setEscapePressed(false);
        paused = !paused;
    }
    if(!paused)
    {
        if(!Map::getInstance()->update(dt))
        {
            loaded = false;
        }
    }
}

void PlayState::draw()
{
    Map::getInstance()->draw();
    if(paused)
    {   
        Render::getInstance()->drawSprite(sprite_pausa, Rvect(540.f, 360.f), 0.f, 1.f, true);
    }
    Render::getInstance()->drawSprite(punto_mira, Rvect(Render::getInstance()->getCursorPosition().x,Render::getInstance()->getCursorPosition().y), 0.f, 0.2f, true);
}

void PlayState::clear()
{

    loaded=false;
}