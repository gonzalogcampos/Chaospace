#pragma once
#include <SFML/Graphics.hpp>

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
        sf::RectangleShape *rectangulo_relleno;
        sf::RectangleShape *rectangulo_vida;
       
        int puntuacion=0;
        

    public:
        Hud();
        virtual ~Hud();

        void setPuntuacion(int sumar);
        void setLife(int i);
        void setLevel(int level);
        void setTextNPCs(int npcs_vivos);


        void update(int puntuacion, int level, int npc_vivos, int porcentaje_vida); 
};