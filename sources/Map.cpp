#include "Map.h"

void Map::loadMapInfo()
{
    tinyxml2::XMLDocument document;
    tinyxml2::XMLElement* xmlMap;
    tinyxml2::XMLElement* tilesetImage;
    tinyxml2::XMLElement* layer;



    int tilewidth, tileheight;

    int numLayers = 1;

    int*** gidMap;
    

    /* ===== CARGAR EL TMX CORRESPONDIENTE ===== */
    document.LoadFile("");
    xmlMap = document.FirstChildElement("map");
    /* ========================================= */



    /* ===== EXTRAER LOS DATOS ===== */
    // sacamos los datos del mapa XML a variables para utilizarlos
    xmlMap->QueryIntAttribute("width", &width);
    xmlMap->QueryIntAttribute("height", &height);
    xmlMap->QueryIntAttribute("tilewidth", &tilewidth);
    xmlMap->QueryIntAttribute("tileheight", &tileheight);

    tilesetImage = xmlMap->FirstChildElement("tileset");
    // sacamos la ruta de la textura que se usa para luego cargarla
    std::string textureSource = (std::string)tilesetImage->FirstChildElement("image")->Attribute("source"); 
    layer = xmlMap->FirstChildElement("layer");
    /* ============================= */



    /* ===== CARGA DE TEXTURAS ===== */
    if(!mapTexture.loadFromFile(textureSource)) {
        std::cerr << "Couldn't load the map texture" << std::endl;
        exit(0);
    }
    
    layer = xmlMap->FirstChildElement("layer");
    /* ============================= */
    

    /* ===== SACAMOS EL MAPA DE GIDS ===== */

    // cada gid se corresponde con un sprite de una textura
    // primero inicializamos el gidMap
    gidMap = new int**[numLayers]; // es el número de capas (se supone que solo es una)

    for(int i = 0; i < numLayers; i++) {
        gidMap[i]=new int*[height];
        for(int j = 0; j < height; j++) {
            gidMap[i][j] = new int[width];
        }
    }

    // extraemos los datos para el gidmap
    // esta preparado para ser multicapa por si acaso
    tinyxml2::XMLElement* data;
    // este int sirve para recorrer las capas, de momento se supone que es una sola capa
    int actualLayer = 0;
    while(layer) {
        data = layer->FirstChildElement("data")->FirstChildElement("tile");

        while(data) 
        {
            for(int i = 0; i < height; i++) {
                for(int j = 0; j < width; j++) {
                    data->QueryIntAttribute("gid", &gidMap[actualLayer][i][j]);
                }
            }
        }
        layer = layer->NextSiblingElement("layer");
        actualLayer++;
    }
    /* =================================== */


    
    /* ===== CREAMOS LOS SPRITES ===== */
    // primero incializamos el mapa de sprites
    mapSprite = new sf::Sprite***[numLayers];

    for(int i = 0; i < numLayers; i++) {
        mapSprite[i] = new sf::Sprite**[height];
        for(int j = 0; j < height; j++) {
            mapSprite[i][j] = new sf::Sprite*[width];
            for(int k = 0; k < width; k++) {
                mapSprite[i][j][k] = new sf::Sprite;
            }
        }
    }

    // creamos los sprites de los bloques (es decir, cada bloque es un sprite)
    int cols = mapTexture.getSize().x / tilewidth;
    int rows = mapTexture.getSize().y / tileheight;

    tileSprites = new sf::Sprite[rows*cols];

    int n = 0;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            tileSprites[n].setTexture(mapTexture);
            tileSprites[n].setTextureRect(sf::IntRect(j*tilewidth, i*tileheight, tilewidth, tileheight));
            n++;
        }
    }

    // ahora asignamos cada sprite a su posición correspondiente.

    for(int i = 0; i < numLayers; i++) {
        for(int j = 0; j < height; j++) {
            for(int k = 0; k < width; k++) {
                // TO-DO si no funciona cambiar el "gidMap[i][j][k]-1" y el "if(gid >= 0 && gid < width*height)"
                int gid = gidMap[i][j][k]-1;

                if(gid >= 0 && gid < width*height)
                {
                    mapSprite[i][j][k] = new sf::Sprite(mapTexture, tileSprites[gid].getTextureRect());
                    mapSprite[i][j][k] -> setPosition(k*tilewidth, j*tileheight);
                }
                else 
                {
                    mapSprite[i][j][k] = NULL;
                }
            }
        }
    }

    /* =============================== */

}

void Map::draw()
{
    int numLayers = 1;

    for(int l =  0; l < numLayers; l++) {
        for(int y = 0; y < height; y++) {
            for(int x = 0; x < width; x++) {
                if(mapSprite[l][y][x] != NULL) {
                    // window.draw(*(mapSprite[l][y][x]));
                }
            }
        }
    }
}