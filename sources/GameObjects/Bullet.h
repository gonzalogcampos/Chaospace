#pragma once

//Headers
#include <GameObject.h>


class Bullet : public GameObject
{
    private:
        bool fromPlayer;
        int force;
    public:
        Bullet(float x, float y, float dir, int type, bool fromPlayer);
        ~Bullet();
        bool isFromPlayer();
        int getForce();
};