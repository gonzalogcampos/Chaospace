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
} 


void TestState::update(float dt)
{

}


void TestState::clear()
{

}