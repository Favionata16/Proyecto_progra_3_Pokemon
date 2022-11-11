#pragma once
#include "Body.h"
#include "EventAll.h"
#include"Event_I.h"

class Button :public Body,Event_I
{
public:



	Button();
	Button(string Nombre);


	bool  Clicked(EventAll* _event) override;
	bool Collided(EventAll* _event) override ;




private:









};

