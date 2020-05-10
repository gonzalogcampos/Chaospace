#pragma once

//Header
#include <Ship.h>

//Forward declarations
class Bullet;

class Npc : public Ship {
    private:
    int ataqueboss=1;
    int movboss=0;
    int tipo, cadencia;
    int X,Y,XPlayer, YPlayer;
    int contador=0;
    unsigned int nave;
    std::vector<Bullet*> Bullets;
    
    public: 
    Npc(); //Cosntructor por defecto de la clase Player.
    
    Npc( int IA, float posX, float posY); //Metodo constructor de la clase Player. Es necesario pasarle una Textura.

    ~Npc(); //Metodo destructor de la clase Player.

    void IA(int tipo);

    void enemigo1();
    void enemigo2();
    void enemigo3();
    void enemigo4();
    void enemigo5();
    void enemigo6();


    void update(float dt);
};
