// Main header
#include <Asteroid.h>

// Headers
#include <Render.h>
#include <Physics.h>

/*
Constructor por defecto para crear un asteroide aleatorio
*/
Asteroid::Asteroid(float X, float Y)
{
    int tipo = rand() % 2 + 1;
    animation = Render::getInstance()->createAnimation(1.f);

    Rint spriteActual;
    
    if(tipo == 1)
    {
        // si es de tipo 1 son los meteoritos marrones
        // Un random para saber el tamanyo del asteroide
        int tam = rand() % 10 + 1;
        switch (tam)
        {
        case 1:
            // Primera columna primer sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 0, 105, 89));
            velRot = 10.f;
            velocity = 10.f;
            type = 0;
            size = 5;
            physics->setCircleBB(109.f);
            break;
        case 2:
            // Primera columna segundo sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 92, 99, 98));
            velRot = 30.f;
            velocity = 30.f;
            type = 0;
            size = 4;
            physics->setCircleBB(94.f);
            break;
        
        case 3:
            // Primera columna tercer sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 186, 60, 64));
            velRot = 50.f;
            velocity = 50.f;
            type = 0;
            size = 3;
            physics->setCircleBB(44.f);
            break;
        
        case 4:
            // Primera columna cuarto sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 285, 40, 43));
            velRot = 100.f;
            velocity = 100.f;
            type = 0;
            size = 2;
            physics->setCircleBB(27.f);
            break;
        case 5:
            // Primera columna quinto sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 388, 23, 26));
            velRot = 150.f;
            velocity = 150.f;
            type = 0;
            size = 1;
            physics->setNoBB();
            break;
        case 6:
            // Segunda columna primer sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(112, 0, 128, 98));
            velRot = 10.f;
            velocity = 10.f;
            type = 0;
            size = 5;
            physics->setCircleBB(109.f);
            break;
        case 7:
            // Segunda columna segundo sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(116, 98, 108, 97));
            velRot = 30.f;
            velocity = 30.f;
            type = 0;
            size = 4;
            physics->setCircleBB(94.f);
            break;
        case 8:
            // Segunda columna tercer sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(117, 195, 51, 43));
            velRot = 50.f;
            velocity = 50.f;
            type = 0;
            size = 3;
            physics->setCircleBB(44.f);
            break;
        case 9:
            // Segunda columna cuarto sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(114, 288, 41, 38));
            velRot = 100.f;
            velocity = 100.f;
            type = 0;
            size = 2;
            physics->setCircleBB(27.f);
            break;
        case 10:
            // Tercera columna quinto sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(117, 387, 22, 25));
            velRot = 150.f;
            velocity = 150.f;
            type = 0;
            size = 1;
            physics->setNoBB();
            break;
        default:
            break;
        }
    }
    else
    {
        // si es de tipo 2 son los meteoritos grises

        // Un random para saber el tamanyo del asteroide
        int tam = rand() % 10 + 1;
        switch (tam)
        {
        case 1:
            // Primera columna primer sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 0, 105, 89));
            velRot = 10.f;
            velocity = 10.f;
            type = 1;
            size = 5;
            physics->setCircleBB(109.f);
            break;
        case 2:
            // Primera columna segundo sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 92, 99, 98));
            velRot = 30.f;
            velocity = 30.f;
            type = 1;
            size = 4;
            physics->setCircleBB(94.f);
            break;
        
        case 3:
            // Primera columna tercer sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 186, 60, 64));
            velRot = 50.f;
            velocity = 50.f;
            type = 1;
            size = 3;
            physics->setCircleBB(44.f);
            break;
        
        case 4:
            // Primera columna cuarto sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 285, 40, 43));
            velRot = 100.f;
            velocity = 100.f;
            type = 1;
            size = 2;
            physics->setCircleBB(27.f);
            break;
        case 5:
            // Primera columna quinto sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 388, 23, 26));
            velRot = 150.f;
            velocity = 150.f;
            type = 1;
            size = 1;
            physics->setNoBB();
            break;
        case 6:
            // Segunda columna primer sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(112, 0, 128, 98));
            velRot = 10.f;
            velocity = 10.f;
            type = 1;
            size = 5;
            physics->setCircleBB(109.f);
            break;
        case 7:
            // Segunda columna segundo sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(116, 98, 108, 97));
            velRot = 30.f;
            velocity = 30.f;
            type = 1;
            size = 4;
            physics->setCircleBB(94.f);
            break;
        case 8:
            // Segunda columna tercer sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(117, 195, 51, 43));
            velRot = 50.f;
            velocity = 50.f;
            type = 1;
            size = 3;
            physics->setCircleBB(44.f);
            break;
        case 9:
            // Segunda columna cuarto sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(114, 288, 41, 38));
            velRot = 100.f;
            velocity = 100.f;
            type = 1;
            size = 2;
            physics->setCircleBB(27.f);
            break;
        case 10:
            // Tercera columna quinto sprite
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(117, 387, 22, 25));
            velRot = 150.f;
            velocity = 150.f;
            type = 1;
            size = 1;
            physics->setNoBB();
            break;
        default:
            break;
        }
    }
    
    Render::getInstance()->addFrameToAnimation(animation, spriteActual);
    physics->setPosition(Pvect(X, Y));
    physics->setPolarVelocity(180, velocity);
    

}


/*
Constructor especial para pasarle un tipo y una posición.
color: 0 -> marrón    1-> gris
tam: 5 <= tam >= 1 (entre 1 y 5 incluidos)
*/
Asteroid::Asteroid(int color, int tam, float X, float Y, float orientation)
{
    animation = Render::getInstance()->createAnimation(1.f);
    Rint spriteActual;
    
    // Si el color es marrón
    if(color == 0)
    {
        if(tam == 3)
        {
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 186, 60, 64));
            physics->setCircleBB(44.f);
        }
        else if(tam == 1)
        {
            spriteActual = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(117, 387, 22, 25));
            physics->setNoBB();
        }
    }
    // si el color es gris
    else if(color == 1)
    {
        if(tam == 3)
        {
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(117, 195, 51, 43));
            physics->setCircleBB(44.f);
        }
        else if(tam == 1)
        {
            spriteActual = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 388, 23, 26));
            physics->setNoBB();
            
        }

    }

    Render::getInstance()->addFrameToAnimation(animation, spriteActual);
    float vel = rand()%100 + 50;
    physics->setPosition(Pvect(X, Y));
    physics->setPolarVelocity(orientation, vel);
}

Asteroid::~Asteroid()
{
    Render::getInstance()->deleteAnimation(animation);
}

int Asteroid::getSize()
{
    return size;
}

int Asteroid::getType()
{
    return type;
}

void Asteroid::changeOrientation(float newOrient)
{
    float newVel = velocity - rand()%30;
    physics->setPolarVelocity(newOrient, newVel);
    hasColided = true;
}

void Asteroid::update(float dt)
{
    physics->setOrient(physics->getOrient()+dt*velRot);
    GameObject::update(dt);
}

bool Asteroid::getHasColided()
{
    return hasColided;    
}

void Asteroid::draw()
{
    GameObject::draw();
}

// En update object de mapa tengo que comprobar colisión con el jugador
// En update colisions tengo que comprobar que colisionan con el meteorito