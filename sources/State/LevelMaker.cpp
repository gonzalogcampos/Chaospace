#include <LevelMaker.h>
#include <chrono>
#include <unistd.h>
#include <SFML/Graphics.hpp>
/*
    Inicializa los vectores, el nivel y los tiempo de juego para poder comenzar a hacer
    updates.
*/
void LevelMaker::initGame()
{
    gameTime = 0.f;
    levelTime = -1.f;
    level  = 0;
    meteoros.clear();
    enemies.clear();
}

/*
    Update del juego, suma el dt al tiempo de juego y el tiempo de nivel, si esta en el estado boss actualiza el boss,
    si se ha pasado el tiempo del boss, pasa de nivel, y si esta en el estado estandar, intenta crear enemigos y meteoritos.
*/
void LevelMaker::updateGame(float dt)
{
    usleep(10);
    gameTime += dt;
    levelTime += dt;
    float t = timePerLevel + (level * timeInc);
    if(levelTime> (t + bossTime) || levelTime<0.f)
    {
        //NEXT Level
        //std::cout<<"LEVEL FINISH\n";
        meteoros.clear();
        enemies.clear();
        levelTime = 0.f;
        bossState = false;
        level++;
        std::cout<<"Level: "<<level<<"\n";
    }else if(levelTime>t)
    {
        if(!bossState)
        {
            createBoss();
            bossState = true;
        }
    }else
    {
        tryCreate(dt);
        updateVectors(dt);
    }
    
}

/*
    Elimina todos los enemigos y meteoritos, y pone el nivel a cero.
    Se usa cuando el player muere.
*/
void LevelMaker::endGame()
{
    level = 0;
    meteoros.clear();
    enemies.clear();
}

/*
    Crea enemigos y meteoritos de manera aleatoria cada dt a razon del numero por segundo 
    de cada que tiene que crear. Solo puede crear un meteorito y un enemigo cada vez.
*/
void LevelMaker::tryCreate(float dt)
{
   float tryPerSecond = 1 / dt;
   
   float prob = (enemiesPerSecond + level*incEnemiesPerSecond);
   int r = rand() % (int)tryPerSecond;
   if(r<prob)
   {
       createEnemy();
   }

   prob = (meteorosPerSecond + level*incMeteorosPerSecond);
   r = rand() % (int)tryPerSecond;
   if(r<prob)
   {
       createMeteoro();
   }
}

/*
    Crea un enemigo en una posicion y alaeatoria y x del tamanyo de la ventana. Con la fuerza,
    vida, y ataque en funcion del nivel.
*/
void LevelMaker::createEnemy()
{
    float x     = window_width;
    float y     = rand() % window_height;
    float life  = enemiesLife   + level*incEnemiesLife;
    float force = enemiesForce  + level*incEnemiesForce;
    float attak = enemiesAttak  + level*incEnemiesAttak;

    enemies.push_back(Enemy(x, y, life, force, attak));
    printData(enemies.at(enemies.size()-1));

}


/*
    Crea un meteorito en una posicion y alaeatoria y x del tamanyo de la ventana. Con la velocidad
    en funcion del nivel.
*/
void LevelMaker::createMeteoro()
{
    float x = window_width;
    float y = rand() % window_height;
    float velocity = meteorosVelocity + level * incMeteorosVelocity;

    meteoros.push_back(Meteoro(x, y, velocity));
    printData(meteoros.at(meteoros.size()-1));
}


/*
    Crea un boss en mitad de la pantalla de altura y pegado a la izquierda, con la fueza vida y ataque
    en funcion del nivel.
*/
void LevelMaker::createBoss()
{
    float x = window_width;
    float y = window_height / 2;
    float life = 0.f;
    float force = 0.f;
    float attak = 0.f;


    boss = Boss(x, y, life, force, attak);
    printData(boss);
}

void LevelMaker::updateVectors(float dt)
{
    float velocity = 300.f;
    for(size_t i = 0; i< enemies.size(); i++)
        enemies.at(i).x -= dt*velocity;

    for(size_t i = 0; i< meteoros.size(); i++)
        meteoros.at(i).x -= dt*(velocity + meteoros.at(i).velocity);
}


void LevelMaker::printData(Meteoro meteoro)
{
    std::cout<<"Meteoro created: "<<meteoro.x<<", y:"<<meteoro.y<<", v:"<<meteoro.velocity<<std::endl;
}
void LevelMaker::printData(Enemy enemy)
{
    std::cout<<"Enemy created: "<<enemy.x<<", y:"<<enemy.y<<", l:"<<enemy.life<<", f"<<enemy.force<<", a:"<<enemy.attak<<std::endl;
}
void LevelMaker::printData(Boss boss)
{
    std::cout<<"Boss created: "<<boss.x<<", y:"<<boss.y<<", l:"<<boss.life<<", f"<<boss.force<<", a:"<<boss.attak<<std::endl;
}
void LevelMaker::printAllData()
{

}


void LevelMaker::test(int levels)
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(window_width, window_height), "Hito 1 | Level creator test");

    initGame();
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float>  elapsed;
    do
    {
        elapsed = end - start;
        start = std::chrono::high_resolution_clock::now();
        updateGame(elapsed.count());
        end = std::chrono::high_resolution_clock::now();


        


        //Render
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);

        sf::CircleShape boss_shape(150);
        boss_shape.setOrigin(sf::Vector2f(boss_shape.getRadius(), boss_shape.getRadius()));
        boss_shape.setFillColor(sf::Color(250, 0, 0));

        sf::CircleShape enemy_shape(20);
        enemy_shape.setOrigin(sf::Vector2f(enemy_shape.getRadius(), enemy_shape.getRadius()));
        enemy_shape.setFillColor(sf::Color(200, 50, 50));

        sf::RectangleShape meteoro_shape(sf::Vector2f(20, 20));
        meteoro_shape.setOrigin(sf::Vector2f(meteoro_shape.getSize().x/2, meteoro_shape.getSize().y/2));
        meteoro_shape.setFillColor(sf::Color(100, 100, 100));


        
        if(bossState)
        {
            boss_shape.setPosition(boss.x, boss.y);
            window.draw(boss_shape);
        }else
        {
            for(size_t i = 0; i< enemies.size(); i++)
            {
                enemy_shape.setPosition(enemies.at(i).x, enemies.at(i).y);
                window.draw(enemy_shape);
            }

            for(size_t i = 0; i< meteoros.size(); i++)
            {
                meteoro_shape.setPosition(meteoros.at(i).x, meteoros.at(i).y);
                window.draw(meteoro_shape);
            }
        }

        window.display();
                
    }while(level<=levels);

    endGame();
    window.close();
}