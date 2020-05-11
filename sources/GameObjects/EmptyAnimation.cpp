#include <EmptyAnimation.h>
#include <Render.h>
#include <Physics.h>

EmptyAnimation::EmptyAnimation(float x, float y, float orient, Type type)
{
    physics->setPosition(Pvect(x, y));
    physics->setOrient(orient);
    physics->setVelocity(Pvect(0, 0));
    physics->setNoBB();

    switch (type)
    {
    case EXPLOSION:
        time = .3f;
        animation = Render::getInstance()->createAnimation(10);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(0*180, 0*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(1*180, 1*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(2*180, 2*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(3*180, 3*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(4*180, 4*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(5*180, 5*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(6*180, 6*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(7*180, 7*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(8*180, 8*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(9*180, 9*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(10*180, 10*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(11*180, 11*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(12*180, 12*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(13*180, 13*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(14*180, 14*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(15*180, 15*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(16*180, 16*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(17*180, 17*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(18*180, 18*180, 180, 180)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Animacion explosion/Explosion2.png", Rrect(19*180, 19*180, 180, 180)));
        break;
    
    default:

        break;
    }
}

EmptyAnimation::~EmptyAnimation()
{
}

void EmptyAnimation::update(float dt)
{
    time-=dt;
    if(time<0.f)
        kill = true;
    
    GameObject::update(dt);
}

bool EmptyAnimation::getKill()
{
    return kill;
}

void EmptyAnimation::draw()
{
    Render::getInstance()->drawAnimation(animation, Rvect(physics->getPosition().x, physics->getPosition().y),physics->getOrient(), .5f);  
}