#pragma once
#include <GameObject.h>

enum PowerUpType
{
    LIFE,
    WEAPON1,
    WEAPON2,
    WEAPON3,
    WEAPON4,
    WEAPON5,
    VELDIS
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

