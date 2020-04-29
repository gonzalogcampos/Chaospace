#pragma once
//#include <SFML/Graphics.hpp>

namespace sf
{
class Font;
class Text;
class Texture;
class Sprite;
}

class Hud{
    private:
        sf::Font *fuente;
        sf::Text *texto_puntuacion;
        sf::Text *texto_enemigos;
        sf::Text *texto_niveles;
        sf::Texture *textura_vidas;
        sf::Sprite *vida_1;
        sf::Sprite *vida_2;
        sf::Sprite *huevo;

        int puntuacion=0;
        

    public:
        Hud();
        virtual ~Hud();

        void setPuntuacion(int sumar);
        void setSpriteVidas(int i);
        void setLevel();
        void setTextoEnemigos(int enemigos_restantes);


        void update(float elapsedTime); 
};