#pragma once

//Headers
#include <GameObject.h>

class Bullet : public GameObject
{
    private:
        int type;
    public:
        Bullet(float x, float y, float v, float dir, int type);
        ~Bullet();
};