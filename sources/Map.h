#pragma once
#include <vector>
#include <string>

class Player;
class Ship;
class GameObject;
class Npc;

class Map
{
    private:
        //std::vector<Ship*> ships;
        Player* player;
        std::vector<Npc*> npcs;
        Map(){}
        float mapPosition;
        float mapIncPosition;

        int level = 0;
        float enemiesPerSecond = .001f;
        float incEnemiesPerSecond = .1f;
        unsigned int fondo;
        unsigned int paredes;
    public:

        static Map* getInstance()
        {
            static Map onlyInstance;
            return &onlyInstance;
        }
        bool update(float dt);

        void updateObjects(float dt);

        void updateColisions();

        void clear();

        void init();

        Npc* createNpc();

        Player* createPlayer(float x, float y);

        void loadLevel();

        void loadMapInfo(std::string mapaRuta);

        void draw();

        float getMapIncPosition();
        
        float moveMap(float dx);
        float getPlayerX();

        float getPlayerY();

        void tryCreate(float dt);

};
