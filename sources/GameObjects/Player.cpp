#include <Player.h>
#include <Physics.h>
#include <Bullet.h>

Player::Player(){ //Constructor por defecto de la clase Player.
    wpn = 1; //Ponemos el arma al 1, que sera el disparo sencillo estandar.
    hp = 3; //Pondremos su vida en el valor inicial de 3.
    powerUp = 0; //Al colocar un 0, inicializamos al Player sin powerUps pasivos.

}

/*
Player::Player(sf::Texture t){ //Metodo constructor de la clase Player. Es necesario pasarle una Textura.
    textura = t;
    sprite.setTexture(t); //Colocamos el Sprite segun la textura que se haya pasado.
    wpn = 1; //Ponemos el arma al 1, que sera el disparo sencillo estandar.
    hp = 3; //Pondremos su vida en el valor inicial de 3.
    powerUp = 0; //Al colocar un 0, inicializamos al Player sin powerUps pasivos.
}
*/

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

void Player::move(sf::Event *e){

    if(e->type == sf::Event::KeyPressed){
        float vx = 0.f;
        float vy = 0.f;
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            //set_frame(*spr_personaje1,{4,0});
            //spr_personaje1->setPosition(spr_personaje1->getPosition().x,spr_personaje1->getPosition().y - 10);   
            //movement.y -=3;
            vy = -3.f;
            //getSprite().move(movement); //TENGO QUE RECUPERAR EL SPRITE AUN          
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            //set_frame(*spr_personaje1,{0,0});
            //spr_personaje1->setPosition(spr_personaje1->getPosition().x,spr_personaje1->getPosition().y + 10);
            //movement.y +=3;
            vy = 3.f;
            //getSprite().move(movement); //TENGO QUE RECUPERAR EL SPRITE AUN
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            //set_frame(*spr_personaje1,{7,0});
            //spr_personaje1->setPosition(spr_personaje1->getPosition().x + 10,spr_personaje1->getPosition().y);
            //movement.x +=3;
            vx = -3.f;
            //getSprite().move(movement); //TENGO QUE RECUPERAR EL SPRITE AUN
        }else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            //set_frame(*spr_personaje1,{3,0});
            //spr_personaje1->setPosition(spr_personaje1->getPosition().x - 10,spr_personaje1->getPosition().y);
            //movement.x -=3;
            vx = 3.f;
            //getSprite().move(movement); //TENGO QUE RECUPERAR EL SPRITE AUN
        }
        physics->setVelocity(Pvect(vx, vy));
    }
}

void Player::shoot(){

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){ //AUN TENGO QUE CAMBIAR LO DE SPR_PERSONAJE1
        //sf::Vector2f bullet_pos = sf::Vector2f(spr_personaje1->getPosition().x+40,spr_personaje1->getPosition().y-4);
        //Bullet *n_bullet = new Bullet(bullet_pos);
        //bullets.push_back(n_bullet);
    }

    for(unsigned i = 0; i < bullets.size(); i++) {
        //Con este bucle, controlaremos el borrar las balas cuando estas salgan del mapa.
        if(bullets.at(i)->getPhysics()->getPosition().x > 800 || bullets.at(i)->getPhysics()->getPosition().x < 0 ) { //Aqui controlamos que salgan de la pantalla horizontalmente.
            //En caso de cumplirse la condicion, borramos dicha bala.
            delete bullets.at(i);
            bullets.erase(bullets.begin()+i);

        } else if(bullets.at(i)->getPhysics()->getPosition().y > 720 || bullets.at(i)->getPhysics()->getPosition().y < 0 ) { //Aqui controlamos que se salgan de la pantalla verticalmente.
            //Cumplida la condicion, procedemos a borrar la bala.
            delete bullets.at(i);
            bullets.erase(bullets.begin()+i);
        
        } else {
            //Llamar al update de la bala
            bullets.at(i)->update();
        }
    }

     //mov_nave=sf::Vector2f(0.f,0.f);
}

//Override del metodo de colisiones
