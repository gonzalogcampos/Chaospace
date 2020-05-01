#pragma once

#include <GameObject.h>

class Asteroid : public GameObject {
    public:
        Asteroid(float X, float Y);
        virtual ~Asteroid();
        void update(float dt);

    private:
        float velRot;
};