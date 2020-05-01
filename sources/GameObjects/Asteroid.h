#pragma once

#include <GameObject.h>

class Asteroid : public GameObject {
    public:
        Asteroid();
        virtual ~Asteroid();
        void update(float dt);

    private:
        float velRot;
};