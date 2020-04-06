#pragma once

class Physics;

class GameObject{

    public:

        GameObject();
        virtual ~GameObject();

        Physics* getPhysics();

        void setAnimation(unsigned int animation);
        bool checkColision(GameObject* object); // Method that checks if a GameObject collides with another GameObject
        void update(float dt);       
        

    protected:
        Physics* physics; 
        unsigned int animation;
};
