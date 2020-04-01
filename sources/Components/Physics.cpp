#include <Physics.h>
#include <cmath>

Physics::Physics()
{
    position = Pvect(0.f, 0.f);
    velocity = Pvect(0.f, 0.f);
    dimensions = Pvect(0.f, 0.f);
    type=BoundingBox::CIRCLE;
    radious = 1.f;
}

Physics::Physics(Pvect position)
{
    this->position = position;
    velocity = Pvect(0.f, 0.f);
    dimensions = Pvect(0.f, 0.f);


    type=BoundingBox::CIRCLE;

    radious = 1.f;
}

void Physics::setPosition(Pvect position)
{
    this->position = position;
}

Pvect Physics::getPosition()
{
    return position;
}

void Physics::setVelocity(Pvect velocity)
{
    this->velocity = velocity;

}

void Physics::setPolarVelocity(float orient, float velocity)
{
    float toRadians = 3.1415926/180;
    this->velocity.x = velocity*cos(orient*toRadians);
    this->velocity.y = velocity*sin(orient*toRadians);
}

Pvect Physics::getPolarVelocity()
{
    float v , theta;
    if(velocity.x == 0.f && velocity.y == 0.f)
    {
        v = 0.f;
        theta = 0.f;
    }else if(velocity.x == 0.f)
    {
        v = std::abs(velocity.y);
        if(velocity.y < 0)
        {
            theta = 270.f;
        }else
        {
            theta = 90.f;
        }
    }else if(velocity.y == 0.f)
    {
        v = std::abs(velocity.x);
        if(velocity.x < 0)
        {
            theta = 180.f;
        }else
        {
            theta = 0.f;
        }
    }else
    {
        float toDegrees = 180/3.1415926;
        v = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));
        theta = atan(velocity.y/velocity.x)*toDegrees;
    }

    return Pvect(v, theta);
}

Pvect Physics::getVelocity()
{
    return this->velocity;
}

void Physics::setOrient(float orient)
{
    this->orient = orient;
}

float Physics::getOrient()
{
    return orient;
}

void Physics::setCircleBB(float radious)
{
    type=BoundingBox::CIRCLE;
    this->radious = radious;
}

void Physics::setRectangleBB(Pvect dimensions)
{
    type=BoundingBox::RECTANGLE;
    this->dimensions = dimensions;
}
BoundingBox Physics::getBBType()
{
    return type;
}
float Physics::getRadious()
{
    return radious;
}
Pvect Physics::getDimensions()
{
    return dimensions;
}
void Physics::update(float dt)
{
    position.x += velocity.x*dt;
    position.y += velocity.y*dt;
}
bool Physics::colides(Physics* target)
{
    bool ret = false;

    if(!target)
        return false;
    if(target->getBBType()==NOCOLIDER || type==NOCOLIDER)
    {
        ret = false;

    }else if(target->getBBType()==RECTANGLE && type==RECTANGLE)
    {
        float ax = position.x - (dimensions.x/2);
        float ay = position.y - (dimensions.y/2);
        float aw = dimensions.x;
        float ah = dimensions.y;
        float bx = target->getPosition().x - (target->getDimensions().x/2);
        float by = target->getPosition().y - (target->getDimensions().y/2);
        float bw = target->getDimensions().x;
        float bh = target->getDimensions().y;

        if(ax < bx+bw &&
            ax+aw > bx &&
            ay < by+bh &&
            ah+ay > by)
        {
            ret = true;
        }

    }else if ((target->getBBType()==CIRCLE && type==RECTANGLE) || (target->getBBType()==RECTANGLE && type==CIRCLE))
    {
        float cx, cy, cr;
        float rx, ry, rw, rh;

        if(type == RECTANGLE)
        {
            rx = position.x - (dimensions.x/2);
            ry = position.y - (dimensions.y/2);
            rw = dimensions.x;
            rh = dimensions.y;
            cx = target->getPosition().x;
            cy = target->getPosition().y;
            cr = target->getRadious();
        }else
        {
            rx = target->getPosition().x - (target->getDimensions().x/2);
            ry = target->getPosition().y - (target->getDimensions().y/2);
            rw = target->getDimensions().x;
            rh = target->getDimensions().y;
            cx = position.x;
            cy = position.y;
            cr = radious;
        }

        float testX = cx;
        float testY = cy;

        if(cx<rx)           testX = rx;
        else if(cx>rx+rw)   testX = rx+rw;

        if(cy<ry)           testY = ry;
        else if(cy>ry+rh)   testY = ry+rh;

        float distX = cx-testX;
        float distY = cy-testY;
        float distance = sqrt(pow(distX,2) + pow(distY,2));

        if(distance<= cr)
            ret = true;

    }else if(target->getBBType()==CIRCLE && type==CIRCLE)
    {
        float ax = position.x;
        float ay = position.y;
        float ar = radious;
        float bx = target->getPosition().x;
        float by = target->getPosition().y;
        float br = target->getRadious();

        float dx = ax - bx;
        float dy = ay - by;
        float distance = sqrt(pow(dx,2) + pow(dy,2));

        if(distance < ar+br)
            ret = true;
    }

    if(ret)
        moveBack();

    return ret;
}

void Physics::moveBack()
{
    //TODO
}