
#include "Button.h"
Button::Button() {


	Sprite = nullptr;

}
bool Button::Clicked(EventAll* _event) {

	if (Colisiones(_event->x_mouse_point, _event->y_mouse_point, x, y, 96, 96, 0, 0)) {

		if (_event->Mouse_Left_Button())

		{

			cout << "HAS HECHO CLICK EN UN BOTON\n";
			_event->setL_Mouse(false);

			return true;

		}

		TintGrade =0.5;

	}
	else {
		TintGrade = 20;
	}

	return false;




}

bool Button::Collided(EventAll* _event) {

	return false;
}
Button::Button(string Nombre) {
	

	Sprite = al_load_bitmap("Boton_Verde.png");


	al_init_font_addon();
	al_init_ttf_addon();

	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
}