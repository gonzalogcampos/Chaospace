#include <SFML/Graphics.hpp>

class Physics;

class GameObject{

    public:

        GameObject();
        virtual ~GameObject();

        Physics* getPhysics();

        void setAnimation(unsigned int animation);
        bool checkColision(GameObject* object); // Method that checks if a GameObject collides with another GameObject
        void update(float dt);

        //OBSOLETO
        //sf::FloatRect getBounds(); // Method to obtain the global bounds of the hitbox
        //sf::Vector2f getPosition();// Method that returns the actual position of the colisionBox
        //void draw(sf::RenderWindow &window); // Draw method 
        
        

    protected:
        Physics* physics;
        unsigned int animation;


        //OBSOLETO
        //sf::Sprite sprite;
        //sf::Texture textura;
        //sf::RectangleShape colisionBox;

};
