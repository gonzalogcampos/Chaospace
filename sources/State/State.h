#pragma once 


class State
{
public:

    enum stateType {
        PLAY,
        TEST,
        MENUINICIAL,
        MENUFINAL
    };

    virtual ~State() {};
    virtual void initState() = 0;
    virtual void update(float dt) = 0;
    virtual void clear() = 0; 
    stateType type;
};