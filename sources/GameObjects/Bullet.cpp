//Main header
#include <Bullet.h>

//Headers
#include <Physics.h>
#include <Render.h>


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


Bullet::Bullet(float x, float y, float v, float dir, int type, bool fromPlayer)
{   
    physics->setPosition(Pvect(x, y));
    physics->setPolarVelocity(dir, v);
    physics->setCircleBB(10.f);
    physics->setOrient(dir);
    animation = Render::getInstance()->createAnimation(15);
    this->fromPlayer = fromPlayer;

    switch (type)
    {
    case 1:
        force = 1;
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png"));
        break;
    case 2:
        force = 10;
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png"));
        break;
    
    
    default:
        force = 1;
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png"));
        break;
    }
}

Bullet::~Bullet()
{
    //Destructor
    Render::getInstance()->deleteAnimation(animation);
}

bool Bullet::isFromPlayer()
{
    return fromPlayer;
}

int Bullet::getForce()
{
    return force;
}