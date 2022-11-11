#pragma once

#include "Object.h"
#include "Trivia.h"
#include "EventAll.h"
class GameAll:Object
{
public:
	GameAll();
	GameAll(ALLEGRO_EVENT_QUEUE* queue,EventAll* NewEventAll);


	void GameAll_Draw();
	void ActualizarCamara(float* PosicionCamara, float x, float y, int ancho, int alto);
	//Aqui es ande el cosntructor con las demas clases.........
private:


	EventAll *Main_Events;
	ALLEGRO_SAMPLE* song;

	ALLEGRO_SAMPLE_INSTANCE* songInstance;

	ALLEGRO_TRANSFORM camara;
	ALLEGRO_DISPLAY* ventana;
	ALLEGRO_EVENT_QUEUE* queue;
	ALLEGRO_TIMER* timer;
	ALLEGRO_TIMER* timerper;

	float PosicionCamara[2] = { 0,0 };
	Trivia* Mini_juego_Trivia;

	ALLEGRO_BITMAP* mapa1;
	ALLEGRO_BITMAP* personaje;
	ALLEGRO_BITMAP* Ruleta;
	


	

	//aqui ira todo el codigo
	int idelx = 200;
	int idely = 200;
	int multiply = 0;
	int multiply2 = 0;


	//musica






};

