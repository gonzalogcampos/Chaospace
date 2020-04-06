#pragma once
#include <vector>
#include <GameObject.h>


class Bullet;

class Ship: public GameObject{
    protected:
        int hp; //Variable responsable del control de la vida tanto del Player como de los Enemigos.
        int wpn; //Variable que dependiendo del valor, indicara el tipo de disparo de la nave.
        std::vector<Bullet*> bullets; //Vector de punteros a las balas que contendra el Player o un enemigo.
        bool alive;
        float cadencia =1.f;
        float st = 0.f;

    public:
        Ship(); //Constructor por defecto de la clase Ship.
        ~Ship(); //Metodo destructor de un Ship.

        std::vector<Bullet*>* getBullets();

        void shoot(); //Metodo que controla y permite el disparo efectuado por un Ship.

        void hpUp(); //Metodo auxiliar utilizado para subir en 1 el valor de la vida de la nave.

        void hpDown(); //Metodo auxiliar empleado para bajar en 1 el valor de la vida de la nave.

        int getWpn(); //Metodo utilizado para recuperar informacion de que arma tiene la nave en el momento.

        void setWpn(int i); //Metodo para cambiar el tipo de arma que lleva una nave.

        void update(float dt);

};