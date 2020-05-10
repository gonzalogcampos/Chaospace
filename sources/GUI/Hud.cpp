#include <string>
#include "Hud.h"
#include <Render.h>


Hud::Hud(){
    fuente = new sf::Font();
    fuente->loadFromFile("resources/Minecrafter.Reg.ttf");

    fuente2 = new sf::Font();
    fuente2->loadFromFile("resources/Long_Shot.ttf");

    sprite_explosion = Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Animacion explosion/Explosion.png", Rrect((float)30,(float)251, (float)130, (float)130));
    
    texto_puntuacion = new sf::Text();
    texto_puntuacion->setFont(*fuente);
    puntuacion=0;
    texto_puntuacion->setString("SCORE 0");
    texto_puntuacion->setPosition((float)350, (float)15);

    texto_niveles = new sf::Text();
    texto_niveles->setFont(*fuente);
    texto_niveles->setString("Level 1");
    texto_niveles->setPosition((float)660, (float)15);

    texto_enemigos = new sf::Text();
    texto_enemigos->setFont(*fuente);
    texto_enemigos->setString("x");
    texto_enemigos->setPosition((float)965, (float)15);

    texto_fps = new sf::Text();
    texto_fps->setFont(*fuente2);
    texto_fps->setString("FPS");
    texto_fps->setPosition((float)995, (float)130);
    texto_fps->setCharacterSize(17);

    texto_distance = new sf::Text();
    texto_distance->setFont(*fuente2);
    texto_distance->setString("0/0 km");
    texto_distance->setPosition((float)940, (float)75);
    texto_distance->setCharacterSize(25);

    rectangulo_relleno = new sf::RectangleShape(sf::Vector2f(202,12));
    rectangulo_relleno->setPosition((float)30, (float)20);
    rectangulo_relleno->setFillColor(sf::Color::White);

    rectangulo_vida = new sf::RectangleShape(sf::Vector2f(200,10));
    rectangulo_vida->setPosition((float)31, (float)21);
    rectangulo_vida->setFillColor(sf::Color::Green);

}

Hud::~Hud(){
    delete fuente;
    delete fuente2;
    delete texto_distance;
    delete texto_enemigos;
    delete texto_niveles;
    delete texto_fps;
    delete texto_puntuacion;
    delete rectangulo_relleno;
    delete rectangulo_vida;
}

void Hud::setPuntuacion(int sumar)
{

    puntuacion = sumar;
    std::string puntuacion_text = "SCORE " + std::to_string(puntuacion); 
    texto_puntuacion->setString(puntuacion_text);
    Render::getInstance()->drawText(*texto_puntuacion);
    
}

void Hud::setLife(int i)
{

    rectangulo_vida->setSize(sf::Vector2f((float)i*2,10));

    if(i>=70){
        rectangulo_vida->setFillColor(sf::Color::Green);
    }else if(i<70 && i>=30){
        rectangulo_vida->setFillColor(sf::Color::Yellow);
    }else if(i>0 && i<30){
        rectangulo_vida->setFillColor(sf::Color::Red);
    }

}

void Hud::setLevel(int level)
{
    texto_niveles->setString("Level " + std::to_string(level));
}

void Hud::setTextNPCs(int kills)
{
    texto_enemigos->setString("x " + std::to_string(kills));
}

void Hud::setTextDistance(int done, int to_do){
    
    std::string puntuacion_text = std::to_string(done) + "/" + std::to_string(to_do) + " km"; 
    texto_distance->setString(puntuacion_text);
}


void Hud::update(int puntuacion, int level, int kills, int porcentaje_vida, float distance, float levelDistance, float fps, int object)
{

    setLevel(level);
    setPuntuacion(puntuacion);
    setTextNPCs(kills);
    setLife(porcentaje_vida);
    texto_fps->setString("FPS: " + std::to_string((int)fps));
    setTextDistance(distance, levelDistance);

}

void Hud::draw()
{
    Render::getInstance()->drawText(*texto_puntuacion);
    Render::getInstance()->drawRectangle(*rectangulo_relleno);
    Render::getInstance()->drawRectangle(*rectangulo_vida);   
    Render::getInstance()->drawText(*texto_niveles);
    Render::getInstance()->drawText(*texto_enemigos);
    Render::getInstance()->drawText(*texto_fps);
    Render::getInstance()->drawText(*texto_distance);
    Render::getInstance()->drawSprite(sprite_explosion, Rvect(911,11), 0.f, 0.37, false);
}

  
