#pragma once

//External headers
#include <string>
#include <map>
#include <vector>

//Header SFML
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


class Animation
{
    private:
        Rint frames;
        Rint fps;
        float dt;
        Rint drawing;
        std::vector<Rint> sprites;
        

    public:
    Animation(Rint fps);
    ~Animation();
    void addFrame(Rint frame);
    void clear();
    void draw(float dt);
    void draw(float dt, Rvect position, float rotation = 0.f, float scale = 0.f, bool centered = true);
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

        std::map<Rint, Animation*> animations;


        Rint spritesCont = 1;
        Rint animationsCont = 1;

        float shakeTime = 0.f;

        Rvect globalScale = Rvect(1.f, 1.f);
        float dt = 0.f;

        bool enter_pressed=false;
        bool escape_pressed=false;
        bool k_pressed = false;
        sf::Sprite cursorSprite;
        sf::Texture cursor;

        sf::RectangleShape r;
        sf::CircleShape c;

    public:
        static Render* getInstance()
        {
            static Render onlyInstance;
            return &onlyInstance;
        }

        ~Render();

        //System functions

        void init(Rvect size, std::string title);

        void close();

        bool isWindowOpen();

        float getWindowWidth();

        float getWindowHeight();

        void preLoop(float dt);

        void postLoop();

        void clearMemory();

        void setGlobalScale(Rvect scale);

        Rvect getGlobalScale();

        Rvect getCursorPosition();

        void shake();

        Rvect polarToCartesian(float r, float a);

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

        bool drawSprite(Rint sprite, Rvect position, float rotation = 0.f, float scale = 1.f, bool centered = true);

        //Animation functions

        Rint createAnimation(float fps);

        bool addFrameToAnimation(Rint animation, Rint sprite);

        Animation* getAnimation(Rint animation);

        bool deleteAnimation(Rint animation);

        bool clearAnimation(Rint animation);

        bool drawAnimation(Rint animation);

        bool drawAnimation(Rint animation, Rvect position, float rotation = 0.f, float scale = 1.f, bool centered = true);

        //EXTRA 
        void drawText(sf::Text text);
        void drawRectangle(sf::RectangleShape rectangle);
        bool isEnterPressed();
        void setEnterPressed(bool press);
        bool isEscapePressed();
        void setEscapePressed(bool press);
        bool isKPressed();
        void setKPressed(bool press);
        void setMouse(bool mouse);
        void drawCircle(Rvect position, float radious, bool centered = true);
        void drawRectangle(Rvect position, Rvect size, bool centered = true);


};