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
#include <Asteroid.h>
#include <PowerUp.h>
#include <EmptyAnimation.h>
#include <Hud.h>

//External headers
#include <tinyxml2.h>
#include <cstdlib>
#include <iostream>

/*=================================================*/
/*==================   Values   ===================*/
/*=================================================*/


const float _Player_InitX = 100.f;
const float _Player_InitY = 360.f;

//Level Values

const float baseDistance = 200.f;
const float incDisctance = 100.f;

const float bossMaxDist = 400.f;

const float baseEnemy = 50.f;
const float baseAsteroid = 50.f;

const float incEnemy = 10.f;
const float incAsteroid = 0.f;

const unsigned int enemyScore = 100;
const unsigned int bossScore = 1000;
const float incScore = .2;



/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/

Map::Map()
{
    hud = new Hud();
}

Map::~Map()
{
    delete hud;
}

/*
Game update. Devuelve false si el jugador ha muerto.
*/
bool Map::update(float dt)
{
    if(player==nullptr)
    {
        clear();
        _score = score;
        _level = level;
        level = -1;
        kills = 0;
        playerHp = 100;
        Game::getInstance()->setState(State::MENUFINAL);
        return false;
    }
    
    if(mapPosition>baseDistance+(level * incDisctance) && !boss)
    {
        createBoss();
    }

    if(!boss)
        tryCreate();

    updateObjects(dt);
    updateColisions();

    float hp = 0.f;
    if(player)
        hp = player->getHp();

    hud->update(score, level+1, kills, hp, mapPosition, baseDistance+(level * incDisctance), 1.f/dt, 1);

    return true;
}

/*
Borra toda la informacion del mapa
*/
void Map::clear()
{ 
    Render::getInstance()->deleteSprite(fondo);
    Render::getInstance()->deleteSprite(paredes);
    for(auto it = npcs.begin(); it<npcs.end(); it++)
    {
        delete *it;
    }
    npcs.clear();

    for(auto it = bullets.begin(); it<bullets.end(); it++)
    {
        delete *it;
    }
    bullets.clear();
        
    for(auto it = powerUps.begin(); it<powerUps.end(); it++)
    {
        delete *it;
    }
    powerUps.clear();

    for(auto it = asteroids.begin(); it<asteroids.end(); it++)
    {
        delete *it;
    }
    asteroids.clear();

    if(player)
    {
        delete player;
        player = nullptr;
    }

    if(boss)
    {
        delete boss;
        boss = nullptr;
    }

    mapPosition = 0.f;
}
 
/*
Inicia el mapa
*/
void Map::init()
{
    int estilo_mapa = rand() % 2 + 1;
    loadLevel(estilo_mapa);
}

/*
Crea una nave
*/
void Map::createNpc()
{   
    int tipo = rand() % 7;
    Npc* npc = new Npc(tipo+1, 1200.f, rand()%720);
    npcs.push_back(npc);
}

/*
Crea un asteroide
*/
void Map::createAsteroid()
{
    Asteroid* ast = new Asteroid(1200.f, rand()%720);
    asteroids.push_back(ast);
}

/*
Crea un jefe
*/
void Map::createBoss()
{
       int jefeTipo =  rand() % 3; 
    if(jefeTipo==0){
    boss = new Npc(8, 1200.f, 720/2);
    }
    if(jefeTipo==1){
    boss = new Npc(9, 1200.f, 720/2);
    }
    if(jefeTipo==2){
    boss = new Npc(10, 1200.f, 720/2);
    }
}

/*
Crea una bala
*/
void Map::createBullet(float x, float y, float orient, int type, bool fromPlayer)
{
    Bullet *n_bullet = new Bullet(x, y, orient, type, fromPlayer);
    bullets.push_back(n_bullet);
}


void Map::createAnimation(float x, float y, float orient, int type)
{
    EmptyAnimation* anim = new EmptyAnimation(x, y, orient, (EmptyAnimation::Type)type);
    animations.push_back(anim);
}


