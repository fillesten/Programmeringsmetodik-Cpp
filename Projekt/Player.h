#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//#include "Game.h"

//fg



class Player {

	sf::RectangleShape circle;
	sf::Event playerEvent;

	float middleX; 
	float middleY;
	float moveSpeed;

	sf::Vector2f velocity; //basically a pair, its params are (float x, float y)
	sf::FloatRect nextPos;

public:


	void setVariables();
	void setShape();

	Player();
	~Player();



	void update(const sf::RenderTarget* target);
	void playerWindowCollision(const sf::RenderTarget* target);
	void playerXplayerCollision(Player& p2);

	// getters / setters
	sf::RectangleShape& getCircle();
	sf::Vector2f& getVelocity();
	float& getmoveSpeed();
	sf::FloatRect& getnextPos();

	void setVelocity(float x, float y);
	void setVelocity_x(float x);
	void setVelocity_y(float y);



	void resetMiddle();


	void render(sf::RenderTarget* target);



};

