#pragma once


#include "EventAll.h"


class Event_I
{
public:

	Event_I();

	virtual bool Clicked( EventAll * _event) = 0;
	virtual bool Collided(EventAll *_event) = 0;
	///



};

