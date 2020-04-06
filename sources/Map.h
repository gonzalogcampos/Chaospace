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


        bool update(float dt);

        void clear();

        void init();

        Ship* createShip();

        Player* createPlayer(float x, float y);

        void loadLevel();

        void loadMapInfo();

        void draw();

};