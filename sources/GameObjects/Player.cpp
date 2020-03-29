#include <Player.h>

Player::Player(){ //Constructor por defecto de la clase Player.

}

Player::Player(sf::Texture t){ //Metodo constructor de la clase Player. Es necesario pasarle una Textura.
    textura = t;
    sprite.setTexture(t); //Colocamos el Sprite segun la textura que se haya pasado.
    wpn = 1; //Ponemos el arma al 1, que sera el disparo sencillo estandar.
    hp = 3; //Pondremos su vida en el valor inicial de 3.
    powerUp = 0; //Al colocar un 0, inicializamos al Player sin powerUps pasivos.
}

Player::~Player(){ //Metodo destructor de la clase Player.

}

int Player::getPUp(){ //Metodo para recuperar el powerUp pasivo actual del Player.
    return powerUp;
} 

void Player::setPUp(int i){ //Metodo para cambiar el powerUp pasivo actual del Player.
    //if(i >= ?min? && i <= ?max?){
        powerUp = i;
    //}
} 

//Override del metodo move()

//Override del metodo shoot()

//Override del metodo de colisiones
