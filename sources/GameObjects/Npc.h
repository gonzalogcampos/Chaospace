#pragma once
#include "Ship.h"
#include "Bullet.h"



using namespace std;

class Npc : public Ship {
    private:
   
    int tipo;
    int X,Y;
    int contador=0;
    unsigned int nave;
    std::vector<Bullet*> Bullets;
    public: 
    Npc(); //Cosntructor por defecto de la clase Player.
    
    Npc( int IA, int posX, int posY); //Metodo constructor de la clase Player. Es necesario pasarle una Textura.

    ~Npc(); //Metodo destructor de la clase Player.

    void IA(int tipo);

    void enemigo1();
    void enemigo2();
    void enemigo3();
    void enemigo4();
    void enemigo5();
    void enemigo6();


    void Update();
};
