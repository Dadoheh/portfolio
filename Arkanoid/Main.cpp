#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

#include "Block.h"
#include"Ball.h"
#include "Paddle.h"
#include"Menu.h"

using namespace std;
using namespace sf;

enum States
{
	GAME, MENU
};
template<class T1, class T2>bool isIntersecting(T1& A, T2& B)
{
	return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}

bool collisiontest(Paddle& paddle, Ball& ball)
{
	if (!isIntersecting(paddle, ball))
		return false;
	ball.moveUp();
	if (ball.getPosision().x < paddle.getPosision().x)
	{
		ball.moveLeft();
	}
	else if (ball.getPosision().x > paddle.getPosision().x)
	{
		ball.moveRight();
	}

}

bool collisiontest(Block& block, Ball& ball)
{
	if (!isIntersecting(block, ball))
		return false;
	block.destroy();

	float overlapLeft{ ball.right() - block.left() };
	float overlapRight{ block.right() - ball.left() };

	float overlapTop{ ball.bottom() - block.top() };
	float overlapBottom{ block.bottom() - ball.top() };

	bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
	bool ballFromTop(abs(overlapTop) < abs(overlapBottom));

	float minOverlapX{ ballFromLeft ? overlapLeft : overlapRight };
	float minOverlapY{ ballFromTop ? overlapTop : overlapBottom };

	if (abs(minOverlapX) < abs(minOverlapY))
	{
		ballFromLeft ? ball.moveLeft() : ball.moveRight();
	}
	else
	{
		ballFromTop ? ball.moveUp() : ball.moveDown();
	}

}

int main()
{
	RenderWindow window{ VideoMode{800,600}, "Arkanoid Game" };
	window.setFramerateLimit(60);
	Menu menu(window.getSize().x, window.getSize().y);//dodane

	Ball ball(400, 300);
	Paddle paddle(400, 500);
	States state = MENU;


	Event event;
	unsigned blocksX{ 8 }, blocksY{ 4 }, blockWidth{ 80 }, blockHeight{ 30 };

	vector<Block>blocks;//
	for (int i = 0; i < blocksY; i++)
	{
		for (int j = 0; j < blocksX; j++)
		{
			blocks.emplace_back((j + 1) * (blockWidth + 10), (i + 2) * (blockHeight + 5), blockWidth, blockHeight);
		}
	}
	while (window.isOpen())
	{
		window.clear(Color(193, 205, 153));
		window.pollEvent(event);

		if (event.type == Event::Closed)
		{
			window.close();
			break;
		}
		if (state == MENU)
		{
			int pick = menu.update(window);
			if (pick == 0)
			{
				state = GAME;
			}
			else if (pick == 1)
			{
				exit(0);
			}
			menu.draw(window);//dodane
		}
		else
		{
			ball.update();
			paddle.update();

			for (auto& block : blocks)if (collisiontest(block, ball)) break;

			auto iterator = remove_if(begin(blocks), end(blocks), [](Block& block) {return block.isDestoroyed(); });//
			blocks.erase(iterator, end(blocks));

			for (auto& block : blocks)
				window.draw(block);

			collisiontest(paddle, ball);
			window.draw(ball);
			window.draw(paddle);
		}

		window.display();
	}
	return 0;
}
