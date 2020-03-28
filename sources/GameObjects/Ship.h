#include <iostream>
#include <GameObject.cpp>
#include <Bullet.cpp>

using namespace std;

class Ship: public GameObject{
    protected:
        int hp; //Variable responsable del control de la vida tanto del Player como de los Enemigos.
        int wpn; //Variable que dependiendo del valor, indicara el tipo de disparo de la nave.
        Bullet *bullets[]; //Vector de punteros a las balas que contendra el Player o un enemigo.

    public:
        Ship(sf::Texture t); //Para crear el Ship sera necesario pasar una textura y que pueda asi tener un Sprite.

        ~Ship(); //Metodo destructor de un Ship.

        void move(); //Metodo que permite el movimiento de un Ship.

        void shoot(); //Metodo que controla y permite el disparo efectuado por un Ship.

        sf::Sprite getSprite(); //Metodo que permite recoger el Sprite de un Ship.
};