/* 
Devuelve el player creado
*/
Player* Map::createPlayer(float x, float y)
{
    Player* p = new Player(x, y);
    p->setHp(playerHp);
    return p;
}

void Map::createLife(float x, float y)
{
    PowerUp* p = new PowerUp(LIFE, x, y);
    powerUps.push_back(p);
}

/*
Carga toda la información del mapa
*/
void Map::loadMapInfo(int lvl)
{   
    tinyxml2::XMLDocument document;
    tinyxml2::XMLElement* xmlMap;
    tinyxml2::XMLElement* imageLayer;
    //std::string rutaMapa = "resources/maps/mapa" + std::to_string(lvl) + "/mapa.tmx";
    int escenario;
    do
    {
        escenario = rand()% 4 + 1;
    } while (escenario == mapaAnterior);

    mapaAnterior = escenario;
    

    //int escenario = 1;
    std::string rutaMapa = "resources/maps/mapa" + std::to_string(lvl) +"/mapa" + std::to_string(escenario) + ".tmx";
    


    document.LoadFile(rutaMapa.c_str());

    xmlMap = document.FirstChildElement("map");

    imageLayer = xmlMap->FirstChildElement("imagelayer");
    std::string ruta = "resources/maps/mapa" + std::to_string(lvl) +"/" + imageLayer->FirstChildElement("image")->Attribute("source");
    fondo = Render::getInstance()->createSprite(ruta);
     

}

/*
Dibujado del mapa
*/  
void Map::draw()
{
    float v1 = .1;
    float v2 = .9;

    int n = v1*mapPosition/1080;
    float xpos = (1080 * n) - mapPosition*v1;

    Render::getInstance()->drawSprite(fondo, Rvect(xpos, 0), 0.f, 1.f, false);
    Render::getInstance()->drawSprite(fondo, Rvect(xpos + 1080, 0), 0.f, 1.f, false);

    n = v2*mapPosition/1080;
    xpos = (1080 * n) - mapPosition*v2;

    Render::getInstance()->drawSprite(paredes, Rvect(xpos, 0), 0.f, 1.f, false);
    Render::getInstance()->drawSprite(paredes, Rvect(xpos + 1080, 0), 0.f, 1.f, false);

    drawObjects();

    hud->draw();
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
    }else
    {
        mapIncPosition = 0.f;
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

   prob = (baseAsteroid + level*incAsteroid);
   r = rand()%10000;
   if(r<prob)
   {
       createAsteroid();
   }
}

