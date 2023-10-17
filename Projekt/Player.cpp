#include "Player.h"

void Player::setVariables() {
	middleX = 1280.f / 2;
	middleY = 720.f / 2;
	moveSpeed = 10.f;
	circle.setPosition(middleX, middleY);
	velocity.x = 0.f;
	velocity.y = 0.f;
}

void Player::setShape() {
	circle.setFillColor(sf::Color::White);
	//circle.setRadius(30.f);
	circle.setSize(sf::Vector2f(40.f, 40.f));
}

Player::Player() { 
	setVariables();
	setShape();
}


void Player::update(const sf::RenderTarget* target) {
	
	//playerMovement(dt);
	//playerMovement(dt); //movement wasd keys
	playerWindowCollision(target);
	circle.move(velocity);
}




//ordningen i main är 
/*

Update:
playerMovement
playerCollision
playerMove
playerWinCollision

Render:
clear
draw draw
display

*/


//done
void Player::playerWindowCollision(const sf::RenderTarget* target) {
	// x = - riktningen = globalbounds.left
	// y = | riktningen = globalbounds.top
	
	if (circle.getPosition().y < 0.f) { //top
		circle.setPosition(circle.getPosition().x, 0.f);
		velocity.y = 0.f;
	}
	if (circle.getPosition().x < 0.f) { //left 
		circle.setPosition(0.f, circle.getGlobalBounds().top);
		velocity.x = 0.f;
	}
	if (circle.getPosition().y + circle.getGlobalBounds().height > target->getSize().y) { //bottom
		circle.setPosition(circle.getPosition().x, target->getSize().y - circle.getGlobalBounds().height);
		velocity.y = 0.f;
	}
	if (circle.getPosition().x + circle.getGlobalBounds().width > target->getSize().x) { //right
		circle.setPosition(target->getSize().x - circle.getGlobalBounds().width, circle.getGlobalBounds().top);
		velocity.x = 0.f;
	}
} 

void Player::playerXplayerCollision(Player& p2) {

	sf::FloatRect p1bounds = circle.getGlobalBounds();
	sf::FloatRect p2bounds = p2.circle.getGlobalBounds();

	sf::FloatRect nextPos = p1bounds;
	nextPos.left += velocity.x;
	nextPos.top += velocity.y;

	if (p2bounds.intersects(nextPos)) {
		//bottom collision from the perspective of the player
		if (p1bounds.top < p2bounds.top
			&& p1bounds.top + p1bounds.height < p2bounds.top + p2bounds.height
			&& p1bounds.left < p2bounds.left + p2bounds.width
			&& p1bounds.left + p1bounds.width > p2bounds.left) {
			velocity.y = 0.f;
			circle.setPosition(p1bounds.left, p2bounds.top - p1bounds.height);
		}
		//top collision
		if (p1bounds.top > p2bounds.top
			&& p1bounds.top + p1bounds.height > p2bounds.top + p2bounds.height
			&& p1bounds.left < p2bounds.left + p2bounds.width
			&& p1bounds.left + p1bounds.width > p2bounds.left) {
			velocity.y = 0.f;
			circle.setPosition(p1bounds.left, p2bounds.top + p2bounds.height);
		}
		//right collision
		if (p1bounds.left < p2bounds.left
			&& p1bounds.left + p1bounds.width < p2bounds.left + p2bounds.width
			&& p1bounds.top < p2bounds.top + p2bounds.height
			&& p1bounds.top + p1bounds.height > p2bounds.top) {
			velocity.x = 0.f;
			circle.setPosition(p2bounds.left - p1bounds.width, p1bounds.top);
		}
		//left collision
		if (p1bounds.left > p2bounds.left
			&& p1bounds.left + p1bounds.width > p2bounds.left + p2bounds.width
			&& p1bounds.top < p2bounds.top + p2bounds.height
			&& p1bounds.top + p1bounds.height > p2bounds.top) {
			velocity.x = 0.f;
			circle.setPosition(p2bounds.left + p1bounds.width, p1bounds.top);
		}
	}		
}


// accessors
sf::RectangleShape& Player::getCircle() { return circle; }
sf::Vector2f& Player::getVelocity() { return velocity; }
float& Player::getmoveSpeed() { return moveSpeed; }
sf::FloatRect& Player::getnextPos() { return nextPos; }

void Player::setVelocity(float x, float y) { velocity.x += x; velocity.y += y; }
void Player::setVelocity_x(float x) { velocity.x += x; }
void Player::setVelocity_y(float y) { velocity.y += y; }

void Player::resetMiddle() { circle.setPosition(middleX, middleY); }

void Player::render(sf::RenderTarget* target) { target->draw(circle); }

Player::~Player() {}
