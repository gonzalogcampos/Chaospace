#pragma once

#include <GameObject.h>

class Asteroid : public GameObject {
    public:
        Asteroid(float X, float Y);
        Asteroid(int color, int tam, float X, float Y, float orientation);
        virtual ~Asteroid();
        void update(float dt);
        void draw();
        float getOrient();
        int getSize();
        int getType();

    private:
        float velRot;
        float velocity;
        int size;
        int type;
};