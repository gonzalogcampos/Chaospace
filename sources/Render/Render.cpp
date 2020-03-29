#include <Render.h>

/*
Destructor que llama a  la  funcion close de Render.
*/
Render::~Render()
{
    close();
}

/*
Inicializa el render creando una nueva ventana y reservando memoria para ella.
*/
void Render::init()
{
    // Create the main window
    window = new sf::RenderWindow(sf::VideoMode(800, 600), "Chaospace | The game 2020");

    spritesCont = 0;

    globalScale = 1;
}

/*
Llama a la funcion clearMemory() y libera la memoria reservada para la ventana.
*/
void Render::close()
{
    clearMemory();
    delete window;
}

/*
Devuelve true si la ventana esta abierta, sino devuelve false.
*/
bool Render::isWindowOpen()
{
    return window->isOpen();
}


/*
Funcion que se llama cuando incia el loop antes de pintar sprites.
Comprueba que la ventana este abierta, y borra todo lo dibujado antes.
*/
void Render::preLoop()
{
        // Process events
        sf::Event event;
        while (window->pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window->close();
        }
        // Clear screen
        window->clear();
}

/*
Funcion que se llama antes de terminar el loop.
Llama a la funcion update de la ventana.
*/
void Render::postLoop()
{
        // Update the window
        window->display();
}

/*
Borra toda la memoria reservada.
*/
void Render::clearMemory()
{
    //TODO
    spritesCont = 0;
}

/*
Aplica la escala global a todos los sprites.
*/
void Render::setGlobalScale(float scale)
{
    globalScale = scale;
}

/*
Devuelve la escala global que se aplica a todos los sprites.
*/
float Render::getGlobalScale()
{
    return globalScale;
}

/*
Carga la textura en la memoria, devuelve true si existe y false si no existe.
Si la textura ya estaba cargada no la actualiza
*/
bool Render::loadTexture(std::string texture)
{
    sf:: Texture*  tex= new sf::Texture();
    if(!tex->loadFromFile(texture))
        return false;

    textures.insert(std::pair<std::string, sf::Texture*>(texture, tex));

    return true;
}

/*
Borra la textura de la memoria y la libera, devuelve true si la textura existia
y false si no existia.
*/
bool Render::deleteTexture(std::string texture)
{
    bool r = false;
    if(textures.find(texture)!=textures.end())
    {
        delete textures.find(texture)->second;
        textures.erase(texture);
        r=true;
    }

    return r;
}

/*
Si la textura estaba cargada en la memoria devuelve un puntero.
Si no estaba cargada devuelve nullptr.
*/
sf::Texture* Render::getTexture(std::string texture)
{
    auto it = textures.find(texture);
    if (it != textures.end())
        return it->second;
    
    return nullptr;
}


/*
Carga un sprite con la textura pasada por parametro.
Devuelve el ide en sprite. Devuelve dalse si no existe la textura
y no carga nada.
*/
bool Render::createSprite(Rint &sprite, std::string texture)
{
    if(!loadTexture(texture))
        return false;
    
    Rint id = spritesCont;
    spritesCont++;

    sf::Sprite* s = new sf::Sprite(*getTexture(texture));

    sprites.insert(std::pair<Rint, sf::Sprite*>(id, s));

    sprite = id;

    return true;
}

/*
Carga un sprite con la textura recortada por rectangle pasada por parametro.
Devuelve el id en sprite. Devuelve dalse si no existe la textura
y no carga nada.
*/
bool Render::createSprite(Rint &sprite,  std::string texture, Rrect rectangle)
{
        if(!loadTexture(texture))
        return false;
    
    Rint id = spritesCont;
    spritesCont++;

    sf::Sprite* s = new sf::Sprite(*getTexture(texture), sf::IntRect(rectangle[0], rectangle[1], rectangle[2], rectangle[3]));

    sprites.insert(std::pair<Rint, sf::Sprite*>(id, s));

    sprite = id;

    return true;
}

/*
Devuelve el puntero al sprite identificado en sprite, si no existe devuelve nullptr
*/
sf::Sprite* Render::getSprite(Rint sprite)
{
    auto it = sprites.find(sprite);
    if (it != sprites.end())
        return it->second;
    
    return nullptr;
}

/*
Borra el sprite de la memoria y la libera, devuelve true si el sprite existia
y false si no existia.
*/
bool Render::deleteSprite(Rint sprite)
{
    bool r = false;
    if(sprites.find(sprite)!=sprites.end())
    {
        delete sprites.find(sprite)->second;
        sprites.erase(sprite);
        r=true;
    }

    return r;
}

/*
Dibuja el sprite pasado por parametro.
Devuelve false si no existe.
*/
bool Render::drawSprite(Rint sprite)
{
    bool r = false;
    if(sprites.find(sprite)!=sprites.end())
    {
        window->draw(*sprites.find(sprite)->second);
        
        r=true;
    }

    return r;
}


/*
Dibuja el sprite  pasado por parametro. Si centerd es true coloca el origen en el centro del objeto, sino en el 0,0.
Aplica las transformaciones pasadas en el orden S R T. Justo tras el escalado aplica el escalado global.
*/
bool Render::drawSprite(Rint sprite, Rvect position, float rotation, float scale, bool centered)
{
    if(sprites.find(sprite)==sprites.end())
        return false;


    sf::Sprite* s = sprites.find(sprite)->second;

    if(centered)
    {
        s->setOrigin(s->getLocalBounds().width*.5, s->getLocalBounds().height*.5);
    }else
    {
        s->setOrigin(0.f, 0.f);
    }
    
    s->setScale(sf::Vector2f(scale, scale));
    s->scale(sf::Vector2f(globalScale, globalScale));
    s->setRotation(rotation);
    s->setPosition(sf::Vector2f(position[0], position[1])); 

    window->draw(*s);

    return true;   
}