void Map::updateObjects(float dt)
{
    player->update (dt);

    if(boss)boss->update(dt);

    //Borrado de balas fuera del mapa y update
    for(auto it = bullets.begin(); it < bullets.end(); it++) {
        //Con este bucle, controlaremos el borrar las balas cuando estas salgan del mapa.
        if((*it)->getPhysics()->getPosition().x > 2000 || (*it)->getPhysics()->getPosition().x < -100 
            || (*it)->getPhysics()->getPosition().y > 800 || (*it)->getPhysics()->getPosition().y < -100 ) {
            //Cumplida la condicion, procedemos a borrar la bala.
            delete (*it);
            bullets.erase(it);
            it--;
        } else {
            //Llamar al update de la bala
            (*it)->update(dt);
        }
    }

    //Borrado de powerups fuera del mapa y update
    for(auto it = powerUps.begin(); it < powerUps.end(); it++) {
        //Con este bucle, controlaremos el borrar las balas cuando estas salgan del mapa.
        if((*it)->getPhysics()->getPosition().x > 2000 || (*it)->getPhysics()->getPosition().x < -100 
            || (*it)->getPhysics()->getPosition().y > 800 || (*it)->getPhysics()->getPosition().y < -100 ) {
            //Cumplida la condicion, procedemos a borrar la bala.
            delete (*it);
            powerUps.erase(it);
            it--;
        } else {
            //Llamar al update de la bala
            (*it)->update(dt);
        }
    }

    //Borrado de npcs fuera del mapa y update
    for(auto it = npcs.begin(); it < npcs.end(); it++) {
        //Con este bucle, controlaremos el borrar las balas cuando estas salgan del mapa.
        if((*it)->getPhysics()->getPosition().x > 2000 || (*it)->getPhysics()->getPosition().x < -100 
            || (*it)->getPhysics()->getPosition().y > 800 || (*it)->getPhysics()->getPosition().y < -100 ) {
            //Cumplida la condicion, procedemos a borrar la bala.
            delete (*it);
            npcs.erase(it);
            it--;
        } else {
            //Llamar al update de la bala
            (*it)->update(dt);
        }
    }
    
    //Borrado de animations fuera del mapa y update
    for(auto it = animations.begin(); it < animations.end(); it++) {
        //Con este bucle, controlaremos el borrar las balas cuando estas salgan del mapa.
        if((*it)->getPhysics()->getPosition().x > 2000 || (*it)->getPhysics()->getPosition().x < -100 
            || (*it)->getPhysics()->getPosition().y > 800 || (*it)->getPhysics()->getPosition().y < -100 
            || (*it)->getKill()) {
            //Cumplida la condicion, procedemos a borrar la bala.
            delete (*it);
            animations.erase(it);
            it--;
        } else {
            //Llamar al update de la bala
            (*it)->update(dt);
        }
    }

    //Borrado de asteroides fuera del mapa y update
    for(auto it = asteroids.begin(); it < asteroids.end(); it++) {
        //Con este bucle, controlaremos el borrar los asteroides cuando estos salgan del mapa.
        if((*it)->getPhysics()->getPosition().x > 2000 || (*it)->getPhysics()->getPosition().x < -100 
            || (*it)->getPhysics()->getPosition().y > 800 || (*it)->getPhysics()->getPosition().y < -100) {
            //Cumplida la condicion, procedemos a borrar el asteroide.
            delete (*it);
            asteroids.erase(it);
            it--;
        } else {
            //Llamar al update del asteroide
            (*it)->update(dt);
        }
    }
}

void Map::drawObjects()
{
    //Dibujado player
    if(player)player->draw();

    //Dibujado del boss
    if(boss)boss->draw();

    //Dibujado Balas
    for(auto it = bullets.begin(); it < bullets.end(); it++)
            (*it)->draw();

    //Dibujado powerUps
    for(auto it = powerUps.begin(); it < powerUps.end(); it++)
            (*it)->draw();
        
    //Dibujado de npcs
    for(auto it = npcs.begin(); it < npcs.end(); it++)
                (*it)->draw();
    
    //Dibujado de animaciones
    for(auto it = animations.begin(); it < animations.end(); it++)
        (*it)->draw();
    
    //Dibujado de asteroides
    for(auto it = asteroids.begin(); it < asteroids.end(); it++)
        (*it)->draw();
}

