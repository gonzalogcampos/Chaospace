#pragma once

//External headers
#include <vector>
#include <string>

//Forward declarations
class Player;
class Ship;
class GameObject;
class Npc;


class Map
{
    private:
        //std::vector<Ship*> ships;
        Player* player;
        
        void* boss;
        
        std::vector<Npc*> npcs;
        Map(){}
        float mapPosition;
        float mapIncPosition;
        unsigned int score = 0;

        int level = -1;
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

        void createNpc();

        void createBoss();
        
        Player* createPlayer(float x, float y);

        void loadLevel();

        void loadMapInfo(std::string mapaRuta);

        void draw();

        float getMapIncPosition();
        
        void moveMap(float dx);

        float getPlayerX();

        float getPlayerY();

        void tryCreate();

};
