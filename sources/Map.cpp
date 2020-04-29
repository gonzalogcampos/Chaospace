//Main header
#include <Map.h>

//Headers
#include <Render.h>
#include <Player.h>
#include <Ship.h>
#include <Npc.h>
#include <Physics.h>
#include <Game.h>
#include <Bullet.h>

//External headers
#include <tinyxml2.h>
#include <cstdlib>


/*=================================================*/
/*==================   Values   ===================*/
/*=================================================*/


const float _Player_InitX = 100.f;
const float _Player_InitY = 285.f;

//Level Values

const float baseDistance = 1000.f;
const float incDisctance = 200.f;

const float bossMaxDist = 50.f;

const float baseEnemy = 50.f;
const float incEnemy = 10.f;

const unsigned int enemyScore = 100;
const unsigned int bossScore = 1000;
const float incScore = .2;



/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


/*
Game update. Devuelve false si el jugador ha muerto.
*/
bool Map::update(float dt)
{
    if(player==nullptr)
    {
        clear();
        level = -1;
        Game::getInstance()->setState(State::MENUFINAL);
        return false;
    }
    
    if(mapPosition>baseDistance + (level * incDisctance))
    {
        clear();
        Game::getInstance()->setState(State::NEXTLEVEL);
        return false;
    }
    else if(mapPosition> mapPosition>baseDistance+(level * incDisctance) - bossMaxDist && !boss)
    {
        createBoss();
    }

    draw();

    if(!boss)
        tryCreate();

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
    loadMapInfo("mapa1"); 

}

/*
Devuelve una nave creada
*/
void Map::createNpc()
{   int tipo = rand() % 7;
    Npc* npc = new Npc(tipo+1, 1200.f, rand()%570);
    npcs.push_back(npc);
}

void Map::createBoss()
{
    
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
Carga toda la información del mapa
*/
void Map::loadMapInfo(std::string rutaMapa)
{
    
    tinyxml2::XMLDocument document;
    //tinyxml2::XMLElement* xmlMap;
    //tinyxml2::XMLElement* imageLayer;
    
    /*
    char* url;
    strcpy(url,"./resources/maps/");
    strcat(url, map);
    string ruta(url);
    ruta += "/";
    strcat(url,"/mapa.tmx");
    */

    document.LoadFile(rutaMapa.c_str());
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
        
void Map::moveMap(float dx)
{
    if(!boss)
    {
        mapPosition += dx;
        mapIncPosition = dx;
    }
}

float Map::getPlayerX(){
    
    return player->getPhysics()->getPosition().x;

}

float Map::getPlayerY(){
    return player->getPhysics()->getPosition().y;
}

void Map::tryCreate()
{
   
   float prob = (baseEnemy + level*incEnemy);
   int r = rand()%10000;
   if(r<prob)
   {
       createNpc();
   }
}

void Map::updateObjects(float dt)
{
    player->update (dt);

    //if(boss)boss->update(dt);

    //Borrado de npc fuera del mapa
    for(auto it = npcs.begin(); it<npcs.end(); it++)
    {   
        if((*it)->getPhysics()->getPosition().x<200.f)
        {
            delete *it;
            npcs.erase(it);
            it--;
        }else{
            (*it)->update(dt);
        }
    }
}

void Map::updateColisions()
{
    for(auto it = player->getBullets()->begin(); it<player->getBullets()->end(); it++)
    {
        Physics* p = (*it)->getPhysics();
        bool colision = false;

        /*
        if(boss && p->colides(boss->getPhysics()));
        {
            if(boss->hit())
            {
                delete boss;
                boss = nullptr;
                score += bossScore * (1 + (level*incScore));
            } 
            colision = true;
        }
        */

        for(auto jt = npcs.begin(); jt<npcs.end() && !colision; jt++)
        {
            if(p->colides((*jt)->getPhysics()))
            {
                delete *jt;
                npcs.erase(jt);
                colision = true;
                score += enemyScore * (1 + (level*incScore));
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

    //De momento no compruebo la colision con las balas del boss porque al final estaran todas juntas
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


/*
Carga un nivel
*/
void Map::loadLevel()
{
    clear();
    mapPosition = 0.f;
    level++;
    if(level == 0)
        score = 0;
    player = createPlayer(_Player_InitX, _Player_InitY);

}