//Main header
#include <Bullet.h>

//Headers
#include <Physics.h>
#include <Render.h>

#include <weapons.h>

/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


Bullet::Bullet(float x, float y, float dir, int type, bool fromPlayer)
{   
    physics->setPosition(Pvect(x, y));
    physics->setCircleBB(10.f);
    physics->setOrient(dir);
    animation = Render::getInstance()->createAnimation(4);
    this->fromPlayer = fromPlayer;
    switch (type)
    {
    case 1:
        force = w1_Fuerza;
        physics->setPolarVelocity(dir, w1_Velocidad);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(45, 8 + 26*0, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(45, 8 + 26*1, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(45, 8 + 26*2, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(45, 8 + 26*3, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(45, 8 + 26*4, 75, 26)));
        break;
    case 2:
        force = w2_Fuerza;
        physics->setPolarVelocity(dir, w2_Velocidad);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(151, 8 + 26*0, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(151, 8 + 26*1, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(151, 8 + 26*2, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(151, 8 + 26*3, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(151, 8 + 26*4, 75, 26)));
        break;
    case 3:
        force = w3_Fuerza;
        physics->setPolarVelocity(dir, w3_Velocidad);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(257, 8 + 26*0, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(257, 8 + 26*1, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(257, 8 + 26*2, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(257, 8 + 26*3, 75, 26)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(257, 8 + 26*4, 75, 26)));
        break;
    case 4:
        force = w4_Fuerza;
        physics->setPolarVelocity(dir, w4_Velocidad);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(60, 177 + 13*0, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(60, 177 + 13*1, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(60, 177 + 13*2, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(60, 177 + 13*3, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(60, 177 + 13*4, 48, 10)));
        break;
    case 5:
        force = w5_Fuerza;
        physics->setPolarVelocity(dir, w5_Velocidad);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(165, 177 + 13*0, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(165, 177 + 13*1, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(165, 177 + 13*2, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(165, 177 + 13*3, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(165, 177 + 13*4, 48, 10)));
        break;
    case 6:
        force = w6_Fuerza;
        physics->setPolarVelocity(dir, w6_Velocidad);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(171, 177 + 13*0, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(171, 177 + 13*1, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(171, 177 + 13*2, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(171, 177 + 13*3, 48, 10)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(171, 177 + 13*4, 48, 10)));
        break;
    case 7:
        force = w7_Fuerza;
        physics->setPolarVelocity(dir, w7_Velocidad);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(380, 52*0, 120, 52)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(380, 52*1, 120, 52)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(380, 52*2, 120, 52)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(380, 52*3, 120, 52)));
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/laser.png", Rrect(380, 52*4, 120, 52)));
        break;
    default:
        force = 5;
        physics->setPolarVelocity(dir, 200);
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