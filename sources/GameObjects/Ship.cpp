#include <Ship.h>
#include <Bullet.h>
#include <Physics.h>

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
    Bullet *n_bullet = new Bullet(physics->getPosition().x, physics->getPosition().x, 10.f, physics->getOrient(), 1);
    bullets.push_back(n_bullet);
} 

//Metodo auxiliar utilizado para subir en 1 el valor de la vida de la nave.
void Ship::hpUp()
{
    hp++;
}

 //Metodo auxiliar empleado para bajar en 1 el valor de la vida de la nave.
void Ship::hpDown()
{
    hp--;
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
    GameObject::update(dt);
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
            bullets.at(i)->update(dt);
        }
    }
}