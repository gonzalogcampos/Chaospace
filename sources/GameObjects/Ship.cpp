#include <Ship.h>
#include <Bullet.h>
#include <Physics.h>
#include <iostream>

Ship::Ship(){ //Constructor por defecto de la clase Ship.
    wpn = 1;
}

Ship::~Ship(){ //Metodo destructor de un Ship.

}

std::vector<Bullet*>* Ship::getBullets()
{
    return &bullets;
}

//Metodo que controla y permite el disparo efectuado por un Ship.
void Ship::shoot()
{
    if(st>cadencia)
    {
        st = 0.f;
        Bullet *n_bullet = new Bullet(physics->getPosition().x, physics->getPosition().y, 1000.f, physics->getOrient(), 1);
        bullets.push_back(n_bullet);
    }
} 

//Metodo auxiliar utilizado para subir en 1 el valor de la vida de la nave.
void Ship::hpUp()
{
    hp++;
}

 //Metodo auxiliar empleado para bajar en 1 el valor de la vida de la nave.
bool Ship::hpDown()
{
    hp--;

    if(hp<=0)
        return true;
    

    return false;
}

 //Metodo utilizado para recuperar informacion de que arma tiene la nave en el momento.
int Ship::getWpn()
{
    return wpn;
}

//Metodo para cambiar el tipo de arma que lleva una nave.
void Ship::setWpn(int i)
{
        wpn = i;
}


void Ship::update(float dt)
{
    for(unsigned i = 0; i < bullets.size(); i++) {
        //Con este bucle, controlaremos el borrar las balas cuando estas salgan del mapa.
        if(bullets.at(i)->getPhysics()->getPosition().x > 2000 || bullets.at(i)->getPhysics()->getPosition().x < -100 ) { //Aqui controlamos que salgan de la pantalla horizontalmente.
            //En caso de cumplirse la condicion, borramos dicha bala.
            delete bullets.at(i);
            bullets.erase(bullets.begin()+i);

        } else if(bullets.at(i)->getPhysics()->getPosition().y > 800 || bullets.at(i)->getPhysics()->getPosition().y < -100 ) { //Aqui controlamos que se salgan de la pantalla verticalmente.
            //Cumplida la condicion, procedemos a borrar la bala.
            delete bullets.at(i);
            bullets.erase(bullets.begin()+i);
        
        } else {
            //Llamar al update de la bala
            bullets.at(i)->update(dt);
        }
    }
    st += dt;
    GameObject::update(dt);

}