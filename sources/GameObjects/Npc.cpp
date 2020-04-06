
 #include "Npc.h"

 
    Npc::Npc() {} //Cosntructor por defecto de la clase Player.
    
    Npc::Npc(int IA, int posX, int posY){
        tipo=IA;
        switch (tipo)
        {
        case 1:
            nave=Render::getInstance()->createSprite("resources/naveE.png");
            break;
        case 2:
            nave=Render::getInstance()->createSprite("resources/naveE.png");
            break;
        case 3:
            nave=Render::getInstance()->createSprite("resources/naveE.png");
            break;
        case 4:
            nave=Render::getInstance()->createSprite("resources/naveE.png");
            break;
        case 5:
            nave=Render::getInstance()->createSprite("resources/naveE.png");
            break;
        case 6:
            nave=Render::getInstance()->createSprite("resources/naveE.png");
            break;
        
        default:
            nave=Render::getInstance()->createSprite("resources/naveE.png");
            break;
        }
        
        X=posX;
        Y=posY;
    }
    
    
    

    Npc::~Npc(){

    } //Metodo destructor de la clase Player.

    void Npc::IA(int tipo){

    }

    void Npc::enemigo1(){}
    void Npc::enemigo2(){}
    void Npc::enemigo3(){}
    void Npc::enemigo4(){}
    void Npc::enemigo5(){}
    void Npc::enemigo6(){}


    void Npc::Update(){
        contador++;
        Render::getInstance()->drawSprite(nave);
        switch (tipo)
        {
        case 1:
            Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);
            X=X-0.1;
            break;
        case 2:
            Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);        
            X=X-0.1;
            Y=Y+0.02;
            break;
         case 3:
            Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);        
            X=X-0.1;
            Y=Y-0.02;
            break;
        case 4:
            Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);
            X=X-0.1;
            if(contador==20){
                sf::Vector2f pos_bala = sf::Vector2f(X-20,Y-4);
                Bullet * nueva = new Bullet(pos_bala);
                Bullets.push_back(nueva);
              }
            break;
        case 5:
            Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);        
            X=X-0.1;
            Y=Y+0.02;
            if(contador==20){
                sf::Vector2f pos_bala = sf::Vector2f(X-20,Y-4);
                Bullet * nueva = new Bullet(pos_bala);
                Bullets.push_back(nueva);
              }
            break;
         case 6:
            Render::getInstance()->drawSprite(nave, Rvect(X,Y), 0.f, 0.f, true);        
            X=X-0.1;
            Y=Y-0.02;
             if(contador==20){
                sf::Vector2f pos_bala = sf::Vector2f(X-20,Y-4);
                Bullet * nueva = new Bullet(pos_bala);
                Bullets.push_back(nueva);
              }
            break;
        
        default:
            break;
        }
        if(X<-20){
            delete this;
        }
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
    }
    }