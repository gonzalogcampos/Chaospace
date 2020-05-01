#pragma once

//External headers
#include <vector>
#include <string>

//Forward declarations
class Player;
class Ship;
class GameObject;
class Bullet;
class Npc;
class PowerUp;
class Hud;

class Map
{
    private:
        Hud* hud;

        Player* player;
        
        void* boss;

        std::vector<Npc*> npcs;
        std::vector<Bullet*> bullets;
        std::vector<PowerUp*> powerUps;

        Map();
        float mapPosition;
        float mapIncPosition;
        unsigned int score = 0;
        unsigned int kills = 0;
        int playerHp = 100;

        int level = -1;
        unsigned int fondo;
        unsigned int paredes;
    public:

        ~Map();
        
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

        void createBullet(float x, float y, float orient, int type, bool fromPlayer);
        
        Player* createPlayer(float x, float y);

        void createLife(float x, float y);

        void loadLevel();

        void loadMapInfo(int lvl);

        void draw();

        void drawObjects();

        float getMapIncPosition();
        
        void moveMap(float dx);

        float getPlayerX();

        float getPlayerY();

        void tryCreate();

};
