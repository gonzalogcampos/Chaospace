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
Borra toda la memoria reservada
*/
void Render::clearMemory()
{
    //TODO
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
Si no estaba cargada devuelve nullptr
*/
sf::Texture* Render::getTexture(std::string texture)
{
    auto it = textures.find(texture);
    if (it != textures.end())
        return it->second;
    
    return nullptr;
}