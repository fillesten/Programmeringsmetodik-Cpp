#include "Game.h"

Game::Game() {
	setVariables(); 
	setWindow();
}

void Game::setVariables() {
	window = nullptr;
    endGame = false;
    moveSpeed = 10.f;
}

void Game::setWindow() {
	videomode.width = 1280;
	videomode.height = 720;
	window = new sf::RenderWindow (videomode ,"Blivande bangerspel!", sf::Style::Titlebar | sf::Style::Close);
    window->setVerticalSyncEnabled(true); //declare framerate to monitors default
}

const bool Game::windowRunning() const { return window->isOpen(); } //keeps the while loop in main going

//i main körs update sen render hela tiden, de permanenet uppdateras
void Game::update() {

    winEvent();
    dt = dt_Clock.restart().asSeconds();

    if (!endGame)
    {
        updatePlayer();//player movement happens outside of player since 2 players
        //playerCollision();
        player1.update(window);
        player2.update(window);

        player1.playerXplayerCollision(player2);
        player2.playerXplayerCollision(player1);


        //sf::FloatRect playerBounds = player1.getCircle().getGlobalBounds();
        //sf::FloatRect wallBounds = player2.getCircle().getGlobalBounds();

        //sf::FloatRect nextPos = playerBounds;
        //nextPos.left += player1.getVelocity().x;
        //nextPos.top += player1.getVelocity().y;

        //if (wallBounds.intersects(nextPos))
        //{
        //    //Bottom collision
        //    if (playerBounds.top < wallBounds.top
        //        && playerBounds.top + playerBounds.height < wallBounds.top + wallBounds.height
        //        && playerBounds.left < wallBounds.left + wallBounds.width
        //        && playerBounds.left + playerBounds.width > wallBounds.left )
        //    {
        //        player1.setVelocity_y(0.f);
        //        //velocity.y = 0.f;
        //        player1.getCircle().setPosition(playerBounds.left, wallBounds.top - playerBounds.height);
        //    }

        //    //Top collision
        //    else if (playerBounds.top > wallBounds.top
        //        && playerBounds.top + playerBounds.height > wallBounds.top + wallBounds.height
        //        && playerBounds.left < wallBounds.left + wallBounds.width
        //        && playerBounds.left + playerBounds.width > wallBounds.left )
        //    {
        //        player1.setVelocity_y(0.f);
        //        player1.getCircle().setPosition(playerBounds.left, wallBounds.top + wallBounds.height);
        //    }

        //    //Right collision
        //    if (playerBounds.left < wallBounds.left
        //        && playerBounds.left + playerBounds.width < wallBounds.left + wallBounds.width
        //        && playerBounds.top < wallBounds.top + wallBounds.height
        //        && playerBounds.top + playerBounds.height > wallBounds.top )
        //    {
        //        player1.setVelocity_x(0.f);
        //        player1.getCircle().setPosition(wallBounds.left - playerBounds.width, playerBounds.top);
        //    }

        //    //Left collision
        //    else if (playerBounds.left > wallBounds.left
        //        && playerBounds.left + playerBounds.width > wallBounds.left + wallBounds.width
        //        && playerBounds.top < wallBounds.top + wallBounds.height
        //        && playerBounds.top + playerBounds.height > wallBounds.top )
        //    {
        //        player1.setVelocity_x(0.f);
        //        player1.getCircle().setPosition(wallBounds.left + wallBounds.width, playerBounds.top);
        //    }
        //}






    }
}


void Game::updatePlayer() {

    sf::Vector2f velValues;
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        velValues.x = 0.f;
        velValues.y = -moveSpeed * dt;
        player1.setVelocity(velValues.x, velValues.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        velValues.x = -moveSpeed * dt;
        velValues.y = 0.f;
        player1.setVelocity(velValues.x, velValues.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        velValues.x = 0.f;
        velValues.y = moveSpeed * dt;
        player1.setVelocity(velValues.x, velValues.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        velValues.x = moveSpeed * dt;
        velValues.y = 0.f;
        player1.setVelocity(velValues.x, velValues.y);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velValues.x = 0.f;
        velValues.y = -moveSpeed * dt;
        player2.setVelocity(velValues.x, velValues.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velValues.x = -moveSpeed * dt;
        velValues.y = 0.f;
        player2.setVelocity(velValues.x, velValues.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        velValues.x = 0.f;
        velValues.y = moveSpeed * dt;
        player2.setVelocity(velValues.x, velValues.y);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velValues.x = moveSpeed * dt;
        velValues.y = 0.f;
        player2.setVelocity(velValues.x, velValues.y);
    }
}

void Game::playerCollision() {
    sf::FloatRect p1bounds = player1.getCircle().getGlobalBounds();
    sf::FloatRect p2bounds = player2.getCircle().getGlobalBounds();

    sf::FloatRect nextPos1 = p1bounds;
    nextPos1.left += player1.getVelocity().x;
    nextPos1.top += player1.getVelocity().y;

    sf::FloatRect nextPos2 = p2bounds;
    nextPos2.left += player2.getVelocity().x;
    nextPos2.top += player2.getVelocity().y;


    if (p2bounds.intersects(nextPos1)) {

        // bottom collision
        if (p1bounds.top < p2bounds.top 
        && p1bounds.top + p1bounds.height < p2bounds.top + p2bounds.height
        && p1bounds.left < p2bounds.left + p2bounds.width
        && p1bounds.left + p1bounds.width > p2bounds.left ) {
            player1.setVelocity_y(0.f);
            player1.getCircle().setPosition(p1bounds.left, p2bounds.top - p1bounds.height);
        }
        //top collision
        if (p1bounds.top > p2bounds.top
        && p1bounds.top + p1bounds.height > p2bounds.top + p2bounds.height
        && p1bounds.left < p2bounds.left + p2bounds.width
        && p1bounds.left + p1bounds.width > p2bounds.left ) {
            player1.setVelocity_y(0.f);
            player1.getCircle().setPosition(p1bounds.left, p2bounds.top + p1bounds.height);
        }
        if (p1bounds.left < p2bounds.left //right collision
        && p1bounds.left + p1bounds.width < p2bounds.left + p2bounds.width
        && p1bounds.top < p2bounds.top + p2bounds.height
        && p1bounds.top + p1bounds.height > p2bounds.top) {
            player1.setVelocity_x(0.f);
            player1.getCircle().setPosition(p2bounds.left - p1bounds.width, p1bounds.top);
        }
        
        if (p1bounds.left > p2bounds.left //left collision
            && p1bounds.left + p1bounds.width > p2bounds.left + p2bounds.width
            && p1bounds.top < p2bounds.top + p2bounds.height
            && p1bounds.top + p1bounds.height > p2bounds.top) {
            player1.setVelocity_x(0.f);
            player1.getCircle().setPosition(p2bounds.left + p1bounds.width, p1bounds.top);
        }

    }
   
}



void Game::render() {
    window->clear(sf::Color(0, 0, 0, 255));
    
    //draw game here

    
    
    player1.render(window);
    
    player2.render(window);
    window->display();
}

/*
Alternativt så kan jag kanske kalla 
på playerMovement inne i denna switch
ELLER så tar jag hela playerMovement 
och stoppar in den i denna switch.
*/
//alternativ lösning ^

//closes the window etc...
void Game::winEvent() {
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) { window->close(); }
        if (event.type == sf::Event::KeyPressed) { 
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { window->close(); }
        }
    }
} 


Game::~Game() { delete this->window; }