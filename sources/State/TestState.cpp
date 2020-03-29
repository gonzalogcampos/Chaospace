#include "TestState.h"
#include <Render.h>
#include <iostream>

void TestState::initState()
{
    type = State::TEST;


    std::cout<<"/////////////////TESTEANDO RENDER://///////////////\n";

    std::cout<<"\n -Carga de texturas:\n";
    std::cout<<"      -Textura correcta:";
    std::cout<<Render::getInstance()->loadTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Direccion de textura:";
    std::cout<<Render::getInstance()->getTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Textura incorrecta:";
    std::cout<<Render::getInstance()->loadTexture("resources/mal.png")<<"\n";
    std::cout<<"      -Direccion de textura:";
    std::cout<<Render::getInstance()->getTexture("resources/mal.png")<<"\n";
    std::cout<<"      -Textura duplicada:";
    std::cout<<Render::getInstance()->loadTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Direccion de textura:";
    std::cout<<Render::getInstance()->getTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Borrar textura:";
    std::cout<<Render::getInstance()->deleteTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Direccion de textura:";
    std::cout<<Render::getInstance()->getTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Borrar textura:";
    std::cout<<Render::getInstance()->deleteTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Textura correcta:";
    std::cout<<Render::getInstance()->loadTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Direccion de textura:";
    std::cout<<Render::getInstance()->getTexture("resources/sprites.png")<<"\n";

    std::cout<<"\n\n\n/////////////////TESTEANDO SPRITES://///////////////\n";

    std::cout<<"\n -Carga de sprites:\n";
    std::cout<<"      -Sprite correcto:";
    sprite1=Render::getInstance()->createSprite("resources/sprites.png");
    std::cout<<sprite1<<"\n";
    std::cout<<"      -Sprite correcto:";
    sprite2=Render::getInstance()->createSprite("resources/sprites.png");
    std::cout<<sprite2<<"\n";
    std::cout<<"      -Sprite correcto:";
    sprite3=Render::getInstance()->createSprite("resources/sprites.png");
    std::cout<<sprite3<<"\n";
    std::cout<<"      -Borrando sprite 2:";
    std::cout<<Render::getInstance()->deleteSprite(sprite2)<<"\n";
    std::cout<<"      -Borrando sprite 2:";
    std::cout<<Render::getInstance()->deleteSprite(sprite2)<<"\n";
    
    std::cout<<"\n\n\n/////////////////Borrado Completo://///////////////\n";
    std::cout<<"\n -Borrado completo:\n";
    Render::getInstance()->clearMemory();
    std::cout<<"      -Borrando sprite 1:";
    std::cout<<Render::getInstance()->deleteSprite(sprite1)<<"\n";
    std::cout<<"      -Borrar textura:";
    std::cout<<Render::getInstance()->deleteTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Textura correcta:";
    std::cout<<Render::getInstance()->loadTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Borrar textura:";
    std::cout<<Render::getInstance()->deleteTexture("resources/sprites.png")<<"\n";
    std::cout<<"      -Sprite correcto:";
    sprite1=Render::getInstance()->createSprite("resources/sprites.png");
    std::cout<<sprite1<<"\n";
    std::cout<<"      -Sprite correcto:";
    sprite2=Render::getInstance()->createSprite("resources/sprites.png");
    std::cout<<sprite2<<"\n";
    std::cout<<"      -Sprite correcto:";
    sprite3=Render::getInstance()->createSprite("resources/sprites.png");
    std::cout<<sprite3<<"\n";
    

} 


void TestState::update(float dt)
{
    //std::cout<<"      -Dibujando sprite 1:\n";
    std::cout<<"GlobalScale:"<<Render::getInstance()->getGlobalScale()<<"\n";
    Render::getInstance()->setGlobalScale(Render::getInstance()->getGlobalScale()+dt/1000);
    Render::getInstance()->drawSprite(sprite1);
    Render::getInstance()->drawSprite(sprite2, Rvect(800.f,600.f), 0.f, 1.f, true);
    rot+=dt;
    Render::getInstance()->drawSprite(sprite3, Rvect(400.f,300.f), rot, 1.f, true);


}


void TestState::clear()
{

}