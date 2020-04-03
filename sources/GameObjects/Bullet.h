#pragma once

//#include <iostream>
//#include <SFML/Graphics.hpp>
#include <GameObject.h>

class Bullet: public GameObject{
    private:
        //sf::CircleShape hitbox;
        //sf::Vector2f movement;

    public:
        Bullet(); //Metodo constructor por defecto de la clase Bullet.

        //Bullet(sf::Vector2f pos); //Metodo constructor mediante paso por parametro de la posicion.

        virtual ~Bullet(); //Metodo destructor de la clase Bullet.

        void moveM(); //Metodo que permite el movimiento de la bala.

        //sf::Vector2f getPositionBullet(); //Metodo auxiliar que nos permite recuperar la posicion del Bullet.

        void update(); //Metodo update, para sobreescribir el de la clase padre.

        //void draw(sf::RenderWindow& renderWindow);
};