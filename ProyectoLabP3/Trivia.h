#pragma once

#ifndef TRIVIA_H

#include "Button.h"
#define TRIVIA_H

class Trivia
{

private:

	Button* NuevoBoton ;

public:
	Trivia();

	float rotation;
	void AnimarRuleta();
	void Dibujar();
	ALLEGRO_BITMAP* Ruleta;
	ALLEGRO_TIMER* timer;

	

	




};


#endif // !TRIVIA_H

