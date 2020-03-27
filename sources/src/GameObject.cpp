
#include "GameObject.h"


GameObject::GameObject(){

}

GameObject::~GameObject(){
    
}

bool GameObject::checkColision(GameObject Object){
    bool collides=false;

    if(colisionBox.getGlobalBounds().intersects(Object.getBounds())){
        collides=true;
    }
    return collides;
}

sf::FloatRect GameObject::getBounds(){
    return colisionBox.getGlobalBounds();
}

sf::Vector2f GameObject::getPosition(){
    return colisionBox.getPosition();
}





