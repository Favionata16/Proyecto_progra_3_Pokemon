#include "GameAll.h"

GameAll::GameAll() {

	al_reserve_samples(2);
	song = al_load_sample("menu.wav");
	songInstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
	al_set_sample_instance_gain(songInstance, 30);

	camara;
	ventana = al_create_display(1280, 720);
	this->queue = al_create_event_queue();

	timerper = al_create_timer(1.0 / 60);
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(ventana));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue, al_get_mouse_event_source());
	//musica
	al_play_sample_instance(songInstance);
	float PosicionCamara[2] = { 0,0 };
	Mini_juego_Trivia = new Trivia();
	mapa1 = al_load_bitmap("MAPAAVANCE.png");
	personaje = al_load_bitmap("Playerm.png");
	Ruleta = al_load_bitmap("ruleta.png");
	al_start_timer(timer);
	al_start_timer(timerper);

}
GameAll::GameAll(ALLEGRO_EVENT_QUEUE * _queue)
{
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

	al_reserve_samples(2);
	song = al_load_sample("menu.wav");
	 songInstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(songInstance, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
	al_set_sample_instance_gain(songInstance, 30);

	 camara;
 ventana = al_create_display(1280, 720);
 this->queue = _queue;

	 timerper = al_create_timer(1.0 / 60);
	timer = al_create_timer(1.0 / 60);
	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_display_event_source(ventana));
	al_register_event_source(queue, al_get_timer_event_source(timer));
	al_register_event_source(queue,al_get_mouse_event_source());
	//musica
	al_play_sample_instance(songInstance);
	float PosicionCamara[2] = { 0,0 };
	Mini_juego_Trivia = new Trivia();
 mapa1 = al_load_bitmap("MAPAAVANCE.png");
 personaje = al_load_bitmap("Playerm.png");
 Ruleta = al_load_bitmap("ruleta.png");
	al_start_timer(timer);
	al_start_timer(timerper);




}

void GameAll::GameAll_Draw()
{



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
		  	al_draw_bitmap_region(personaje, 64 * multiply2, 96 * multiply, 64, 96, idelx, idely, 0);
			  //al_draw_rotated_bitmap(Ruleta, 60, 60, 100, 100, 100, 0);
			al_flip_display();
			al_clear_to_color(al_map_rgb(255, 255, 255));
		}



}

void GameAll::ActualizarCamara(float* PosicionCamara, float x, float y, int ancho, int alto)
{

	PosicionCamara[0] = -(1280 / 2) + (x + ancho / 2);
	PosicionCamara[1] = -(720 / 2) + (y + alto / 2);

	if (PosicionCamara[0] < 0)
		PosicionCamara[0] = 0;
	if (PosicionCamara[1] < 0)
		PosicionCamara[1] = 0;
}
