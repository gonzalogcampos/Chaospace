#pragma once

//Header
#include <GameObject.h>

//External headers
#include <vector>

//Forward declarations
class Bullet;



class Ship: public GameObject{
    public:

        Ship(); //Constructor por defecto de la clase Ship.

        ~Ship(); //Metodo destructor de un Ship.

        void shoot(bool p = false); //Metodo que controla y permite el disparo efectuado por un Ship.

        void hpUp(int hp); //Metodo auxiliar utilizado para subir en 1 el valor de la vida de la nave.

        bool hpDown(int hp); //Metodo auxiliar empleado para baar en 1 el valor de la vida de la nave.

        int getHp();

        void update(float dt);

        void setWeaponType(int t);

        int getWeaponType();
        
        void draw();
        
    protected:
        int hp; //Variable responsable del control de la vida tanto del Player como de los Enemigos.
        float st = 0.f;
        int weaponType = 0;
        float cadencia;
        float shootAnimTime = 0.f;
        unsigned int shootAnim;
};