//Main header
#include <Ship.h>

//Headers
#include <Bullet.h>
#include <Physics.h>
#include <Map.h>
#include <weapons.h>

/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


//Constructor por defecto de la clase Ship.
Ship::Ship()
{ 
    hp = 1;
    weaponType = 1;
}

 //Metodo destructor de un Ship.
Ship::~Ship()
{

}


//Metodo que controla y permite el disparo efectuado por un Ship.
void Ship::shoot(bool p)
{
    float cadencia = 1.f;
    switch (weaponType)
    {
    case 1:
        cadencia = w1_Cadencia;
        break;
    case 2:
        cadencia = w2_Cadencia;
        break;    
    case 3:
        cadencia = w3_Cadencia;
        break;    
    case 4:
        cadencia = w4_Cadencia;
        break;    
    case 5:
        cadencia = w5_Cadencia;
        break;
    case 6:
        cadencia = w6_Cadencia;
        break;    
    case 7:
        cadencia = w7_Cadencia;
        break;
    default:
        cadencia = 1.f;
        break;
    }
    if(st>cadencia)
    {
        st = 0.f;
        Map::getInstance()->createBullet(physics->getPosition().x, physics->getPosition().y, physics->getOrient(), weaponType, p);
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

void Ship::update(float dt)
{
    st += dt;
    GameObject::update(dt);
}

void Ship::setWeaponType(int t)
{
    weaponType = t;
}

int Ship::getWeaponType()
{
    return weaponType;
}

void Ship::draw()
{

    GameObject::draw();
}