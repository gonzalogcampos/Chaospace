//Main header
#include <Npc.h>

//Headers
#include <Render.h>
#include <Physics.h>
#include <Map.h>
#include <iostream>
#include "math.h"



/*=================================================*/
/*==================   Values   ===================*/
/*=================================================*/




/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


//Cosntructor por defecto de la clase NPC.
Npc::Npc() 
{

}

Npc::Npc(int IA, float posX, float posY){
    tipo=IA;
    int nivel = Map::getInstance()->getLevel()+1;
    if(nivel>4){
        nivel=nivel%5+1 ;
    }

    rectangulo_relleno = new sf::RectangleShape(sf::Vector2f(102,12));
    rectangulo_relleno->setPosition((float)physics->getPosition().x, (float)physics->getPosition().y);
    rectangulo_relleno->setFillColor(sf::Color::White);

    rectangulo_vida = new sf::RectangleShape(sf::Vector2f(100,10));
    rectangulo_vida->setPosition((float)physics->getPosition().x+1, (float)physics->getPosition().y+1);
    rectangulo_vida->setFillColor(sf::Color::Green);

    switch (tipo)
    {
    case 1:
        setWeaponType(nivel);
        //nave=Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile000.png");
        hp = 1;
        cadencia=10;
        break;
    case 2:
        setWeaponType(nivel);
        //nave=Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile000.png");
        hp = 1;
        cadencia=10;
        break;
    case 3:
        setWeaponType(nivel);
        //nave=Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile000.png");
        hp = 1;
        cadencia=10;
        break;
    case 4:
        setWeaponType(nivel);
        //nave=Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile001.png");
        hp = 1;
        cadencia=10;
        break;
    case 5:
        setWeaponType(nivel);
        //nave=Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile002.png");
        hp = 1;
        cadencia=5;
        break;
    case 6:
        setWeaponType(nivel);
        //nave=Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile003.png");
        hp = 1;
        cadencia=5;
        break;
    case 7:
        setWeaponType(nivel);
        //nave=Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile004.png");
        hp = 1;        
        cadencia=5;
        break;
    case 8:
    //boss
        setWeaponType(nivel);
        hp=100;
        cadencia=10;
        break;
    case 9:
        setWeaponType(5);
        hp=150;
        cadencia=10;
        break;
     case 10:
        setWeaponType(6);
        hp=200;
        cadencia=10;
        break;
    default:
        setWeaponType(nivel);
        //nave=Render::getInstance()->createSprite("resources/naveE.png");
        hp = 1;
        cadencia=10;
        break;
    }
    
    hpmax=hp;
    
    X=posX;
    Y=posY;
        switch (nivel)
        {
        case 1:
        if(tipo<8)
    {
        switch (tipo)
        {
        case 1:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 2:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f, 75.f));
           
            break;
        case 3:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 4:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile001.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 5:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile002.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 6:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile003.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 7:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile004.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
                
        default:
            break;
        }
        
    }
    else
    {
        animation = Render::getInstance()->createAnimation(15);
         if(tipo==10){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/15.png"));
        
        }
        if(tipo==9){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/11.png"));
       
        }
        
        if(tipo==8){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/7.png"));
        
        }
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(220.f,220.f));
    }
            break;
        case 2:
        if(tipo<8)
    {
        switch (tipo)
        {
        case 1:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase2/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 2:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase2/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 3:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase2/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 4:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase2/tile001.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 5:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase2/tile002.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 6:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase2/tile003.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 7:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase2/tile004.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
                
        default:
            break;
        }
        
    }
    else
    {
        animation = Render::getInstance()->createAnimation(15);
          if(tipo==10){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/15.png"));
        
        }
        if(tipo==9){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/11.png"));
       
        }
        
        if(tipo==8){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/7.png"));
        
        }      
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(220.f,220.f));
    }
            break;
        case 3:
        if(tipo<8)
    {
        switch (tipo)
        {
        case 1:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase3/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 2:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase3/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 3:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase3/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 4:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase3/tile001.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 5:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase3/tile002.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 6:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase3/tile003.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 7:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase3/tile004.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
                
        default:
            break;
        }
        
    }
    else
    {
        animation = Render::getInstance()->createAnimation(15);
          if(tipo==10){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/15.png"));
        
        }
        if(tipo==9){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/11.png"));
       
        }
        
        if(tipo==8){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/7.png"));
        
        }
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(220.f,220.f));
    }
            break;
        case 4:
        if(tipo<8)
    {
        switch (tipo)
        {
        case 1:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase4/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 2:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase4/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 3:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase4/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 4:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase4/tile001.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 5:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase4/tile002.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 6:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase4/tile003.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 7:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase4/tile004.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
                
        default:
            break;
        }
        
    }
    else
    {
        animation = Render::getInstance()->createAnimation(15);
        if(tipo==10){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/15.png"));
        
        }
        if(tipo==9){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/11.png"));
       
        }
        
        if(tipo==8){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/7.png"));
        
        }
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(220.f,220.f));
    }
            break;
        
        default:
        if(tipo<8)
    {
        switch (tipo)
        {
        case 1:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 2:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 3:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile000.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 4:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile001.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
           
            break;
        case 5:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile002.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 6:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile003.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
        case 7:
        animation = Render::getInstance()->createAnimation(15);
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/Enemigos/Fase1/tile004.png"));
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(70.f,75.f));
            break;
                
        default:
            break;
        }
        
    }
    else
    {
        
        animation = Render::getInstance()->createAnimation(15);
         if(tipo==10){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/15.png"));
        
        }
        if(tipo==9){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/11.png"));
       
        }
        
        if(tipo==8){
        Render::getInstance()->addFrameToAnimation(animation, Render::getInstance()->createSprite("resources/SPRITES NUESTROS/Bosses/7.png"));
        
        }
        
        physics->setPosition(Pvect(X, Y));
        physics->setOrient(180.f);
        physics->setRectangleBB(Pvect(220.f,220.f));
    
    }
            break;
        }
    

}




