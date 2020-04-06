
#include "Npc.h"
#include <Render.h>
#include <Physics.h>
#include <Map.h>
#include <iostream>

 
    Npc::Npc() {} //Cosntructor por defecto de la clase Player.
    
    Npc::Npc(int IA, float posX, float posY){
        tipo=IA;
        switch (tipo)
        {
        case 1:
            //nave=Render::getInstance()->createSprite("resources/naveE.png");
            cadencia=10;
            break;
        case 2:
            //nave=Render::getInstance()->createSprite("resources/naveE.png");
            cadencia=10;
            break;
        case 3:
            //nave=Render::getInstance()->createSprite("resources/naveE.png");
            cadencia=10;
            break;
        case 4:
            //nave=Render::getInstance()->createSprite("resources/naveE.png");
            cadencia=10;
            break;
        case 5:
            //nave=Render::getInstance()->createSprite("resources/naveE.png");
            cadencia=5;
            break;
        case 6:
            //nave=Render::getInstance()->createSprite("resources/naveE.png");
            cadencia=5;
            break;
          case 7:
            //nave=Render::getInstance()->createSprite("resources/naveE.png");
            cadencia=5;
            break;
        
        default:
            //nave=Render::getInstance()->createSprite("resources/naveE.png");
            cadencia=10;
            break;
        }
        

        
        X=posX;
        Y=posY;
        
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/naveE.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);

        physics->setRectangleBB(Pvect(123.f,115.f));


    }
    
    
    

    Npc::~Npc(){

    } //Metodo destructor de la clase NPC.

    void Npc::IA(int tipo){

    }

    void Npc::enemigo1(){}
    void Npc::enemigo2(){}
    void Npc::enemigo3(){}
    void Npc::enemigo4(){}
    void Npc::enemigo5(){}
    void Npc::enemigo6(){}


    void Npc::update(float dt){
        float vx = 0.f;
        float vy = 0.f;
        contador++;
        Render::getInstance()->drawSprite(nave);
        float dx = Map::getInstance()->getPlayerX()-physics->getPosition().x;
        float dy = Map::getInstance()->getPlayerY()-physics->getPosition().y;
        //std::cout<<"x:"<<dx<<" y:"<<dy<<std::endl;
        switch (tipo)
        {
        case 1:
            Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);
            vx = -200.f;
            if(Y<Map::getInstance()->getPlayerY()){
                             vy = +100.f;

            }
            if(Y>Map::getInstance()->getPlayerY()){
                              vy = -100.f;

            }
            break;
        case 2:
            /*Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);        
            X=X-0.1;
            Y=Y+0.02;*/
            vx = -200.f;
            vy = -100.f;

            break;
         case 3:
            /*Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);        
            X=X-0.1;
            Y=Y-0.02;*/
            vx = -200.f;
            vy = +100.f;
            break;
        case 4:
            /*Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);
            X=X-0.1;*/
            vx = -200.f;
            if(Y<Map::getInstance()->getPlayerY()){
                             vy = +100.f;

            }
            if(Y>Map::getInstance()->getPlayerY()){
                              vy = -100.f;

            }
            //std::cout<<"Entro2"<<std::endl;
            if(contador==cadencia){
             //std::cout<<"Entro"<<std::endl;
               Ship::shoot();
               contador=0;
              }
            break;
        case 5:
            /*Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);        
            X=X-0.1;
            Y=Y+0.1;*/
             vx = -200.f;
             vy = -100.f;
            if(contador==cadencia){
                Ship::shoot();
                contador=0;
              }
            break;
         case 6:
            /*Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);        
            X=X-0.1;
            Y=Y-0.02;*/
            vx = -200.f;
            vy = +100.f;
             if(contador==cadencia){
                Ship::shoot();
                contador=0;
              }
            break;
        case 7:
         vx = -200.f;
            if(Y<Map::getInstance()->getPlayerY()){
                             vy = +100.f;

            }
            if(Y>Map::getInstance()->getPlayerY()){
                              vy = -100.f;

            }
            //calcular angulo hacia el player
            float theta;
    if(dx == 0.f && dy == 0.f)
    {
        theta = 0.f;
    }else if(dx == 0.f)
    {
        if(dy < 0)
        {
            theta = 270.f;
        }else
        {
            theta = 90.f;
        }
    }else if(dy == 0.f)
    {
        if(dx < 0)
        {
            theta = 180.f;
        }else
        {
            theta = 0.f;
        }
    }else
    {
        float toDegrees = 180/3.1415926;
        theta = atan(dy/dx)*toDegrees;
        if(dx<0)
            theta+=180;
    }
    physics->setOrient(theta);
    

    //physics->setOrient(180.f);

            if(contador==cadencia){
            
               Ship::shoot();
               contador=0;
              }     

            break;

        default:
            break;
        }
        physics->setVelocity(Pvect(vx, vy));
        if(X<-20){
            delete this;
        }
        Ship::update(dt);
        /*
        for(unsigned i = 0; i < Bullets.size(); i++) {
        // borrar las balas al salir del mapa
        if(Bullets.at(i)->getPositionBala().x > 800 || Bullets.at(i)->getPositionBala().x < 0 ) {
            // destruyo la bala
            delete Bullets.at(i);
            Bullets.erase(Bullets.begin()+i);

        } else if(Bullets.at(i)->getPositionBala().y > 720 || Bullets.at(i)->getPositionBala().y < 0 ) {
            // destruyo la bala
            delete Bullets.at(i);
            Bullets.erase(Bullets.begin()+i);
        
        } else {
            // LLamar al update de la bala
            Bullets.at(i)->update();
        }
    }*/
    }