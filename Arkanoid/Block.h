#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Block :public Drawable
{
public:
	Block(float t_X, float t_Y, float t_Width, float t_Height);
	Block() = delete;
	~Block() = default;

	void update();

	Vector2f getPosision();

	float left();
	float right();
	float top();
	float bottom();

	bool isDestoroyed();
	void destroy();
	Vector2f getSize();

private:
	virtual void draw(sf::RenderTarget& target, RenderStates states) const override;
	RectangleShape shape;
	bool destroyed{ false };
};

