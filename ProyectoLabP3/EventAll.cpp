#include "EventAll.h"




bool EventAll::Mouse_Left_Button()
{

	return L_Mouse;
}

EventAll::EventAll() {
	

	x_mouse_point = 0;
	y_mouse_point = 0;


}
void EventAll:: setL_Mouse(bool L) {
	L_Mouse = L;

}
void EventAll:: selR_Mouse(bool R) {
	R_Mouse = R;
}
EventAll::EventAll(ALLEGRO_EVENT_QUEUE* queue) {

	this->queue = queue;


	al_register_event_source(queue, al_get_keyboard_event_source());
	al_register_event_source(queue, al_get_mouse_event_source());

}
bool EventAll::Mouse_Right_Button()
{
	return R_Mouse;
}
void EventAll::RegisEvent() {


	ALLEGRO_EVENT events;
	al_wait_for_event(queue, &events);
	//Este codigo obtendra todos los eventos que se registren de entradas.
	if (events.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {

		if (events.mouse.button & 1) {
			L_Mouse = true;

			cout << "Se presiono un Boton del Mouase 1\n";
		}
		else if (events.mouse.button & 2) {

			R_Mouse = true;

			cout << "Se presiono un boton del Mouse 2\n";
		}


	}
	else {
	
		L_Mouse = false;
		R_Mouse = false;
	}

		 
	
    if (events.type == ALLEGRO_EVENT_MOUSE_AXES) {
	
		x_mouse_point = events.mouse.x;
		y_mouse_point = events.mouse.y;
		cout << "Mouse x:" << x_mouse_point<<endl;
		cout << "Mouse y:" << y_mouse_point << endl;

	}



}
