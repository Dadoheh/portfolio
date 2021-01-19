#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

#define MAX_NUMBER_OF_ITEMS 2

class Menu
{
public:
	Menu(float width, float height);
	~Menu() = default;
	void draw(RenderWindow& window);
	int update(RenderWindow& window);

private:
	bool on_mouse_over(Text text_to_check, RenderWindow& window);
	Font font;
	Text menu[MAX_NUMBER_OF_ITEMS];

};

