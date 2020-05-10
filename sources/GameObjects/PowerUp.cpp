#include <PowerUp.h>
#include <Physics.h>
#include <Render.h>


PowerUp::PowerUp(PowerUpType t, float x, float y) : GameObject()
{
    physics->setPosition(Pvect(x, y));
    physics->setCircleBB(5.f);

    this->t = t;

    animation = Render::getInstance()->createAnimation(5);

    switch (t)
    {
    case LIFE:
        /*
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/energy.png", Rrect(50*2, 0, 50, 50)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/energy.png", Rrect(50*3, 0, 50, 50)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/energy.png", Rrect(50*4, 0, 50, 50)));
        */
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health2.png"));
        break;
    case VELDIS:
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/att-speed.png"));
        break;
    

    default:
        break;
    }

}

PowerUp::~PowerUp()
{
    
}

PowerUpType PowerUp::getType()
{
    return t;
}