#include "Bullet.h"


Bullet::Bullet(sf::Vector2f pos)
{   
    movimiento = sf::Vector2f(0.f, 0.f);

    hitbox = sf::CircleShape(10.0);
    hitbox.setFillColor(sf::Color::Green);
    hitbox.setOrigin(10.f/2,10.f/2);
    hitbox.setPosition(pos);

}

Bullet::~Bullet()
{
    //Destructor
}


void Bullet::update()
{
    // Mover la bala a la izquierda
    moverse();

}

void Bullet::moverse() 
{
    movimiento.x -= 3;
    hitbox.move(movimiento);
}


sf::Vector2f Bullet::getPositionBala() 
{
    return hitbox.getPosition();
}

void Bullet::draw(sf::RenderWindow& renderWindow)
{
    renderWindow.draw(hitbox);
}