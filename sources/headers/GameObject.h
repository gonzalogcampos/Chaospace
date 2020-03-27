#include <SFML/Graphics.hpp>

class GameObject{

    public:

        GameObject();
        virtual ~GameObject();

        bool checkColision(GameObject object); // Method that checks if a GameObject collides with another GameObject
        sf::FloatRect getBounds(); // Method to obtain the global bounds of the hitbox
        void update();
        sf::Vector2f getPosition();// Method that returns the actual position of the colisionBox
        void draw(sf::RenderWindow &window); // Draw method 
        
        

    protected:
    
        sf::Sprite sprite;
        sf::Texture textura;
        sf::RectangleShape colisionBox;

};
