#pragma once

//Exteral headers
#include <chrono>


/*=================================================*/
/*==================   Values   ===================*/
/*=================================================*/


float _Clock_FPSLimit = 60.f;


class Clock
{
    private:
        std::chrono::duration<double>  elapsedTime;
        std::chrono::duration<double>  interpolatedTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> lastTime;
        std::chrono::time_point<std::chrono::high_resolution_clock> lastInterpolatedTime;
    public:
        Clock();
        float getElapsedTime();
        float getInterpolatedTime();
        bool canContinue();


};




/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


/*
Constructor de clock
*/
Clock::Clock()
{
    lastTime = std::chrono::high_resolution_clock::now();
}

/*
Devuelve el tiempo transcurido
*/
float Clock::getElapsedTime()
{
    return elapsedTime.count();
}

float Clock::getInterpolatedTime()
{
    return interpolatedTime.count();
}

/*
Si el tiempo transcurrido desde la ultima vez que pudo continuar es mayor que el tiempo minimo, devuelve true y continua
*/
bool Clock::canContinue()
{
    std::chrono::time_point<std::chrono::high_resolution_clock> currentTime = std::chrono::high_resolution_clock::now();

    elapsedTime = currentTime - lastTime;
    interpolatedTime = currentTime - lastInterpolatedTime;
    lastInterpolatedTime = currentTime;

    double minTime = 1.f/_Clock_FPSLimit;
    if(elapsedTime.count() > minTime)
    {
        lastTime = currentTime;
        return true;
    }
    return false;
};