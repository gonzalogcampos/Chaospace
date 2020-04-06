#include <Physics.h>
#include <cmath>
#include <iostream>

/*
Constructor por defecto.
Situa el objeto en el 0-0, sin velocidad y sin BB
*/
Physics::Physics()
{
    position = Pvect(0.f, 0.f);
    velocity = Pvect(0.f, 0.f);
    dimensions = Pvect(0.f, 0.f);
    type=BoundingBox::NOCOLIDER;
    radious = 1.f;
}

/*
Constructor que setea la posicion en position.
Sin velocidad y son BB
*/
Physics::Physics(Pvect position)
{
    this->position = position;
    velocity = Pvect(0.f, 0.f);
    dimensions = Pvect(0.f, 0.f);


    type=BoundingBox::NOCOLIDER;

    radious = 1.f;
}

/*
Setea la posicion a la pasada por parametro
*/
void Physics::setPosition(Pvect position)
{
    this->position = position;
}

void Physics::addPosition(Pvect position)
{
    this->position = Pvect(this->position.x + position.x, this->position.y + position.y);

}

/*
Devuelve la posicion.
*/
Pvect Physics::getPosition()
{
    return position;
}

/*
Setea la velocidad en cordenadas cartesianas pasada por parametro.
*/
void Physics::setVelocity(Pvect velocity)
{
    this->velocity = velocity;

}

/*
Anade la velocidad cardinal pasada por parametro.
*/
void Physics::addVelocity(Pvect velocity)
{
    this->velocity = Pvect(this->velocity.x + velocity.x, this->velocity.y + velocity.y);
}

/*
Setea la velocidad en coordenadas polares pasada por parametro.
*/
void Physics::setPolarVelocity(float orient, float velocity)
{
    float toRadians = 3.1415926/180;
    this->velocity.x = velocity*cos(orient*toRadians);
    this->velocity.y = velocity*sin(orient*toRadians);
}

/*
Devuelve la velocidad en coordenadas polares (v, theta)
*/
Pvect Physics::getPolarVelocity()
{

    
    std::cout<<"GPV 1\n";
    float v = 1.f;
    float theta = 1.f;
    std::cout<<"Velocity: ";
    std::cout<<this->velocity.x<<" "<<this->velocity.y<<"\n";
    if(velocity.x == 0.f && velocity.y == 0.f)
    {
    std::cout<<"GPV 2\n";

        v = 0.f;
        theta = 0.f;
    }else if(velocity.x == 0.f)
    {
    std::cout<<"GPV 3\n";

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
    std::cout<<"GPV 4\n";

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
    std::cout<<"GPV 5\n";

        float toDegrees = 180/3.1415926;
        v = sqrt(pow(velocity.x, 2) + pow(velocity.y, 2));
        theta = atan(velocity.y/velocity.x)*toDegrees;
    }

    return Pvect(v, theta);
}

/*
Devuelve la velocidad en coordenadas cartesianas.
*/
Pvect Physics::getVelocity()
{
    return this->velocity;
}

/*
Setea la orientacion del objeto en grados siendo (1,0) 0º
*/
void Physics::setOrient(float orient)
{
    this->orient = orient;
}

/*
Devuelve la orientacion del objeto en grados siendo (1,0) 0º
*/
float Physics::getOrient()
{
    return orient;
}


/*
Setea la velocidad maxima del objeto
*/
void Physics::setMaxVelocity(float velocity)
{
    maxVelocity = velocity;
}

/*
Devuelve la velocidadmacima del objeto
*/
float Physics::getMaxVelocity()
{
    return maxVelocity;
}

/*
Setea el BB a un circulo de radio radious centrado en la posicion del objeto.
*/
void Physics::setCircleBB(float radious)
{
    type=BoundingBox::CIRCLE;
    this->radious = radious;
}

/*
Setea el BB a un rectangulo con las dimensiiones pasadas por parameetro centrado en la posicion del objeto.
*/
void Physics::setRectangleBB(Pvect dimensions)
{
    type=BoundingBox::RECTANGLE;
    this->dimensions = dimensions;
}

/*
Hace que el objeto no tengo BB y por tanto no colisione.
*/
void Physics::setNoBB()
{
    type = BoundingBox::NOCOLIDER;
}

/*
Devuelve el tipo de BB (Circular, Rectangular, NoBB).
*/
BoundingBox Physics::getBBType()
{
    return type;
}

/*
Devuelve el radio del BB circular
*/
float Physics::getRadious()
{
    return radious;
}

/*
Devuelve las dimensiones de BB rectangular
*/
Pvect Physics::getDimensions()
{
    return dimensions;
}

/*
Actualiza la posicion del objeto.
*/
void Physics::update(float dt)
{
    std::cout<<"Update Phis 1\n";
    if(getPolarVelocity().x>maxVelocity)
    {
        std::cout<<"Update Phis 2\n";

       setPolarVelocity(maxVelocity, getPolarVelocity().y);
    }

    std::cout<<"Update Phis 3\n";
    this->position.x += this->velocity.x*dt;
    std::cout<<"Update Phis 4\n";

    position.y += velocity.y*dt;
}

/*
Devuelve true si colisiona con el target, false en caso contrario.
*/
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


/*
Por hacer en caso de que queramos que los objetos no se muevan cuando colisionen.
*/
void Physics::moveBack()
{
    //TODO
}