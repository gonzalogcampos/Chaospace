#pragma once
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "tinyxml2.h"


class Player;
class Ship;

class Map
{
    private:
        std::vector<Ship*> ships;
        Player* player;

        sf::Texture mapTexture;
        sf::Sprite* tileSprites;
        sf::Sprite**** mapSprite;
        int width, height;
    public:

        /*
        Game update. Devuelve false si el jugador ha muerto.
        */
        bool update(float dt);

        /*
        Borra toda la informacion del mapa
        */
        void clear();

        /*
        Inicia el mapa
        */
        void init();

        /*
        Devuelve una nave creada
        */
        Ship* createShip();


        /*
        Devuelve el player creado
        */
        Player* createPlayer();


        /*
        Carga un nivel
        */
        void loadLevel();

        /*
        Carga toda la información del mapa
        */
        void loadMapInfo();

        /*
        Dibujado del mapa
        */  
        void draw();

};