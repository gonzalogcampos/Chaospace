
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

    vida_1->setPosition(30.f, 80);
    vida_2->setPosition(60.f, 80);

    vida_1->setScale(1.5,1.5);
    vida_2->setScale(1.5,1.5);

    texto_niveles = new sf::Text();
    texto_niveles->setFont(*fuente);
    texto_niveles->setString("Level 1");
    texto_niveles->setPosition((float)568, (float)15);

    huevo = new sf::Sprite(*textura_vidas, sf::IntRect(0, 72, 24, 24));
    huevo->setPosition(575, 80);
    huevo->setScale(1.5,1.5);

    texto_enemigos = new sf::Text();
    texto_enemigos->setFont(*fuente);
    texto_enemigos->setString("x");
    texto_enemigos->setPosition((float)625, (float)80);
}

Hud::~Hud(){}

void Hud::setPuntuacion(int sumar){

    puntuacion = puntuacion+sumar;
    std::string puntuacion_text = std::to_string(puntuacion); 
    texto_puntuacion->setString(puntuacion_text);
}

void Hud::setSpriteVidas(int i){}

void Hud::setLevel(){
    texto_niveles->setString("Level 2");
}

void Hud::setTextoEnemigos(int enemigos_restantes){
    texto_enemigos->setString("x  " + std::to_string(enemigos_restantes));
}


void Hud::update(float elapsedTime){

}


  
