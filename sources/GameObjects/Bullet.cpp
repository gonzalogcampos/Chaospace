#include "Bullet.h"

Bullet::Bullet(){ //Metodo constructor por defecto de la clase Bullet.

} 

Bullet::Bullet(sf::Vector2f pos){ //Metodo constructor mediante paso por parametro de la posicion.
    
    movement = sf::Vector2f(0.f, 0.f); //Simplemente se inicializan los valores del Bullet a los predterminados.
    hitbox = sf::CircleShape(10.0);
    hitbox.setFillColor(sf::Color::Green);
    hitbox.setOrigin(10.f/2,10.f/2); //Quiza hay que cambiar esto posteriormente?
    hitbox.setPosition(pos);    
} 

Bullet::~Bullet(){ //Metodo destructor de la clase Bullet.

} 

void Bullet::moveM(){ //Metodo que permite el movimiento de la bala.
    movement.x += 3;
    hitbox.move(movement);
} 

sf::Vector2f Bullet::getPositionBullet(){ //Metodo auxiliar que nos permite recuperar la posicion del Bullet.
    return hitbox.getPosition();
} 

void Bullet::update(){ //Metodo update, para sobreescribir el de la clase padre.
    //En proceso
} 

//void Bullet::draw(sf::RenderWindow& renderWindow);