#pragma once

#ifndef TRIVIA_H

#include "Button.h"

#define TRIVIA_H


class Trivia
{

private:

	Button* NuevoBoton ;
	bool ReduceSpeed;
	float speed;
public:
	Trivia();
	Trivia(EventAll* event);
	float rotation;

	void AnimarRuleta();
	void Events();
	void Dibujar();
	ALLEGRO_BITMAP* Ruleta;
	ALLEGRO_TIMER* timer;
	EventAll* Main_Event;
	

	




};


#endif // !TRIVIA_H

