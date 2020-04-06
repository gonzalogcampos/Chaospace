
#include <GameObject.h>
#include <Physics.h>
#include <Render.h>

GameObject::GameObject()
{
    physics = new Physics();
}

GameObject::~GameObject()
{
    delete physics;
    Render::getInstance()->deleteAnimation(animation);
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
    physics->update(dt);

    Render::getInstance()->drawAnimation(animation, 
                                            Rvect(physics->getPosition().x, physics->getPosition().y),
                                            physics->getOrient());  

}
