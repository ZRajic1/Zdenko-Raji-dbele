#include "Cvijet.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Cvijet::Cvijet(RenderWindow* w)
{
	window = w;
	create_cvijet();
	create_list();
	create_stabljiku();
}

void Cvijet::create_cvijet()
{
	cvijet.setRadius(10);
	cvijet.setOrigin(0, 0);
	cvijet.setScale(1, 1);
	cvijet.setOutlineThickness(10.f);
	cvijet.setOutlineColor(Color::White);
	Vector2f circlePosition(395, 252);
	cvijet.setPosition(circlePosition);
	cvijet.setFillColor(Color::Yellow);
}

void Cvijet::create_list()
{
	list.setPosition(405.f, 400.f);
	list.setPointCount(3);
	list.setPoint(0, Vector2f(0, 0));
	list.setPoint(1, Vector2f(30, 10));
	list.setPoint(2, Vector2f(70, -20));
	list.setFillColor(Color::Green);

	//crni pravokutnik za animaciju
	blackScreen.setSize(Vector2f(70, 40));
	blackScreen.setPosition(406.f, 380.f);
	blackScreen.setFillColor(Color::Black);
}

void Cvijet::create_stabljiku()
{
	line[0] = Vertex(Vector2f(405.f, 500.f), Color::Green);
	line[1] = Vertex(Vector2f(405.f, 500.f), Color::Green);
}

void Cvijet::draw()
{
	if (line->position.y >= 350) //Animacije za liniju/stabljiku
	{
		line->position.y -= 2;
	}
	if (line->position.y >= 300)
	{
		line->position.y -= 1;
	}

	if (temp <= 480.f)	//Animacije za prikaz lista
	{
		blackScreen.move(1, 0);
		temp += 1;
	}
	
	if (scaleCounter <= 20)		//Animacija za zoom-in & zoom-out cvijeta
	{
		cvijet.setOrigin(6, 0);
		cvijet.scale(1.05, 1.05);
		scaleCounter++;
	}
	if (scaleCounter >= 20 && scaleCounter <= 40)
	{
		cvijet.scale(0.99, 0.99);
		scaleCounter++;
	}

	window->draw(list);
	window->draw(blackScreen);
	window->draw(line, 2, Lines);
	window->draw(cvijet);
}
