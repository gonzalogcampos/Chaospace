//Main header
#include <Ship.h>

//Headers
#include <Bullet.h>
#include <Physics.h>
#include <Map.h>
#include <weapons.h>
#include <Render.h>

/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


//Constructor por defecto de la clase Ship.
Ship::Ship()
{ 
    hp = 1;
    weaponType = 1;
    shootAnim = Render::getInstance()->createAnimation(120);
}

 //Metodo destructor de un Ship.
Ship::~Ship()
{
    Render::getInstance()->deleteAnimation(shootAnim);
}


//Metodo que controla y permite el disparo efectuado por un Ship.
void Ship::shoot(bool p)
{
    if(st>cadencia)
    {
        st = 0.f;
        shootAnimTime = .1f;
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

int Ship::getHp()
{
    return hp;
}

void Ship::setHp(int hp)
{
    this->hp = hp;
}

void Ship::update(float dt)
{
    st += dt;
    if(shootAnimTime>0.f)
        shootAnimTime -= dt;
    
    GameObject::update(dt);
}

void Ship::setWeaponType(int t)
{
    weaponType = t;
    Render* r = Render::getInstance();
    r->clearAnimation(shootAnim);
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

   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(1*50, 3*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(3*50, 3*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(0*50, 4*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(2*50, 4*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(4*50, 4*50, 50, 50))); 
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(1*50, 5*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(3*50, 5*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(0*50, 6*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(2*50, 6*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(4*50, 6*50, 50, 50)));  
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(1*50, 7*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(3*50, 7*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(0*50, 8*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(2*50, 8*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(4*50, 8*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(1*50, 9*50, 50, 50)));
   r->addFrameToAnimation(shootAnim,r->createSprite("resources/lightsplash2.png", Rrect(3*50, 9*50, 50, 50)));
}

int Ship::getWeaponType()
{
    return weaponType;
}

void Ship::draw()
{
    Rvect d = Render::getInstance()->polarToCartesian(80.f,  physics->getOrient());
    if(shootAnimTime>0.f)
        Render::getInstance()->drawAnimation(shootAnim, Rvect(physics->getPosition().x+d.x, physics->getPosition().y+d.y), physics->getOrient() + 90.f);
    
    GameObject::draw();
}