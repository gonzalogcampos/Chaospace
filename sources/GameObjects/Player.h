#pragma once

//Header
#include <Ship.h>

class Player : public Ship {
    protected:
        int powerUp; //Variable que dicta si el Player ha cogido un powerUp pasivo, y lo identifica mediante un numero.
    
    public: 
        Player(float x, float y); //Cosntructor por defecto de la clase Player.

        //Player(sf::Texture t); //Metodo constructor de la clase Player. Es necesario pasarle una Textura.

        ~Player(); //Metodo destructor de la clase Player.

        void move(); //Sobrecarga del metodo de movimiento la clase padre.

        int getPUp(); //Metodo para recuperar el powerUp pasivo actual del Player.

        void setPUp(int i); //Metodo para cambiar el powerUp pasivo actual del Player.
        
        void update(float dt);
};

