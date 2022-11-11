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
	int x_mouse_point;
	int y_mouse_point;
	EventAll(ALLEGRO_EVENT_QUEUE* queue);
	void RegisEvent();
	ALLEGRO_EVENT_QUEUE * queue;
	void  setL_Mouse(bool L);
	void selR_Mouse(bool R);
	bool Mouse_Left_Button();
	bool Mouse_Right_Button();

	//getter de events;








};


#endif // !EVENT_ALL_H


