#include "Body.h"

Body::Body()
{
    x = 0;
    y = 0;
    sizeX = 1;
    sizeY = 1;
    color = al_map_rgba_f(1,1,1,20);
    angle = 1;
    CanDraw = true;
    width = 1;
    height = 1;
    sx = 0;
    sy = 0;
    TintGrade = 20;

    al_init_font_addon();
    al_init_ttf_addon();
    al_install_keyboard();
    al_install_mouse();
    al_init_image_addon();

}

void Body::setAngle(int _angle) {
    angle = _angle;

}
void Body::setSizeX(float _x) {
    sizeX = _x;

}

void Body::setSizeY(float _y) {

    sizeY = _y;

}
void Body::setX(int _x) {
    x= _x;

}

void Body::setY(int _y) {

    y = _y;

}
void Body::setCanDraw(bool _CanDraw)
{
    CanDraw = _CanDraw;
}

void Body::setTintGrade(float grade)
{

    TintGrade = grade;
}

void Body::setSx(int _sx)
{
    ///zona de dibujado del bitmap
    sx = _sx;
}

void Body::setSy(int _sy)
{
    //zona de dibujado del bitmap
    sy = _sy;
}
bool Body::Colisiones(float x, float y, float ex, float ey, int ancho, int alto, int dir, int movespeed) {

    if (x + ancho < ex || x> ex + ancho || y + alto<ey || y>ey + alto) {
        return false;
    }

    ///Colision

    if (dir == 0) {
        this->y -= movespeed;

    }
    else if (dir == 1) {
        this->x+= movespeed;
    }
    else if (dir == 2) {

        this->x -= movespeed;
    }
    else if (dir == 3) {
        this->y+= movespeed;
    }
    return true;









}
bool Body::Draw()
{
    if (CanDraw) {
    //     al_draw_tinted_scaled_rotated_bitmap(Sprite, color, width / 2, height / 2, x, y, sizeX, sizeY, angle, 0);
         al_draw_tinted_scaled_rotated_bitmap_region(Sprite,width*sx,height*sy,width,height, al_map_rgba_f(1, 1, 1, TintGrade) ,width/2,height/2,x,y,sizeX,sizeY,angle,0);

    }

    return CanDraw;




}
void Body::setWidth(int _width) {

    width = _width;

}
void Body::setHeight(int _height) {

    height = _height;

}

Body::~Body() {


}