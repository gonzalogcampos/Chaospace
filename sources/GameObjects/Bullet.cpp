#include <Bullet.h>
#include <Physics.h>
#include <Render.h>

Bullet::Bullet(float x, float y, float v, float dir, int type)
{   
    physics->setPosition(Pvect(x, y));
    physics->setPolarVelocity(dir, v);
    physics->setCircleBB(10.f);
    physics->setOrient(dir);
    animation = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png"));
}

Bullet::~Bullet()
{
    //Destructor
    Render::getInstance()->deleteAnimation(animation);
}