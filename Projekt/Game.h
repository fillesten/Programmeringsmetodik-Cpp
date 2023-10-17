#pragma once

#include <iostream>
#include <ctime>
#include <vector>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Player.h"
#include "Ball.h"

//float dot(const sf::Vector2f& lVec, const sf::Vector2f& rVec) { return (lVec.x * rVec.x) + (lVec.y * rVec.y); }
//sf::Vector2f normalize(sf::Vector2f src) {
//	float length = std::sqrt(dot(src, src));
//	if (length != 0) { src /= length; }
//	return src;
//}
//sf::Vector2f reflect(const sf::Vector2f& velocity, const sf::Vector2f& normal) {
//	return -2.f * dot(velocity, normal) * normal + velocity;
//}
//float lengthSquared(const sf::Vector2f& src) { return dot(src, src); }
//





class Game
{
private:
	sf::RenderWindow *window;
	sf::VideoMode videomode;
	sf::Event event;

	Player player1;
	Player player2;
	//Ball ball;

	float dt;
	sf::Clock dt_Clock;
	float moveSpeed;

	bool endGame;
	int points;

public:


	// kon/de -struktor
	Game();
	virtual ~Game();

	void setVariables();
	void setWindow();
	
	//accessfunktioner
	const bool windowRunning() const;

	//funktioner
	void winEvent();  
	
	void update();
	void updatePlayer();//individual player movement
	void playerCollision();


	void updateBall();


	void renderGUI();
	void render();
};

