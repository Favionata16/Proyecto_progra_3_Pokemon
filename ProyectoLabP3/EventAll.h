#pragma once

#include "Object.h"


#ifndef EVENT_ALL_H
 


#define EVENT_ALL_H
class EventAll:Object {

private:
	


	bool L_Mouse;
	bool R_Mouse;
public:
	EventAll();
	EventAll(ALLEGRO_EVENT_QUEUE* queue);
	void RegisEvent();
	ALLEGRO_EVENT_QUEUE * queue;

	bool Mouse_Left_Button();
	bool Mouse_Right_Button();
	//getter de events;








};


#endif // !EVENT_ALL_H


