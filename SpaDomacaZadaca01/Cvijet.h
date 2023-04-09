#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Cvijet
{
	float temp = 406.f;
	float scaleCounter = 0;
	CircleShape cvijet;
	ConvexShape list;
	RectangleShape blackScreen;
	Vertex line[2];
	RenderWindow* window;

public:
	Cvijet(RenderWindow* w);
	void draw();
	void create_cvijet();
	void create_list();
	void create_stabljiku();

};

