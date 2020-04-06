
#include <GameObject.h>
#include <Physics.h>
#include <Render.h>
#include <iostream>

GameObject::GameObject()
{
    physics = new Physics();
}

GameObject::~GameObject()
{
    delete physics;
}

Physics* GameObject::getPhysics()
{
    return physics;
}

void GameObject::setAnimation(unsigned int animation)
{
    this->animation = animation;
}


bool GameObject::checkColision(GameObject* object)
{
    if(!object)
        return false;

    return physics->colides(object->getPhysics());
}

void GameObject::update(float dt)
{
    std::cout<<"Update GO1\n";
    physics->update(dt);
    std::cout<<"Update GO2\n";

    Render::getInstance()->drawAnimation(animation, 
                                            Rvect(physics->getPosition().x, physics->getPosition().y),
                                            physics->getOrient());  
    std::cout<<"Update GO3\n";

}






/*

OBSOLETO

*/

/*
sf::FloatRect GameObject::getBounds()
{
    return colisionBox.getGlobalBounds();
}

sf::Vector2f GameObject::getPosition()
{
    return colisionBox.getPosition();
}

void GameObject::draw(sf::RenderWindow& window) 
{
    window.draw(sprite);
}
*/