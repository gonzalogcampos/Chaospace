#pragma once
#include <GameObject.h>

enum PowerUpType
{
    LIFE,
    MAX_LIFE,
    WEAPON1,
    WEAPON2,
    WEAPON3,
    WEAPON4,
    WEAPON5,
    VELDIS,
    SHIELD
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

