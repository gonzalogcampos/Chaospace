#pragma once

#include <GameObject.h>

class Asteroid : public GameObject {
    public:
        Asteroid(float X, float Y);
        Asteroid(int color, int tam, float X, float Y);
        virtual ~Asteroid();
        void update(float dt);
        void draw();
        float getOrient();
        int getTam();
        int getType();

    private:
        float velRot;
        float velocity;
        int tam;
        int type;
        unsigned int sprites[1][10];
        
};