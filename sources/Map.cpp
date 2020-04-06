#include "Map.h"
#include "Player.h"
#include <Ship.h>
#include <Npc.h>
#include <Physics.h>
#include <cstdlib>

/*
Game update. Devuelve false si el jugador ha muerto.
*/
bool Map::update(float dt)
{
    tryCreate(dt);
    updateObjects(dt);
    updateColisions();
}

/*
Borra toda la informacion del mapa
*/
void Map::clear()
{ 
 
}
 
/*
Inicia el mapa
*/
void Map::init()
{
    loadLevel();

}

/*
Devuelve una nave creada
*/
Npc* Map::createNpc()
{
    Npc* npc = new Npc(4, 1200.f, 400.f);
    npcs.push_back(npc);
}

/* 
Devuelve el player creado
*/
Player* Map::createPlayer(float x, float y)
{
    Player* p = new Player(x, y);
    return p;
}
 

/*
Carga un nivel
*/
void Map::loadLevel()
{
    mapPosition = 0.f;
    level++;
    player = createPlayer(100.f, 360.f);
}

/*
Carga toda la información del mapa
*/
void Map::loadMapInfo()
{

}

/*
Dibujado del mapa
*/  
void Map::draw()
{

}

float Map::getMapPosition()
{
    return mapPosition;
}
        
float Map::setMapPosition(float dx)
{
    mapPosition = dx;
}
float Map::getPlayerX(){
    
    return player->getPhysics()->getPosition().x;

}

float Map::getPlayerY(){
    return player->getPhysics()->getPosition().y;
}

void Map::tryCreate(float dt)
{
   float tryPerSecond = 1 / dt;
   
   float prob = (enemiesPerSecond + level*incEnemiesPerSecond);
   int r = rand() % (int)tryPerSecond;
   if(r<prob)
   {
       createNpc();
   }
}

void Map::updateObjects(float dt)
{
    player->update (dt);

    for(size_t i = 0; i<npcs.size(); i++)
        npcs.at(i)->update(dt);
}

void Map::updateColisions()
{
    size_t s = player->getBullets()->size();
    for(auto it = player->getBullets()->begin(); it<player->getBullets()->end(); it++)
    {
        Physics* p = (*it)->getPhysics();
        bool colision = false;
        for(auto jt = npcs.begin(); jt<npcs.end() && !colision; jt++)
        {
            if(p->colides((*jt)->getPhysics()))
            {
                delete *jt;
                npcs.erase(jt);
                colision = true;
            }
        }
        if(colision)
        {
            delete *it;
            player->getBullets()->erase(it);
            it--;
            colision = false;
        }
    }
}