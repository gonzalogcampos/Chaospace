#include "Map.h"
#include "Player.h"
#include "tinyxml2.h"
#include "Render.h"
#include <iostream>
#include <Ship.h>
#include <Npc.h>
#include <Physics.h>
#include <cstdlib>

/*
Game update. Devuelve false si el jugador ha muerto.
*/
bool Map::update(float dt)
{
    draw();
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
    loadMapInfo("mapa1"); 

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
void Map::loadMapInfo(std::string rutaMapa)
{
    
    tinyxml2::XMLDocument document;
    tinyxml2::XMLElement* xmlMap;
    tinyxml2::XMLElement* imageLayer;
    
    /*
    char* url;
    strcpy(url,"./resources/maps/");
    strcat(url, map);
    string ruta(url);
    ruta += "/";
    strcat(url,"/mapa.tmx");
    */

    document.LoadFile(rutaMapa.c_str());
    std::cout << "carga el mapa correctamente" << std::endl;
    //xmlMap = document.FirstChildElement("map");
    fondo = Render::getInstance()->createSprite("resources/maps/mapa1/fondo1.png");
    // fondo = Render::getInstance()->createAnimation(1.f);
    // paredes = Render::getInstance()->createSprite("/resources/maps/mapa1/seccion1.png", Rrect(0, 0, 1080, 720));
    /*
    imageLayer = xmlMap->FirstChildElement("imagelayer");
    while(imageLayer) {
        if(((std::string)imageLayer->Attribute("name")).compare("fondo") == 0) 
        {
            ruta = ruta + (string)imageLayer->FirstChildElement("image")->Attribute("source");
            fondo = Render::getInstance()->createSprite(ruta, Rrect(0, 0, 1080, 720));

        } 
        else if(((std::string)imageLayer->Attribute("name")).compare("paredes") == 0) 
        {
            ruta = ruta + (string)imageLayer->FirstChildElement("image")->Attribute("source");
            paredes = Render::getInstance()->createSprite(ruta, Rrect(0, 0, 1080, 720));

        }

        imageLayer = imageLayer->NextSiblingElement("imagelayer");
    }
    */
   

}

/*
Dibujado del mapa
*/  
void Map::draw()
{
    Render::getInstance()->drawSprite(fondo, Rvect(-mapPosition*0.1, 0), 0.f, 1.f, false);
    //Render::getInstance()->drawSprite(paredes, Rvect(0, 0), 0.f, 1.f, false);
}

float Map::getMapIncPosition()
{
    return mapIncPosition;
}
        
float Map::moveMap(float dx)
{
    mapPosition += dx;
    mapIncPosition = dx;
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