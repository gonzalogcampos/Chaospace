#pragma once


#include <iostream>
#include <vector>

/*
Aparecera un boss al final de cada nivel.
    - el nivel dura un tiempo x*l*it
    - los enemigos aparecen con una frecuencia x
    - los meteoritos aparecen con una frecuencia x
    - pueden aparecer en cualquier punto a la derecha de la pantalla
    - se mueven a una velocidad v hacia la izquierda
    - los enemigos se crean con vida, fuerza, y ataque * dependiendo del nivel
    - los enemigos se guardan en un vector
    - los meteoritios se guardan en un vector
    - el boss se muere cada 5 segundos en este test
*/

//Definitions

const unsigned int window_height = 702;
const unsigned int window_width = 702;

const float timePerLevel = 1.f;  //s
const float timeInc = 3.f;        //s
const float bossTime = .5f;       //s


const float enemiesPerSecond = .01f;
const float incEnemiesPerSecond = .01f;
const float enemiesLife = 3.f;
const float incEnemiesLife = .1f;
const float enemiesForce = 2.f;
const float incEnemiesForce = .1f;
const float enemiesAttak = 1.f;
const float incEnemiesAttak = 0.2f;


const float meteorosPerSecond = .01f;
const float incMeteorosPerSecond = .01f;
const float meteorosVelocity = 100.f;
const float incMeteorosVelocity = .2f;

class Meteoro
{
    public:
        Meteoro(float x, float y, float velocity){this->x = x; this->y = y; this->velocity = velocity;};
        float x, y;
        float velocity;

};

class Enemy
{
    public:
        Enemy(float x, float y, float life, float force, float attak){this->x = x; this->y = y; this->life = life; this->force = force; this->attak = attak;};
        float x, y;
        float life, force, attak;

};

class Boss
{
    public:
        Boss(){};
        Boss(float x, float y, float life, float force, float attak){this->x = x; this->y = y; this->life = life; this->force = force; this->attak = attak;};
        float x, y;
        float life, force, attak;

};

class LevelMaker
{
    public:
        LevelMaker(){};
        ~LevelMaker(){};

        void updateGame(float dt);

        void endGame();

        void initGame();

        void test(int levels);


    private:
        float gameTime;
        unsigned int level;
        float levelTime;
        std::vector<Meteoro> meteoros;
        std::vector<Enemy> enemies;
        Boss boss;
        bool bossState = false;
        void tryCreate(float dt);
        void createEnemy();
        void createMeteoro();
        void createBoss();
        void updateVectors(float dt);


        /*
        For test only
        */
        void printData(Meteoro meteoro);
        void printData(Enemy enemy);
        void printData(Boss boss);
        void printAllData();


};

