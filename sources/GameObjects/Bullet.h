#pragma once

//Headers
#include <GameObject.h>

class Bullet : public GameObject
{
    private:
        int type;
        bool fromPlayer;
    public:
        Bullet(float x, float y, float v, float dir, int type, bool fromPlayer);
        ~Bullet();
        bool isFromPlayer();
};