#pragma once

enum BoundingBox
{
    NOCOLIDER,
    CIRCLE,
    RECTANGLE
};
struct Pvect
{
    float x;
    float y;
    Pvect(){this->x = 0.f; this->y = 0.f;}
    Pvect(float x,float y){this->x = x; this->y = y;}
};
class Physics
{
    private:

        Pvect position;
        float orient;
        Pvect velocity;

        BoundingBox type;

        Pvect dimensions;
        float radious;

        float maxVelocity = 10000.f;

    public:

        /*
        Constructores y destructores
        */
        Physics();
        Physics(Pvect position);

        /*
        Getters & Setters
        */
        void setPosition(Pvect position);
        void addPosition(Pvect position);
        Pvect getPosition();

        void setVelocity(Pvect velocity);
        void addVelocity(Pvect velocity);
        void setPolarVelocity(float orient, float velocity);
        Pvect getPolarVelocity();
        Pvect getVelocity();

        void setOrient(float orient);
        float getOrient();

        void setMaxVelocity(float velocity);
        float getMaxVelocity();

        /*
        Funciones relativas al bb
        */
        void setCircleBB(float radious);
        void setRectangleBB(Pvect dimensions);
        void setNoBB();
        BoundingBox getBBType();
        float getRadious();
        Pvect getDimensions();

        /*
        Funciones relativas al sistema
        */
        void update(float dt);

        bool colides(Physics* target);

        void moveBack();
};