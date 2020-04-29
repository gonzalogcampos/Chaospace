//Main header
#include <Ship.h>

//Headers
#include <Bullet.h>
#include <Physics.h>
#include <Map.h>


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


//Constructor por defecto de la clase Ship.
Ship::Ship()
{ 
    wpn = 1;
    hp = 1;
}

 //Metodo destructor de un Ship.
Ship::~Ship()
{

}


//Metodo que controla y permite el disparo efectuado por un Ship.
void Ship::shoot()
{
    if(st>cadencia)
    {
        st = 0.f;
        Map::getInstance()->createBullet(physics->getPosition().x, physics->getPosition().y, shootVel, physics->getOrient(), bulletType, false);
    }
} 

//Metodo auxiliar utilizado para subir en 1 el valor de la vida de la nave.
void Ship::hpUp(int hp)
{
    this->hp += hp;
}

 //Metodo auxiliar empleado para bajar en 1 el valor de la vida de la nave.
bool Ship::hpDown(int hp)
{
    this->hp -= hp;

    if(this->hp<=0)
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
    st += dt;
    GameObject::update(dt);
}

void Ship::setBulletType(int t)
{
    bulletType = t;
}

int Ship::getBulletType()
{
    return bulletType;
}

void Ship::setCadencia(float c)
{
    cadencia = c;
}