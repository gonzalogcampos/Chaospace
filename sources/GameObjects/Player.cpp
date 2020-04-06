#include <Player.h>
#include <Physics.h>
#include <Render.h>
#include <Map.h>


//Constructor por defecto de la clase Player.
Player::Player(float x, float y)
{
    wpn = 1;
    hp = 3;
    powerUp = 0;
    physics->setPosition(Pvect(x, y));
    physics->setRectangleBB(Pvect(10.f,10.f));

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
    float vx = 0.f;
    float vy = 0.f;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        vy = -200.f;        
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        vy = 200.f;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)  || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        vx = 200.f;
   
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        vx = -200.f;
    
    physics->setVelocity(Pvect(vx, vy));

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

    if(physics->getPosition().x>400.f)
    { 
        Map::getInstance()->setMapPosition(physics->getPosition().x - 400.f);
    }else{
        Map::getInstance()->setMapPosition(0.f);
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
