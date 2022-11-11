#include "Trivia.h"

Trivia::Trivia()
{

	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	
	al_install_keyboard();
	NuevoBoton = new Button("Imagenes/Boton_Verde.png");
	NuevoBoton->setX(1080);
	NuevoBoton->setY(600);
	NuevoBoton->setHeight(2050);
	NuevoBoton->setWidth(2050);
	NuevoBoton->setSizeX(0.09);
	NuevoBoton->setSizeY(0.09);
	NuevoBoton->setAngle(0);
	Ruleta = al_load_bitmap("ruleta.png");

	timer = al_create_timer(1.0 / 60);
	al_start_timer(timer);
	rotation = 0;

	

}

void Trivia::AnimarRuleta()
{
//	al_draw_rotated_bitmap(Ruleta,60,60,100,100,rotation,0);

//	al_draw_bitmap(Ruleta,50,50,0);
	rotation +=0.05;

}

void Trivia::Dibujar()
{

	al_draw_scaled_rotated_bitmap(Ruleta, 60, 60, 120, 120, 15, 15, rotation, 0);


	NuevoBoton->Draw();



	if (al_get_timer_count(timer)>1) {

	
		AnimarRuleta();
		al_set_timer_count(timer, 0);
	
	}
	if (rotation > 6.28)
		rotation = 0;
}
