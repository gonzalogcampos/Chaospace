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
        std::vector<Npc*> npcs;
        Map(){}
        float mapPosition;



        int level = 0;
        float enemiesPerSecond = .001f;
        float incEnemiesPerSecond = .1f;
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

        void loadMapInfo();

        void draw();

        float getMapPosition();
        
        float setMapPosition(float dx);
        float getPlayerX();

        float getPlayerY();

        void tryCreate(float dt);

};