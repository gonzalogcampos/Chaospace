#include <string>
#include "Hud.h"
#include <Render.h>


Hud::Hud(){
    fuente = new sf::Font();
    fuente->loadFromFile("resources/Minecrafter.Reg.ttf");
    
    texto_puntuacion = new sf::Text();
    texto_puntuacion->setFont(*fuente);
    puntuacion=0;
    texto_puntuacion->setString("0");
    texto_puntuacion->setPosition((float)30, (float)15);

    texto_niveles = new sf::Text();
    texto_niveles->setFont(*fuente);
    texto_niveles->setString("Level 1");
    texto_niveles->setPosition((float)568, (float)15);

    texto_enemigos = new sf::Text();
    texto_enemigos->setFont(*fuente);
    texto_enemigos->setString("x");
    texto_enemigos->setPosition((float)625, (float)80);

    rectangulo_relleno = new sf::RectangleShape(sf::Vector2f(100,64));
    rectangulo_relleno->setPosition((float)40, (float)40);
    rectangulo_relleno->setFillColor(sf::Color::Black);

    rectangulo_vida = new sf::RectangleShape(sf::Vector2f(100,64));
    rectangulo_vida->setPosition((float)40, (float)40);
    rectangulo_vida->setFillColor(sf::Color::Green);
}

Hud::~Hud(){}

void Hud::setPuntuacion(int sumar)
{

    puntuacion = sumar;
    std::string puntuacion_text = std::to_string(puntuacion); 
    texto_puntuacion->setString(puntuacion_text);
    Render::getInstance()->drawText(*texto_puntuacion);
    
}

void Hud::setLife(int i)
{

    rectangulo_vida->setSize(sf::Vector2f((float)i,64));

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

void Hud::setTextNPCs(int npcs_vivos)
{
    texto_enemigos->setString("x  " + std::to_string(npcs_vivos));
}


void Hud::update(int puntuacion, int level, int npc_vivos, int porcentaje_vida, float distance, float levelDistance, float fps)
{

    setLevel(level);
    setPuntuacion(puntuacion);
    setTextNPCs(npc_vivos);
    setLife(porcentaje_vida);
}

void Hud::draw()
{
    Render::getInstance()->drawText(*texto_puntuacion);
    Render::getInstance()->drawRectangle(*rectangulo_vida);
    Render::getInstance()->drawText(*texto_niveles);
    Render::getInstance()->drawText(*texto_enemigos);
}

  