Npc::~Npc(){
    float r = random()%100;
    float elegir = random()%4;
    if(r<30 && elegir==1)
    {
        Map::getInstance()->createLife(physics->getPosition().x, physics->getPosition().y);
    }
    if(r<10 && elegir == 0)
    {
        Map::getInstance()->createMaxLife(physics->getPosition().x, physics->getPosition().y);
    }
    if(r<30 && elegir == 2)
    {
        Map::getInstance()->createSpeed(physics->getPosition().x, physics->getPosition().y);
    }  
    if(r<20 && elegir == 3)
    {
        Map::getInstance()->createShield(physics->getPosition().x, physics->getPosition().y);
    }

    delete rectangulo_vida;
    delete rectangulo_relleno;
        
    
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
    switch (tipo)
    {
    case 1:
        Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);
        vx = -200.f;

        if(Y<Map::getInstance()->getPlayerY())
            vy = +100.f;

        if(Y>Map::getInstance()->getPlayerY())
            vy = -100.f;

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
        if(Y<Map::getInstance()->getPlayerY())
            vy = +100.f;

        if(Y>Map::getInstance()->getPlayerY())
            vy = -100.f;

        if(contador==cadencia)
        {
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
        if(contador==cadencia)
        {
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
        if(contador==cadencia)
        {
            Ship::shoot();
            contador=0;
        }
        break;
    case 7:
        vx = -200.f;
        if(Y<Map::getInstance()->getPlayerY())
            vy = +100.f;

        if(Y>Map::getInstance()->getPlayerY())
            vy = -100.f;

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
        
        if(contador==cadencia)
        {
            Ship::shoot();
            contador=0;
        }     

        break;
    case 8: //IA Del boss
    
        
        if(physics->getPosition().x<100)
            vx=1000.f;
        
        if(physics->getPosition().x>1000)
            vx=-100.f;
        
        if(physics->getPosition().x>=100 && physics->getPosition().x<=900)
            vx=20.f;

         if(physics->getPosition().y<100)
             physics->setPosition(Pvect(physics->getPosition().x,720/2));
         
         if(physics->getPosition().y>620)
             physics->setPosition(Pvect(physics->getPosition().x,720/2));
        //Ataque1
          if(Map::getInstance()->getPlayerX()>physics->getPosition().x){
        
             vx=1000.f;
        }
        if(ataqueboss==1)
        {
            movboss++;

            //for(int i=0;i<30;i++){
            if(movboss<30)
            vy = -300.f;

            if(movboss==5 || movboss== 15 || movboss ==25)
                Ship::shoot();
        
            //}
                //for(int i=0;i<30;i++){
            if(movboss<60 && movboss>=30)
            vy = +300.f;

            if(movboss==35 || movboss== 45 || movboss ==55)
                Ship::shoot();
            
            if(movboss>=60)
            {
                movboss=0;
                ataqueboss = rand() % 4 + 1; 
            }
            //}
            contador=0;
            
            
        }

        //Ataque2
        if(ataqueboss==2)
        {
            movboss++;
            //for(int i=0;i<30;i++){
            if(movboss<30)
                vy = +300.f;

            if(movboss==5 || movboss== 15 || movboss ==25)
                Ship::shoot();
            
            //}
                //for(int i=0;i<30;i++){
            if(movboss<60 && movboss>=30)
            vy = -300.f;

            if(movboss==35 || movboss== 45 || movboss ==55)
                Ship::shoot();

            if(movboss>=60)
            {
                movboss=0;
                ataqueboss = rand() % 4 + 1; 
            }
            //}
            contador=0;                                 
        }

        //Ataque3
        if(ataqueboss==3)
        {   
            movboss++;
            if(physics->getPosition().x>=300)
            {
                vx=-300.f;
                if(movboss%2==0)
                    Ship::shoot();

                if(movboss>30)
                {
                    movboss=0;
                    ataqueboss = rand() % 4 + 1; 
                }
            }
            if(movboss>30)
            {
                movboss=0;
                ataqueboss = rand() % 4 + 1; 
            }
        }

        //Ataque4
        if(ataqueboss==4)
        {
            movboss++;
            if(physics->getPosition().x<=700)
            {
                vx=300.f;

                if(movboss%2==0)
                    Ship::shoot();

                if(movboss>30)
                {
                    movboss=0;
                    ataqueboss = rand() % 4 + 1; 
                }

            }
            if(movboss>30)
            {
                movboss=0;
                ataqueboss = rand() % 4 + 1; 
            }
        }

        break;
    



    case 9: //IA Del boss 2
      
        if(physics->getPosition().x<100)
            vx=1000.f;
        
        if(physics->getPosition().x>1000)
            vx=-100.f;
        
        if(physics->getPosition().x>=100 && physics->getPosition().x<=900)
            vx=20.f;

          if(physics->getPosition().y<100)
             physics->setPosition(Pvect(physics->getPosition().x,720/2));
         
         if(physics->getPosition().y>620)
             physics->setPosition(Pvect(physics->getPosition().x,720/2));

          if(Map::getInstance()->getPlayerX()>physics->getPosition().x){
        
             vx=1000.f;
        }
        
        //Ataque1
        if(ataqueboss==1)
        {
            movboss++;

            //for(int i=0;i<30;i++){
            if(movboss<30)
            vy = -300.f;

            if(movboss==5 || movboss==10 || movboss== 15 ||movboss==20 || movboss ==25){
               
                Ship::shoot();
        }
            //}
                //for(int i=0;i<30;i++){
            if(movboss<60 && movboss>=30)
            vy = +300.f;

            if(movboss==35 || movboss== 45 || movboss ==55 || movboss==40 || movboss== 50 || movboss ==59){
               
                Ship::shoot();
            }
            if(movboss>=60)
            {
                movboss=0;
                ataqueboss = rand() % 5 + 1; 
            }
            //}
            contador=0;
            
            
        }

        //Ataque2
        if(ataqueboss==2)
        {
            movboss++;
            //for(int i=0;i<30;i++){
            if(movboss<30)
                vy = +300.f;

            if(movboss==5 || movboss==10 || movboss== 15 ||movboss==20 || movboss ==25){
                
                Ship::shoot();
            }
            //}
                //for(int i=0;i<30;i++){
            if(movboss<60 && movboss>=30)
            vy = -300.f;

            if(movboss==35 || movboss== 45 || movboss ==55 || movboss==40 || movboss== 50 || movboss ==59){
                
                Ship::shoot();
                
            }

            if(movboss>=60)
            {
                movboss=0;
                ataqueboss = rand() % 5 + 1; 
            }
            //}
            contador=0;                                 
        }

        //Ataque3
        if(ataqueboss==3)
        {   
            movboss++;
            if(physics->getPosition().x>=300)
            {
                vx=-300.f;
                if(movboss%2==0){
                    
                    Ship::shoot();
                    

                }

                if(movboss>30)
                {
                    movboss=0;
                    ataqueboss = rand() % 5 + 1; 
                }
            }
            if(movboss>30)
            {
                movboss=0;
                ataqueboss = rand() % 5 + 1; 
            }
        }

        //Ataque4
        if(ataqueboss==4)
        {
            movboss++;
            if(physics->getPosition().x<=700)
            {
                vx=300.f;

                if(movboss%2==0){
                    
                    Ship::shoot();
                }

                if(movboss>30)
                {
                    movboss=0;
                    ataqueboss = rand() % 5 + 1; 
                }

            }
            if(movboss>30)
            {
                movboss=0;
                ataqueboss = rand() % 5 + 1; 
            }
        }
        //Ataque5
         if(ataqueboss==5){
             movboss++;
             Ship::shoot();
             if(Map::getInstance()->getPlayerY()>physics->getPosition().y)
             vy=+200.f;
         }
         if(Map::getInstance()->getPlayerY()<=physics->getPosition().y)
             vy=-200.f;
         if(contador>60){
              ataqueboss = rand() % 5 + 1;
         }
        break;

     case 10: //IA Del boss 3
     
        if(physics->getPosition().x<100)
            vx=1000.f;
        
        if(physics->getPosition().x>1000)
            vx=-100.f;
        
        if(physics->getPosition().x>=100 && physics->getPosition().x<=900)
            vx=20.f;

          if(physics->getPosition().y<100)
             physics->setPosition(Pvect(physics->getPosition().x,720/2));
         
         if(physics->getPosition().y>620)
             physics->setPosition(Pvect(physics->getPosition().x,720/2));

           if(Map::getInstance()->getPlayerX()>physics->getPosition().x){
        
             vx=1000.f;
        }
        
        //Ataque1
        if(ataqueboss==1)
        {
            movboss++;

            //for(int i=0;i<30;i++){
            if(movboss<30)
            vy = -400.f;

            if(movboss==5 || movboss==10 || movboss== 15 ||movboss==20 || movboss ==25){
               
                Ship::shoot();
        }
            //}
                //for(int i=0;i<30;i++){
            if(movboss<60 && movboss>=30)
            vy = +300.f;

            if(movboss==35 || movboss== 45 || movboss ==55 || movboss==40 || movboss== 50 || movboss ==59){
               
                Ship::shoot();
            }
            if(movboss>=60)
            {
                movboss=0;
                ataqueboss = rand() % 5 + 1; 
            }
            //}
            contador=0;
            
            
        }

        //Ataque2
        if(ataqueboss==2)
        {
            movboss++;
            //for(int i=0;i<30;i++){
            if(movboss<30)
                vy = +400.f;

            if(movboss==5 || movboss==10 || movboss== 15 ||movboss==20 || movboss ==25){
                
                Ship::shoot();
            }
            //}
                //for(int i=0;i<30;i++){
            if(movboss<60 && movboss>=30)
            vy = -400.f;

            if(movboss==35 || movboss== 45 || movboss ==55 || movboss==40 || movboss== 50 || movboss ==59){
                
                Ship::shoot();
                
            }

            if(movboss>=60)
            {
                movboss=0;
                ataqueboss = rand() % 5 + 1; 
            }
            //}
            contador=0;                                 
        }

        //Ataque3
        if(ataqueboss==3)
        {   
            movboss++;
            if(physics->getPosition().x>=300)
            {
                vx=-300.f;
                if(movboss%2==0){
                    
                    Ship::shoot();
                    

                }

                if(movboss>30)
                {
                    movboss=0;
                    ataqueboss = rand() % 5 + 1; 
                }
            }
            if(movboss>30)
            {
                movboss=0;
                ataqueboss = rand() % 5 + 1; 
            }
        }

        //Ataque4
        if(ataqueboss==4)
        {
            movboss++;
            if(physics->getPosition().x<=700)
            {
                vx=400.f;

                if(movboss%2==0){
                    
                    Ship::shoot();
                }

                if(movboss>30)
                {
                    movboss=0;
                    ataqueboss = rand() % 5 + 1; 
                }

            }
            if(movboss>30)
            {
                movboss=0;
                ataqueboss = rand() % 5 + 1; 
            }
        }
        //Ataque5
         if(ataqueboss==5){
             movboss++;
             Ship::shoot();
             if(Map::getInstance()->getPlayerY()>physics->getPosition().y)
             vy=+300.f;
         }
         if(Map::getInstance()->getPlayerY()<=physics->getPosition().y)
             vy=-300.f;
         if(contador>60){
              ataqueboss = rand() % 5 + 1;
         }
        break;

    default:
        break;
    }

    physics->setVelocity(Pvect(vx, vy));

    setLife();
    Ship::update(dt);
}

void Npc::draw(){
    Ship::draw();
    if(tipo==8 || tipo==9 || tipo==10){
        Render::getInstance()->drawRectangle(*rectangulo_relleno);
        Render::getInstance()->drawRectangle(*rectangulo_vida);
    }
}

void Npc::setLife()
{

    float porcentaje = ((float)Ship::getHp()/(float)hpmax)*100;
    rectangulo_vida->setSize(sf::Vector2f((float)porcentaje,10));

    if(porcentaje>=70){
        rectangulo_vida->setFillColor(sf::Color::Green);
    }else if(porcentaje<70 && porcentaje>=30){
        rectangulo_vida->setFillColor(sf::Color::Yellow);
    }else if(porcentaje>0 && porcentaje<30){
        rectangulo_vida->setFillColor(sf::Color::Red);
    }

    rectangulo_relleno->setPosition((float)physics->getPosition().x-45, (float)physics->getPosition().y-120);
    rectangulo_vida->setPosition((float)physics->getPosition().x-44, (float)physics->getPosition().y-119);

}
