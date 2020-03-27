#include <SFML/Graphics.hpp>

class GameObject{

    public:

        GameObject();
        virtual ~GameObject();
        bool checkColision(GameObject object);
        sf::FloatRect getBounds();
        void draw(sf::RenderWindow &window);
        void update();
        sf::Vector2f getPosition();
        
        

    protected:
    
        sf::Sprite sprite;
        sf::Texture textura;
        sf::RectangleShape colisionBox;






};
