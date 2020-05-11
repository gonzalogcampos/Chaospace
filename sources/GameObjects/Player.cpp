//Main header
#include <Player.h>

//Headers
#include <Physics.h>
#include <Render.h>
#include <Map.h>


/*=================================================*/
/*==================   Values   ===================*/
/*=================================================*/


float _Player_vx = 200.f;
float _Player_vy = 400.f;

float _Player_SpeedUpX = 300.f;
float _Player_SpeedUpY = 300.f; 

float _Player_Acel = 30.f;
float _Player_Dcel = 30.f;
float _Player_VToStop = 5.f;
float _Player_MAXRight = 200.f;
float _Player_VToCenter = .02f;
float _Player_BBX = 70.f;
float _Player_BBY = 75.f;
float _Player_InitHP = 100.f;


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


//Constructor por defecto de la clase Player.
Player::Player(float x, float y)
{
    hp = _Player_InitHP;
    powerUp = 0;
    physics->setPosition(Pvect(x, y));
    physics->setRectangleBB(Pvect(_Player_BBX, _Player_BBY));

    setWeaponType(6);

    animation = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/player.png"));

    escudo = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(escudo, Render::getInstance()->createSprite("resources/energy.png",Rrect(100,0,50,50)));
    Render::getInstance()->addFrameToAnimation(escudo, Render::getInstance()->createSprite("resources/energy.png",Rrect(150,0,50,50)));
    Render::getInstance()->addFrameToAnimation(escudo, Render::getInstance()->createSprite("resources/energy.png",Rrect(200,0,50,50)));

    velocity = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(velocity, Render::getInstance()->createSprite("resources/fuego.png",Rrect(0,0,12,21)));
    Render::getInstance()->addFrameToAnimation(velocity, Render::getInstance()->createSprite("resources/fuego.png",Rrect(123,0,20,21)));
    Render::getInstance()->addFrameToAnimation(velocity, Render::getInstance()->createSprite("resources/fuego.png",Rrect(250,0,21,21)));
    Render::getInstance()->addFrameToAnimation(velocity, Render::getInstance()->createSprite("resources/fuego.png",Rrect(376,0,36,21)));
}

//Metodo destructor de la clase Player.
Player::~Player()
{ 

}

 //Metodo para recuperar el powerUp pasivo actual del Player.
int Player::getPUp()
{
    return powerUp;
} 

//Metodo para cambiar el powerUp pasivo actual del Player.
void Player::setPUp(int i)
{ 
        powerUp = i;
}

void Player::hpUp(int hp)
{
    this->hp += hp;
    if(this->hp >_Player_InitHP)
        this->hp = _Player_InitHP;
}
/*
Le coloca un escudo de 3 golpes al player
*/
void Player::setShield()
{
    shield = 3;
}

bool Player::hpDown(int hp)
{
    if(shield > 0)
    {
        shield--;
    }
    else
    {
        this->hp -= hp;
        if(this->hp<=0)
            return true;
    }
    
    return false;
}

void Player::setHp(int nu)
{
    hp=nu;
}

void Player::speedUp()
{
    vtime = 5.f;
}

void Player::cambioArma()
{
    float r = 1 + random()%7;

    setWeaponType(r);

}


void Player::move()
{
    float ax = 0.f;
    float ay = 0.f;
    float vx = physics->getVelocity().x;
    float vy = physics->getVelocity().y;

    /*
    PROTOCOLO DE ACELERACION
    */
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        ay -=  _Player_Acel;        
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        ay += _Player_Acel;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)  || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        ax += _Player_Acel;
   
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        ax -= _Player_Acel;



    /*
    PROTOCOLO DE DECELERACION
    */
    if(ax == 0.f)
    {
        if(vx<_Player_VToStop)
            ax = _Player_Dcel;
        else if(vx>_Player_VToStop)
            ax = -_Player_Dcel;
        else
            vx = 0.f;
    }
    if(ay == 0.f)
    {
        if(vy<_Player_VToStop)
            ay = _Player_Dcel;
        else if(vy>_Player_VToStop)
            ay = -_Player_Dcel;
        else
            vy = 0.f;
    }

    /*
    CALCULO DE LA VELOCIDAD
    */
    vx += ax;
    vy += ay;

    float dvx = _Player_vx;
    float dvy = _Player_vy;

    if(vtime>0.f)
    { 
        dvx += _Player_SpeedUpX;
        dvy += _Player_SpeedUpY;
        show_velocity=true;
    }else
    {
        show_velocity=false;
    }

    if(vx<(-dvx))
        vx = -dvx;
    else if(vx>dvx)
        vx = dvx;
    
    if(vy<(-dvy))
        vy = -dvy;
    else if(vy>dvy)
        vy = dvy;


    /*
    SET DE LA VELOCIDAD
    */
    physics->setVelocity(Pvect(vx, vy));


    /*
    CALCULO DE LA ORIENTACION
    */
    float dx = Render::getInstance()->getCursorPosition().x - physics->getPosition().x;
    float dy = Render::getInstance()->getCursorPosition().y - physics->getPosition().y;

    float theta;
    if(dx == 0.f && dy == 0.f)
    {
        theta = 0.f;
    }else if(dx == 0.f)
    {
        if(dy < 0)
        {
            theta = 270.f;
        }else
        {
            theta = 90.f;
        }
    }else if(dy == 0.f)
    {
        if(dx < 0)
        {
            theta = 180.f;
        }else
        {
            theta = 0.f;
        }
    }else
    {
        float toDegrees = 180/3.1415926;
        theta = atan(dy/dx)*toDegrees;
        if(dx<0)
            theta+=180;
    }
    physics->setOrient(theta);



}

//Override del metodo de colisiones
void Player::update(float dt)
{
    move();

    if(vtime>0.f)
        vtime -= dt;

    if(physics->getPosition().x>_Player_MAXRight)
    { 
        Map::getInstance()->moveMap((physics->getPosition().x - _Player_MAXRight ) *_Player_VToCenter);
    }else{
        Map::getInstance()->moveMap(0.f);
    }
    
    if(physics->getPosition().x<0.f)
        physics->setPosition(Pvect(0.f, physics->getPosition().y));

    if(physics->getPosition().y<0.f)
        physics->setPosition(Pvect(physics->getPosition().x, 0.f));
    
    if(physics->getPosition().y>720.f)
        physics->setPosition(Pvect(physics->getPosition().x, 720.f));



    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        shoot();
    
    Ship::update(dt);

}    
 

void Player::shoot(bool p)
{
    Ship::shoot(p);
}

void Player::draw()
{
    Ship::draw();
    Rvect de = Render::getInstance()->polarToCartesian(50.f,  physics->getOrient());
    if(shield>0)
    {
        Render::getInstance()->drawAnimation(escudo,Rvect(physics->getPosition().x,physics->getPosition().y),physics->getOrient(),2.5);

    }

    if(show_velocity==true)
    {
        Render::getInstance()->drawAnimation(velocity, Rvect(physics->getPosition().x-de.x, physics->getPosition().y-de.y), physics->getOrient());

    }
}
