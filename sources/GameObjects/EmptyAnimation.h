#pragma once
#include <GameObject.h>


class EmptyAnimation : public GameObject
{
    private:
        float time;
        bool kill = false;

    public:
        enum Type{EXPLOSION};
        EmptyAnimation(float x, float y, float orient, Type type);
        ~EmptyAnimation();
        void update(float dt);
        bool getKill();
};