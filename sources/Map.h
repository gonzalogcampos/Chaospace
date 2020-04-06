#pragma once
#include <vector>


class Player;
class Ship;
class GameObject;
class Npc;

class Map
{
    private:
        //std::vector<Ship*> ships;
        Player* player;
        Npc* npc;
        Map(){}
    public:

        static Map* getInstance()
        {
            static Map onlyInstance;
            return &onlyInstance;
        }
        bool update(float dt);

        void clear();

        void init();

        Ship* createShip();

        Player* createPlayer(float x, float y);

        void loadLevel();

        void loadMapInfo();

        void draw();

        float getPlayerX();

        float getPlayerY();

};