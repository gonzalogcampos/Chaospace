#pragma once
#include <string>
#include <map>

//Cabecera de SFML
#include <SFML/Graphics.hpp>


/*
    Variables predefinidas para gestionar funciones del render
*/
typedef unsigned int Rint;
struct Rrect
{
    int x;
    int y;
    int w;
    int h;
    Rrect(int x, int y, int w, int h){this->x = x; this->y = y;this->w = w; this->h = h;}
};
struct Rvect
{
    float x;
    float y;
    Rvect(float x,float y){this->x = x; this->y = y;}
};


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

        Rint spritesCont = 1;

        float globalScale;

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

        void setGlobalScale(float scale);

        float getGlobalScale();

        //Textures function

        bool loadTexture(std::string texture);

        bool deleteTexture(std::string texture);

        sf::Texture* getTexture(std::string texture);

        //Sprites functions

        Rint createSprite(std::string texture);

        Rint createSprite(std::string texture, Rrect rectangle);

        sf::Sprite* getSprite(Rint sprite);

        bool deleteSprite(Rint sprite);

        bool drawSprite(Rint sprite);

        bool drawSprite(Rint sprite, Rvect position, float rotation = 0.f, float scale = 0.f, bool centered = true);


};