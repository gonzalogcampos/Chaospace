#pragma once

//Forward declarations
class Physics;

class GameObject{

    public:

        GameObject();

        virtual ~GameObject();

        Physics* getPhysics();

        void setAnimation(unsigned int animation);
        bool checkColision(GameObject* object);
        void update(float dt);       
        

    protected:
        Physics* physics; 
        unsigned int animation;
};
