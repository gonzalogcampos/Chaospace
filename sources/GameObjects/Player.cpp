#include <Player.h>
#include <Physics.h>
#include <Render.h>
#include <Map.h>

float _Player_vx = 200.f;
float _Player_vy = 400.f;
float _Player_Acel = 20.f;
float _Player_Dcel = 20.f;
float _Player_VToStop = 5.f;
float _Player_MAXRight = 200.f;
float _Player_VToCenter = .01f;
float _Player_BBX = 123.f;
float _Player_BBY = 115.f;
float _Player_InitHP = 10.f;


//Constructor por defecto de la clase Player.
Player::Player(float x, float y)
{
    wpn = 1;
    hp = _Player_InitHP;
    powerUp = 0;
    physics->setPosition(Pvect(x, y));
    physics->setRectangleBB(Pvect(_Player_BBX, _Player_BBY));

    animation = Render::getInstance()->createAnimation(15);
    Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/naveE.png"));
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
    if(vx<(-_Player_vx))
        vx = -_Player_vx;
    else if(vx>_Player_vx)
        vx = _Player_vx;
    
    if(vy<(-_Player_vy))
        vy = -_Player_vy;
    else if(vy>_Player_vy)
        vy = _Player_vy;


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
    
    if(physics->getPosition().y>720)
        physics->setPosition(Pvect(physics->getPosition().x, 720.f));



    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) //AUN TENGO QUE CAMBIAR LO DE SPR_PERSONAJE1
        shoot();
    
    Ship::update(dt);

}    
