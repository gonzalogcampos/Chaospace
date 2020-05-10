
//Main header
#include <Menu.h>

//Headers
#include <Render.h>
#include <Map.h>
#include <string>

/*=================================================*/
/*==================   Values   ===================*/
/*=================================================*/


float HEIGHT_MODEL_SCALE = 1.f;
float WIDTH_MODEL_SCALE = 1.f;


/*=================================================*/
/*==================   Metodos   ==================*/
/*=================================================*/


void Menu::down(){
    
    if(at<0.2)
        return;

    at = 0.f;

    buttons.at(focus)->unfocus();
    if(focus >= buttons.size() - 1){
        focus = 0;
    }else{
        focus++;
    }

    buttons.at(focus)->focus();
};

void Menu::up()
{   
    if(at<0.2)
        return;

    at = 0.f;
    buttons.at(focus)->unfocus();
    
    if(focus <= 0)
    {
        focus = buttons.size()-1;
    }else{
        
        focus--;
    }

    buttons.at(focus)->focus();
}


int Menu::click()
{
    if(!buttons.empty() && focus<buttons.size())
        return buttons.at(focus)->getID();

    return -1;
}

void Menu::clear()
{   
    for(size_t i = 0; i<buttons.size(); i++) 
        delete buttons.at(i); 
    
    buttons.clear();

    Render::getInstance()->deleteSprite(titulo);
    Render::getInstance()->deleteSprite(background);
    delete texto_level1; 
    delete fuente;
    delete texto_puntuacion1;
    delete fuente2;
    puntuacion_text2.clear();
    nivel_text2.clear();
}   

void Menu::update(float dt)
{
    //Time
    at+=dt;
    
    for(size_t i=0; i<buttons.size(); i++)
        buttons.at(i)->update();
    
}

void Menu::draw()
{
   
    Render::getInstance() -> drawSprite(background, Rvect(540.f,360.f));
    Render::getInstance() -> drawSprite(titulo, Rvect(540.f, 150.f));
    if(texto_puntuacion1!=NULL)
    {
        Render::getInstance()->drawText(*texto_puntuacion1);
    }

    if(texto_level1!=NULL)
    {
        Render::getInstance()->drawText(*texto_level1);
    }
    
     

    for(size_t i=0; i<buttons.size(); i++)
        buttons.at(i)->draw();
}

void Menu::setBackground(char* b)
{

}

Button::Button(int id, char* pathnormal, char* pathfocus, float x, float y)
{
    this->id = id;
    this->x = x;
    this->y = y;
    spritenormal = Render::getInstance() -> createSprite(pathnormal);
    spritefocus = Render::getInstance() -> createSprite(pathfocus);
    sprite = spritenormal;

}

Button::~Button()
{
    Render::getInstance()->deleteSprite(spritenormal);
    Render::getInstance()->deleteSprite(spritefocus);
}

void Button::focus()
{
    sprite = spritefocus;
}

void Button::unfocus()
{
    sprite = spritenormal;
}

void Button::setPosition(float x, float y)
{
    this->x = x;
    this->y = y;

    update();
}

void Button::update()
{
}

void Button::draw()
{
    Render::getInstance() -> drawSprite(sprite, Rvect(x, y));
}