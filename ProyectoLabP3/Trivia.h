#pragma once

#ifndef TRIVIA_H
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

#include <allegro5/allegro_image.h>
#define TRIVIA_H

class Trivia
{

private:
	
public:
	Trivia();

	float rotation;
	void AnimarRuleta();
	void Dibujar();
	ALLEGRO_BITMAP* Ruleta;
	ALLEGRO_TIMER* timer;
	
	

	




};


#endif // !TRIVIA_H

