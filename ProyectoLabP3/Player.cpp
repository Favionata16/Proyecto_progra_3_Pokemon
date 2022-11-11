#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include<allegro5/allegro_primitives.h>
#include <Windows.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
using namespace std;

int idelx = 650; //posicion del personaje en el mapa
int idely = 550;
enum Mapas
{
	Nieve = 1, Cueva = 2, Casa = 3 //
};

bool Colisiones(float x, float y, float ex, float ey, int ancho, int alto,int dir,int movespeed) {

	if (x + ancho < ex || x> ex + ancho || y + alto<ey || y>ey + alto) {
		return false;
	}

	///Colision

	if (dir == 0) {
		idely -= movespeed;
	}
	else if (dir == 1) {
		idelx += movespeed;
	}
	else if (dir == 2) {
	
		idelx -= movespeed;
	}
	else if (dir == 3) {
		idely += movespeed;
	}
	return true;









}
void ActualizarCamara(float* PosicionCamara, float x, float y, int ancho, int alto) { //funcion para que la camara se actualize al moverse
	 

	PosicionCamara[0] = -(1280 / 2) + (x + ancho/2);
	PosicionCamara[1] = -(720 / 2) + (y + alto/2);

	if (PosicionCamara[0] < 0)
		PosicionCamara[0] = 0;

	if (PosicionCamara[1] < 0)
		PosicionCamara[1] = 0;
};

class escenario {
	ALLEGRO_BITMAP* suelo;
	ALLEGRO_BITMAP* cielo;
	ALLEGRO_BITMAP* choque;
public:
	void carga()
	{
		suelo = al_load_bitmap("datos/escenaN.png");
		cielo = al_load_bitmap("datos/escenaS.png");
		choque = al_load_bitmap("datos/escenaC.png");
	}
	void pinta(bool sup = false)
	{
		if (!sup) al_draw_bitmap(suelo, 0, 0, 0);

		al_draw_bitmap(cielo, 0, 0, 0);

	}
	bool esRojo(int x, int y)
	{
		unsigned char r, g, b;
		ALLEGRO_COLOR colorMira;
		colorMira = al_get_pixel(choque, x, y);
		al_unmap_rgb(colorMira, &r, &g, &b);
		return (r == 255 && g == 0 && b == 0);
	}
} escena;

int main() {
	ALLEGRO_COLOR al_get_pixel(ALLEGRO_BITMAP * bitmap, int x, int y);
	int multiply = 0;
	int multiply2 = 0;
	Mapas MapaActual = Nieve; //para saber en que mapa esta
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
	ALLEGRO_SAMPLE* song = al_load_sample("menu.wav");//musica mapa normal
	ALLEGRO_SAMPLE_INSTANCE* songInstance = al_create_sample_instance(song);
	al_set_sample_instance_playmode(songInstance,ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstance, al_get_default_mixer());
	al_set_sample_instance_gain(songInstance, 40);//volumen

	ALLEGRO_SAMPLE* songC = al_load_sample("musicaCueva.wav");//musica mapa cueva
	ALLEGRO_SAMPLE_INSTANCE* songInstanceC = al_create_sample_instance(songC);
	al_set_sample_instance_playmode(songInstanceC, ALLEGRO_PLAYMODE_LOOP);
	al_attach_sample_instance_to_mixer(songInstanceC, al_get_default_mixer());
	al_set_sample_instance_gain(songInstanceC, 5);//volumen

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

	//cargando imagenes de los mapas
	ALLEGRO_BITMAP* mapa1 = al_load_bitmap("MAPAAVANCE.png");
	ALLEGRO_BITMAP* mapa2 = al_load_bitmap("cueva.png");
	ALLEGRO_BITMAP* mapa3 = al_load_bitmap("mapfinal1.png");
	ALLEGRO_BITMAP* personaje = al_load_bitmap("Playerm.png");
	al_start_timer(timer);
	al_start_timer(timerper);
	while (true) {

		ALLEGRO_KEYBOARD_STATE estadotecla;
		ALLEGRO_EVENT event;
		al_get_keyboard_state(&estadotecla);
		al_wait_for_event(queue, &event);

		ActualizarCamara(PosicionCamara, idelx, idely, 64, 96);//seguimiento

		al_identity_transform(&camara);
		al_translate_transform(&camara, -PosicionCamara[0], -PosicionCamara[1]);
		al_use_transform(&camara);

		Colisiones(idelx, idely, 1250,1540, 64, 64, multiply, 5);
		std::cout << idelx << "---" << idely << "\n";
		if (al_key_down(&estadotecla,ALLEGRO_KEY_A)) {
			idelx-=5;
			multiply = 1;
			if (al_get_timer_count(timerper)>10) {
				al_set_timer_count(timerper,0);
				if (multiply2< 3) {
					multiply2++;

				}
				else {
					multiply2 = 0;
				}
			}
		}
		if (al_key_down(&estadotecla, ALLEGRO_KEY_W)) {
			idely-=5;
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
			idely+=5;
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
			idelx+=5;
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
		

			
			if (MapaActual== Nieve) {//para ingresar
				al_draw_scaled_bitmap(mapa1, 0, 0, 1280, 720, 0, 0, 4 * 1280, 4 * 720, 0);
				if (Colisiones(idelx,idely,735, 455,34,34,multiply,0)) {
					MapaActual = Cueva;
					idelx = 865;
					idely = 1205;
					al_stop_sample_instance(songInstance);
					al_play_sample_instance(songInstanceC);
				}
				if (Colisiones(idelx, idely, 1180, 1195, 34, 34, multiply, 0)) {
					MapaActual = Casa;
					idelx = 395;
					idely = 595;
				}

			}
			else if (MapaActual == Cueva) {//para salir
				al_draw_scaled_bitmap(mapa2, 0, 0, 1280, 720, 0, 0, 4 * 1280, 4 * 720, 0);
				//870---1305
				//Idel x y y son la posicion del personaje, la coordenada en x y en y donde va a colisionar, el tamano de la colision
				if (Colisiones(idelx, idely, 870,1305, 34, 34, multiply, 0)) {
					MapaActual = Nieve;
					idelx = 750;
						idely = 570;
						al_stop_sample_instance(songInstanceC);
						al_play_sample_instance(songInstance);

				}

			}
			else if (MapaActual == Casa) {
				al_draw_scaled_bitmap(mapa3, 0, 0, 1280, 720, 0, 0, 4 * 1280, 4 * 720, 0);

				if (Colisiones(idelx, idely, 370, 570, 20, 20, multiply, 0)) {
					MapaActual = Nieve;
					idelx = 1185; 
					idely = 1245;
				}
			}

		
			al_draw_bitmap_region(personaje, 64*multiply2, 96*multiply, 64,96,idelx,idely,0);
			al_flip_display();
			al_clear_to_color(al_map_rgb(255, 255, 255));
		}

	
		
	}
	return 0;
}