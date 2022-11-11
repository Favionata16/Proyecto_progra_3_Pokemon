#pragma once
#include "Object.h"


class Body:public Object
{


protected:

	int x, y;
	float sizeX;
	float sizeY;
	int height;
	int width;
	float angle;
	int sx;
	int sy;
	float TintGrade;


	ALLEGRO_COLOR color;


	ALLEGRO_BITMAP* Sprite;
	
public:
	
	Body();
	bool CanDraw;
	void setCanDraw(bool _CanDraw);
	void setTintGrade(float grade);
	void setSx(int _sx);
	void setSy(int _sy);
	void setX(int x);
	void setY(int y);
	void setSizeX(float _x);
	void setSizeY(float);

	void setWidth(int _width);
	void setHeight(int _height);
	void setAngle(int _angle);
	bool Draw();



	~Body();



};

