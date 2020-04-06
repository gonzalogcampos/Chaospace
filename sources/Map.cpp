#include <Map.h>
#include <Player.h>
#include <Ship.h>
#include <Npc.h>
#include <Physics.h>
#include <cstdlib>
#include <Game.h>
#include <iostream>


/*
Game update. Devuelve false si el jugador ha muerto.
*/
bool Map::update(float dt)
{
    if(player==nullptr)
    {
        //Hemos muerto
        return false;
    }
    tryCreate(dt);
    updateObjects(dt);
    updateColisions();
    return true;
}

/*
Borra toda la informacion del mapa
*/
void Map::clear()
{ 
    for(auto it = npcs.begin(); it<npcs.end(); it++)
    {
        delete *it;
    }
    npcs.clear();

    if(player)
    {
        delete player;
        player = nullptr;
    }
    level = -1;
    mapPosition = 0.f;
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
{   int tipo = rand() % 7;
    Npc* npc = new Npc(tipo+1, 1200.f, 400.f);
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


    for(auto it = npcs.begin(); it<npcs.end(); it++)
    {
        bool colision = false;
        for(auto jt = (*it)->getBullets()->begin(); jt<(*it)->getBullets()->end() && !colision; jt++)
        {
            if(player->getPhysics()->colides((*jt)->getPhysics()))
            {
                colision = true;
                delete *jt;
                (*it)->getBullets()->erase(jt);
                jt--;

                if(player->hpDown())
                {
                    delete player;
                    player = nullptr;

                    return;
                }
            }
        }
    }
}