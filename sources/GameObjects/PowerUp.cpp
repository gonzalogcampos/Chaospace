#include <PowerUp.h>
#include <Physics.h>
#include <Render.h>


PowerUp::PowerUp(PowerUpType t, float x, float y) : GameObject()
{
    physics->setPosition(Pvect(x, y));
    physics->setCircleBB(5.f);

    this->t = t;

    animation = Render::getInstance()->createAnimation(10);

    switch (t)
    {
    case LIFE:
        /*
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/energy.png", Rrect(50*2, 0, 50, 50)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/energy.png", Rrect(50*3, 0, 50, 50)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/energy.png", Rrect(50*4, 0, 50, 50)));
        */
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health/health.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health/health3.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health/health2.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health/health3.png"));
        break;
    case VELDIS:
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/att-speed/att-speed.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/att-speed/att-speed3.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/att-speed/att-speed2.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/att-speed/att-speed3.png"));
        break;
    case MAX_LIFE:
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health/maxHealth.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health/maxHealth3.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health/maxHealth2.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/health/maxHealth3.png"));
        break;
    case SHIELD:
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/shield/shield1.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/shield/shield3.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/shield/shield2.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/shield/shield3.png"));
        break;
    case WEAPONCHAN:
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/bala_power/bala2.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/bala_power/bala2_3.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/bala_power/bala2_2.png"));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/bala_power/bala2_3.png"));

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