#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Bullet{
    private:
        
        sf::CircleShape hitbox;
        sf::Vector2f movimiento;

    public:
        Bullet(sf::Vector2f pos);
        virtual ~Bullet();

        void moverse();
        sf::Vector2f getPositionBala();



        void update();
        void draw(sf::RenderWindow& renderWindow);
};