#include "Body.h"

Body::Body()
{
    x = 0;
    y = 0;
    sizeX = 1;
    sizeY = 1;
    color = al_map_rgba(25, 25, 25,1);
    angle = 1;
    CanDraw = true;
    width = 1;
    height = 1;

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

bool Body::Draw()
{
    if (CanDraw) {
   //     al_draw_tinted_scaled_rotated_bitmap(Sprite, color, width / 2, height / 2, width, height, sizeX, sizeY, angle, 0);
     al_draw_scaled_rotated_bitmap(Sprite,width/2,height/2, width, height, sizeX, sizeY, angle, 0);

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