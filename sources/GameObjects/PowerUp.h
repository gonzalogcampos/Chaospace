#pragma once
#include <GameObject.h>

enum PowerUpType
{
    LIFE,
    WEAPON1
};

class PowerUp : public GameObject
{
    public:

        PowerUp(PowerUpType t, float x, float y);
        ~PowerUp();
        


        PowerUpType getType();

    private:
        PowerUpType t;
};

