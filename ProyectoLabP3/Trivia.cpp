#include "Trivia.h"

Trivia::Trivia()
{

	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	
	al_install_keyboard();
	
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



	if (al_get_timer_count(timer)>1) {

	
		AnimarRuleta();
		al_set_timer_count(timer, 0);
	
	}
	if (rotation > 6.28)
		rotation = 0;
}