void Map::updateColisions()
{
    ///Colision de power ups
    for(auto it = powerUps.begin(); it<powerUps.end(); it++)
    {
        if((*it)->getPhysics()->colides(player->getPhysics()))
        {
            switch ((*it)->getType())
            {
            case LIFE:
                player->hpUp(10);
                break;
            case WEAPON1:
                /* code */
                break;
            
            default:
                break;
            }
            delete (*it);
            powerUps.erase(it);
            it--;
        }
    }
    
    //Colision de balas
    for(auto it = bullets.begin(); it<bullets.end(); it++)
    {
        bool colision = false;

        // Si la bala es del jugador
        if( (*it)->isFromPlayer() ) 
        {
            Physics* p = (*it)->getPhysics();

            // comprobar si colisiona con el boss
            if(this->boss!=nullptr)
            {
                if(p->colides(boss->getPhysics()))
                {
                    if(boss->hpDown((*it)->getForce()))
                    {
                        delete boss;
                        boss = nullptr;
                        score += bossScore * (1 + (level*incScore));
                        playerHp = player->getHp();

                        _score = score;
                        _level = level;
                        clear();
                        Game::getInstance()->setState(State::NEXTLEVEL);
                        return;
                    } 
                    colision = true;
                }
            }
            
            // comprobar si colisiona con los npcs
            for(auto jt = npcs.begin(); jt<npcs.end() && !colision; jt++)
            {
                if(p->colides((*jt)->getPhysics()))
                {
                    colision = true;
                    if((*jt)->hpDown((*it)->getForce()))
                    {
                        createAnimation((*jt)->getPhysics()->getPosition().x, (*jt)->getPhysics()->getPosition().y, 0.f, EmptyAnimation::EXPLOSION);
                        delete *jt;
                        npcs.erase(jt);
                        score += enemyScore * (1 + (level*incScore));
                        kills++;
                    }
                }
            }

            // Comprobar si colisiona con los asteroides
            for(auto at = asteroids.begin(); at<asteroids.end() && !colision; at++)
            {
                if(p->colides((*at)->getPhysics()))
                {
                    colision = true;
                    // create a smaller asteroid
                    int tam = (*at)->getSize();

                    if(tam > 3)
                    {
                        int type = (*at)->getType();
                        Pvect pos = (*at)->getPhysics()->getPosition();
                        float orient = p->getOrient() + (rand() % 21 + (-10));
                        Asteroid* small = new Asteroid(type, 3, pos.x, pos.y, orient);
                        orient = p->getOrient() + (rand() % 181 + (-90));
                        Asteroid* small2 = new Asteroid(type, 3, pos.x, pos.y, orient);
                        delete *at;
                        asteroids.erase(at);
                        asteroids.push_back(small);
                        asteroids.push_back(small2);
                    }
                    else
                    {
                        int type = (*at)->getType();
                        Pvect pos = (*at)->getPhysics()->getPosition();
                        float orient = p->getOrient() + (rand() % 21 + (-10));
                        Asteroid* small = new Asteroid(type, 1, pos.x, pos.y, orient);
                        orient = p->getOrient() + (rand() % 181 + (-90));
                        Asteroid* small2 = new Asteroid(type, 1, pos.x, pos.y, orient);
                        delete *at;
                        asteroids.erase(at);
                        asteroids.push_back(small);
                        asteroids.push_back(small2);
                    }
                    
                }
            }

        }else{
            if(player && player->getPhysics()->colides((*it)->getPhysics()))
            {
                colision = true;
                Render::getInstance()->shake();
                if(player->hpDown((*it)->getForce()))
                {
                    delete player;
                    player = nullptr;
                }
            }
            
        }
        if(colision)
        {
            delete *it;
            bullets.erase(it);
            it--;
        }
    }

    // Colisión de asteroides
    if(player)
    {
        for(auto it = asteroids.begin(); it<asteroids.end(); it++)
        {
            if((*it)->getPhysics()->colides(player->getPhysics()))
            {
                // SI COLISIONAN CON EL JUGADOR
                
                if(!(*it)->getHasColided())
                {
                    float orient = player->getPhysics()->getOrient() + (rand() % 21 + (-10));
                    (*it)->changeOrientation(orient);
                    player->hpDown(2);
                    Render::getInstance()->shake();
                }
            }
        }
    }
    
}


/*
Carga un nivel
*/
void Map::loadLevel(int tipo)
{
    clear();
    if(level >= 3)
    {
        loadMapInfo(1);
    }
    else
    {
        loadMapInfo(1);
    }
    
    mapPosition = 0.f;
    level++;
    if(level == 0)
        score = 0;
    
    player = createPlayer(_Player_InitX, _Player_InitY);
}

int Map::getScore()
{
    return _score;
}

int Map::getLevel()
{
    return level;
}