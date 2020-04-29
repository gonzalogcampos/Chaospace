#pragma once

//Header
#include <GameObject.h>

//External headers
#include <vector>

//Forward declarations
class Bullet;


class Ship: public GameObject{
    protected:
        int hp; //Variable responsable del control de la vida tanto del Player como de los Enemigos.
        int wpn; //Variable que dependiendo del valor, indicara el tipo de disparo de la nave.
        float cadencia =1.f;
        float shootVel = 1000.f;
        float st = 0.f;
        int bulletType = 1;

    public:
        Ship(); //Constructor por defecto de la clase Ship.
        ~Ship(); //Metodo destructor de un Ship.

        void shoot(); //Metodo que controla y permite el disparo efectuado por un Ship.

        void hpUp(int hp); //Metodo auxiliar utilizado para subir en 1 el valor de la vida de la nave.

        bool hpDown(int hp); //Metodo auxiliar empleado para bajar en 1 el valor de la vida de la nave.

        int getWpn(); //Metodo utilizado para recuperar informacion de que arma tiene la nave en el momento.

        void setWpn(int i); //Metodo para cambiar el tipo de arma que lleva una nave.

        void setCadencia(float c);

        void update(float dt);

        void setBulletType(int t);

        int getBulletType();

};