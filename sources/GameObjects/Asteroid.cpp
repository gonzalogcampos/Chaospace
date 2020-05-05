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

    // cojo todos los sprites
    // primero los marrones
    sprites[0][0] = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 0, 105, 89));
    sprites[0][1] = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 92, 99, 98));
    sprites[0][2] = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 186, 60, 64));
    sprites[0][3] = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 285, 40, 43));
    sprites[0][4] = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 388, 23, 26));
    sprites[0][5] = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(112, 0, 128, 98));
    sprites[0][6] = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(116, 98, 108, 97));
    sprites[0][7] = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(117, 195, 51, 43));
    sprites[0][8] = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(114, 288, 41, 38));
    sprites[0][9] =  Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(117, 387, 22, 25));
    // ahora los grises
    sprites[1][0] = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 0, 105, 89));
    sprites[1][1] = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 92, 99, 98));
    sprites[1][2] = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 186, 60, 64));
    sprites[1][3] = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 285, 40, 43));
    sprites[1][4] = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 388, 23, 26));
    sprites[1][5] = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(112, 0, 128, 98));
    sprites[1][6] = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(116, 98, 108, 97));
    sprites[1][7] = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(117, 195, 51, 43));
    sprites[1][8] = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(114, 288, 41, 38));
    sprites[1][9] =  Render::getInstance()->createSprite("resources/Mgris.png", Rrect(117, 387, 22, 25));

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
            spriteActual = sprites[0][0];
            velRot = 10.f;
            velocity = 10.f;
            tam = 5;
            physics->setCircleBB(109.f);
            break;
        case 2:
            // Primera columna segundo sprite
            spriteActual = sprites[0][1];
            velRot = 30.f;
            velocity = 30.f;
            tam = 4;
            physics->setCircleBB(94.f);
            break;
        
        case 3:
            // Primera columna tercer sprite
            spriteActual = sprites[0][2];
            velRot = 50.f;
            velocity = 50.f;
            tam = 3;
            physics->setCircleBB(44.f);
            break;
        
        case 4:
            // Primera columna cuarto sprite
            spriteActual = sprites[0][3];
            velRot = 100.f;
            velocity = 100.f;
            tam = 2;
            physics->setCircleBB(27.f);
            break;
        case 5:
            // Primera columna quinto sprite
            spriteActual = sprites[0][4];
            velRot = 150.f;
            velocity = 150.f;
            tam = 1;
            physics->setNoBB();
            break;
        case 6:
            // Segunda columna primer sprite
            spriteActual = sprites[0][5];
            velRot = 10.f;
            velocity = 10.f;
            physics->setCircleBB(109.f);
            break;
        case 7:
            // Segunda columna segundo sprite
            spriteActual = sprites[0][6];
            velRot = 30.f;
            velocity = 30.f;
            physics->setCircleBB(94.f);
            break;
        case 8:
            // Segunda columna tercer sprite
            spriteActual = sprites[0][7];
            velRot = 50.f;
            velocity = 50.f;
            physics->setCircleBB(44.f);
            break;
        case 9:
            // Segunda columna cuarto sprite
            spriteActual = sprites[0][8];
            velRot = 100.f;
            velocity = 100.f;
            physics->setCircleBB(27.f);
            break;
        case 10:
            // Tercera columna quinto sprite
            spriteActual = sprites[0][9];
            velRot = 150.f;
            velocity = 150.f;
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
            spriteActual = sprites[1][0];
            velRot = 10.f;
            velocity = 10.f;
            type = 1;
            physics->setCircleBB(109.f);
            break;
        case 2:
            // Primera columna segundo sprite
            spriteActual = sprites[1][1];
            velRot = 30.f;
            velocity = 30.f;
            type = 1;
            physics->setCircleBB(94.f);
            break;
        
        case 3:
            // Primera columna tercer sprite
            spriteActual = sprites[1][2];
            velRot = 50.f;
            velocity = 50.f;
            type = 1;
            physics->setCircleBB(44.f);
            break;
        
        case 4:
            // Primera columna cuarto sprite
            spriteActual = sprites[1][3];
            velRot = 100.f;
            velocity = 100.f;
            type = 1;
            physics->setCircleBB(27.f);
            break;
        case 5:
            // Primera columna quinto sprite
            spriteActual = sprites[1][4];
            velRot = 150.f;
            velocity = 150.f;
            type = 1;
            physics->setNoBB();
            break;
        case 6:
            // Segunda columna primer sprite
            spriteActual = sprites[1][5];
            velRot = 10.f;
            velocity = 10.f;
            type = 1;
            physics->setCircleBB(109.f);
            break;
        case 7:
            // Segunda columna segundo sprite
            spriteActual = sprites[1][6];
            velRot = 30.f;
            velocity = 30.f;
            type = 1;
            physics->setCircleBB(94.f);
            break;
        case 8:
            // Segunda columna tercer sprite
            spriteActual = sprites[1][7];
            velRot = 50.f;
            velocity = 50.f;
            type = 1;
            physics->setCircleBB(44.f);
            break;
        case 9:
            // Segunda columna cuarto sprite
            spriteActual = sprites[1][8];
            velRot = 100.f;
            velocity = 100.f;
            type = 1;
            physics->setCircleBB(27.f);
            break;
        case 10:
            // Tercera columna quinto sprite
            spriteActual = sprites[1][9];
            velRot = 150.f;
            velocity = 150.f;
            type = 1;
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
Asteroid::Asteroid(int color, int tam, float X, float Y)
{

}

Asteroid::~Asteroid()
{
    Render::getInstance()->deleteAnimation(animation);
}

int Asteroid::getTam()
{
    return tam;
}

float Asteroid::getOrient()
{
    return physics->getOrient();
}

void Asteroid::update(float dt)
{
    physics->setOrient(physics->getOrient()+dt*velRot);
    GameObject::update(dt);
}


void Asteroid::draw()
{
    GameObject::draw();
}

// En update object de mapa tengo que comprobar colisión con el jugador
// En update colisions tengo que comprobar que colisionan con el meteorito