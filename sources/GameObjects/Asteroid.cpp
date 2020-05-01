// Main header
#include <Asteroid.h>

// Headers
#include <Render.h>
#include <Physics.h>


Asteroid::Asteroid(float X, float Y)
{
    int tipo = rand() % 2 + 1;
    animation = Render::getInstance()->createAnimation(1.f);
    Rint sprite;
    if(tipo == 1)
    {
        // si es de tipo 1 son los meteoritos marrones
        // Un random para saber el tamanyo del asteroide
        int tam = rand() % 10 + 1;
        switch (tam)
        {
        case 1:
            // Primera columna primer sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 0, 105, 89));
            velRot = 1.3f;
            break;
        case 2:
            // Primera columna segundo sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 92, 99, 98));
            velRot = 1.6f;
            break;
        
        case 3:
            // Primera columna tercer sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 186, 60, 64));
            velRot = 1.9f;
            break;
        
        case 4:
            // Primera columna cuarto sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 285, 40, 43));
            velRot = 2.1f;
            break;
        case 5:
            // Primera columna quinto sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(0, 388, 23, 26));
            velRot = 2.5f;
            break;
        case 6:
            // Segunda columna primer sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(112, 0, 128, 98));
            velRot = 1.3f;
            break;
        case 7:
            // Segunda columna segundo sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(116, 98, 108, 97));
            velRot = 1.6f;
            break;
        case 8:
            // Segunda columna tercer sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(117, 195, 51, 43));
            velRot = 1.9f;
            break;
        case 9:
            // Segunda columna cuarto sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(114, 288, 41, 38));
            velRot = 2.1f;
            break;
        case 10:
            // Tercera columna quinto sprite
            sprite = Render::getInstance()->createSprite("resources/Mmarron.png", Rrect(117, 387, 22, 25));
            velRot = 2.5f;
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
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 0, 105, 89));
            velRot = 1.3f;
            break;
        case 2:
            // Primera columna segundo sprite
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 92, 99, 98));
            velRot = 1.6f;
            break;
        
        case 3:
            // Primera columna tercer sprite
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 186, 60, 64));
            velRot = 1.9f;
            break;
        
        case 4:
            // Primera columna cuarto sprite
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 285, 40, 43));
            velRot = 2.1f;
            break;
        case 5:
            // Primera columna quinto sprite
            velRot = 2.5f;
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(0, 388, 23, 26));
            break;
        case 6:
            // Segunda columna primer sprite
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(112, 0, 128, 98));
            velRot = 1.3f;
            break;
        case 7:
            // Segunda columna segundo sprite
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(116, 98, 108, 97));
            velRot = 1.6f;
            break;
        case 8:
            // Segunda columna tercer sprite
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(117, 195, 51, 43));
            velRot = 1.9f;
            break;
        case 9:
            // Segunda columna cuarto sprite
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(114, 288, 41, 38));
            velRot = 2.1f;
            break;
        case 10:
            // Tercera columna quinto sprite
            sprite = Render::getInstance()->createSprite("resources/Mgris.png", Rrect(117, 387, 22, 25));
            velRot = 2.5f;
            break;
        default:
            break;
        }
    }
    
    Render::getInstance()->addFrameToAnimation(animation, sprite);
    physics->setPosition(Pvect(X, Y));

}

Asteroid::~Asteroid()
{
    
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