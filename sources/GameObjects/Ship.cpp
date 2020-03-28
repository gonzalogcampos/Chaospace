#include <Ship.h>

Ship::Ship(sf::Texture t){ //Para crear el Ship sera necesario pasar una textura y que pueda asi tener un Sprite.
    textura = t;
    sprite.setTexture(t); //Colocamos el Sprite segun la textura que se haya pasado.
    wpn = 1; //Ponemos el arma al 1, que sera el disparo sencillo estandar.
} 

Ship::~Ship(){ //Metodo destructor de un Ship.

} 

void Ship::move(){ //Metodo que permite el movimiento de un Ship.

} 

void Ship::shoot(){ //Metodo que controla y permite el disparo efectuado por un Ship.

} 

sf::Sprite Ship::getSprite(){ //Metodo que permite recoger el Sprite de un Ship.
    return sprite;
} 