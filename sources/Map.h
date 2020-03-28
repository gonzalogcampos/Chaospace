#pragma once
#include <vector>

class Player;
class Ship;

class Map
{
    private:
        std::vector<Ship*> ships;
        Player* player;

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


};