#pragma once
#include <string>
#include <map>

//Cabecera de SFML
#include <SFML/Graphics.hpp>


/*
    Variables predefinidas para gestionar funciones del render
*/
typedef unsigned int Rint;
typedef int Rrect[4];
typedef int Rvect[2];


/*
    Clase Render singleton
*/
class Render
{
    private:
        Render(){};
        sf::RenderWindow* window;
        std::map<std::string, sf::Texture*> textures;
        std::map<Rint, sf::Sprite*> sprites;

    public:
        static Render* getInstance()
        {
            static Render onlyInstance;
            return &onlyInstance;
        }

        ~Render();

        //System functions

        void init();

        void close();

        bool isWindowOpen();

        void preLoop();

        void postLoop();

        void clearMemory();

        //Textures function

        bool loadTexture(std::string texture);

        bool deleteTexture(std::string texture);

        sf::Texture* getTexture(std::string texture);

        //Sprites functions

        bool createSprite(Rint &sprite,  std::string texture);

        bool createSprite(Rint &sprite,  std::string texture, Rrect rectangle);

        sf::Sprite* getSprite(Rint sprite);

        bool deleteSprite(Rint sprite);

        bool drawSprite(Rint sprite);

        bool drawSprite(Rint sprite, Rvect position, float rotation = 0.f, float scale = 0.f);


};