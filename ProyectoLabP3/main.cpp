
#include "GameAll.h"
#include "EventAll.h"
using namespace std;

//NUESTRA PARTE
void ActualizarCamara(float* PosicionCamara, float x, float y, int ancho, int alto) {


	PosicionCamara[0] = -(1280 / 2) + (x + ancho / 2);
	PosicionCamara[1] = -(720 / 2) + (y + alto / 2);

	if (PosicionCamara[0] < 0)
		PosicionCamara[0] = 0;
	if (PosicionCamara[1] < 0) 
		PosicionCamara[1] = 0;
};

int main() {
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();
	

	ALLEGRO_EVENT_QUEUE* queue=al_create_event_queue();
	EventAll NewEventAll = EventAll(queue);


	GameAll NewGame = GameAll(queue,&NewEventAll);

	while (true) {

		NewEventAll.RegisEvent();

		NewGame.GameAll_Draw();
	}
	/*int idelx = 200;
	int idely = 200;
	int multiply = 0;
	int multiply2 = 0;
	al_init();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	al_install_mouse();
	al_init_image_addon();
	al_init_primitives_addon();
	al_install_keyboard();
	al_install_audio();
	al_init_acodec_addon();
	
	//musica
	al_reserve_samples(2);
	ALLEGRO_SAMPLE* song = al_load_sample("menu.wav");
	ALLEGRO_SAMPLE_INSTANCE* songInstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
	al_set_sample_instance_gain(songInstance, 30);
	
	ALLEGRO_TRANSFORM camara;
	ALLEGRO_DISPLAY* ventana = al_create_display(1280, 720);
	ALLEGRO_EVENT_QUEUE* queue = al_create_event_queue();
	ALLEGRO_TIMER* timer = NULL;
	ALLEGRO_TIMER* timerper = al_create_timer(1.0 / 60);
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(ventana));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	//musica
	al_play_sample_instance(songInstance);
	float PosicionCamara[2] = { 0,0 };
	Trivia* Mini_juego_Trivia=new Trivia();
	ALLEGRO_BITMAP* mapa1 = al_load_bitmap("MAPAAVANCE.png");
	ALLEGRO_BITMAP* personaje = al_load_bitmap("Playerm.png");
	ALLEGRO_BITMAP* Ruleta = al_load_bitmap("ruleta.png");
	al_start_timer(timer);
	al_start_timer(timerper);
	while (true) {

		ALLEGRO_KEYBOARD_STATE estadotecla;
		ALLEGRO_EVENT event;
		al_get_keyboard_state(&estadotecla);
		al_wait_for_event(queue, &event);

		ActualizarCamara(PosicionCamara, idelx, idely, 64, 96);

		al_identity_transform(&camara);
		al_translate_transform(&camara, -PosicionCamara[0], -PosicionCamara[1]);
		al_use_transform(&camara);

		if (al_key_down(&estadotecla, ALLEGRO_KEY_A)) {
			idelx--;
			multiply = 1;
			if (al_get_timer_count(timerper) > 10) {
				al_set_timer_count(timerper, 0);
				if (multiply2 < 3) {
					multiply2++;

				}
				else {
					multiply2 = 0;
				}
			}
		}
		if (al_key_down(&estadotecla, ALLEGRO_KEY_W)) {
			idely--;
			multiply = 3;
			if (al_get_timer_count(timerper) > 10) {
				al_set_timer_count(timerper, 0);
				if (multiply2 < 3) {
					multiply2++;
				}
				else {
					multiply2 = 0;
				}
			}
		}
		if (al_key_down(&estadotecla, ALLEGRO_KEY_S)) {
			idely++;
			multiply = 0;
			if (al_get_timer_count(timerper) > 10) {
				al_set_timer_count(timerper, 0);
				if (multiply2 < 3) {
					multiply2++;
				}
				else {
					multiply2 = 0;
				}
			}
		}
		if (al_key_down(&estadotecla, ALLEGRO_KEY_D)) {
			idelx++;
			multiply = 2;
			if (al_get_timer_count(timerper) > 10) {
				al_set_timer_count(timerper, 0);
				if (multiply2 < 3) {
					multiply2++;
				}
				else {
					multiply2 = 0;
				}
			}
		}
		if (event.type == ALLEGRO_EVENT_TIMER) {

			Mini_juego_Trivia->Dibujar();
	  //  al_draw_scaled_bitmap(mapa1, 0, 0, 1280, 720, 0, 0, 4 * 1280, 4 * 720, 0);
	//	al_draw_bitmap_region(personaje, 64 * multiply2, 96 * multiply, 64, 96, idelx, idely, 0);
		//al_draw_rotated_bitmap(Ruleta, 60, 60, 100, 100, 100, 0);
			al_flip_display();
			al_clear_to_color(al_map_rgb(255, 255, 255));
		}



	}
	*/
	return 0;
}