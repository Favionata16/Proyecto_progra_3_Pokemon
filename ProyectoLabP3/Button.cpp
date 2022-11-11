
#include "Button.h"
Button::Button() {


	Sprite = nullptr;

}

Button::Button(string Nombre) {
	

	Sprite = al_load_bitmap("Boton_Verde.png");


	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
}