#pragma once

namespace sf
{
class Font;
class Text;
class RectangleShape;
}

class Hud{
    private:
        sf::Font *fuente;
        sf::Font *fuente2;
        sf::Text *texto_puntuacion;
        sf::Text *texto_enemigos;
        sf::Text *texto_niveles;
        sf::Text *texto_fps;
        sf::Text *texto_distance;
        sf::RectangleShape *rectangulo_relleno;
        sf::RectangleShape *rectangulo_vida;
        unsigned int sprite_explosion;
       
        int puntuacion=0;
        

    public:
        Hud();
        virtual ~Hud();

        void setPuntuacion(int sumar);
        void setLife(int i);
        void setLevel(int level);
        void setTextNPCs(int kills);
        void setTextDistance(int done, int to_do);


        void update(int puntuacion, int level, int kills, int porcentaje_vida, float distance, float levelDistance, float fpsint);
        void draw();
};