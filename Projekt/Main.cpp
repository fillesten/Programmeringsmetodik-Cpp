#include "Game.h"

//nya med bollar och circular collision: src: https://trederia.blogspot.com/2016/02/2d-physics-101-pong.html
//float dot(const sf::Vector2f& lVec, const sf::Vector2f& rVec) { return (lVec.x * rVec.x) + (lVec.y * rVec.y); }
//sf::Vector2f normalize(sf::Vector2f src) {
//    float length = std::sqrt(dot(src, src));
//    if (length != 0) { src /= length; }
//    return src;
//}
//sf::Vector2f reflect(const sf::Vector2f& velocity, const sf::Vector2f& normal) {
//    return -2.f * dot(velocity, normal) * normal + velocity;
//}
//float lengthSquared(const sf::Vector2f& src) { return dot(src, src); }
//




//mina gamla:
void playerMovement(sf::Vector2f& playerVel1, sf::Vector2f& playerVel2, float moveSpeed, float& dt) {
    //player1 måvment  BLUE
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { playerVel1.y += -moveSpeed * dt; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { playerVel1.y += moveSpeed * dt;  }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { playerVel1.x += -moveSpeed * dt; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { playerVel1.x += moveSpeed * dt;  }
    
    //player2 måvment RED
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    { playerVel2.y += -moveSpeed * dt; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  { playerVel2.y += moveSpeed * dt;  }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  { playerVel2.x += -moveSpeed * dt; }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { playerVel2.x += moveSpeed * dt;  }
    
    /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { p1.move(0.f, -moveSpeed); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) { p1.move(0.f, moveSpeed);  }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { p1.move(-moveSpeed, 0.f); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) { p1.move(moveSpeed, 0.f);  }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    { p2.move(0.f, -moveSpeed); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  { p2.move(0.f, moveSpeed);  }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  { p2.move(-moveSpeed, 0.f); }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { p2.move(moveSpeed, 0.f);  }*/
    //static movement
}
void winCollision(sf::RectangleShape& player ,sf::Vector2f& playerVel, float winWidth, float winHeigt) { 
    if (player.getPosition().x < 0.f) {  //left
        player.setPosition(0.f, player.getPosition().y); 
        playerVel.x = 0.f; 
    }
    if (player.getPosition().y < 0.f) {  //top
        player.setPosition(player.getPosition().x, 0.f); 
        playerVel.y = 0.f; 
    }
    if (player.getPosition().x + player.getGlobalBounds().width > winWidth) { //right
        player.setPosition(winWidth - player.getGlobalBounds().width, player.getPosition().y); 
        playerVel.x = 0.f; 
    }
    if (player.getPosition().y + player.getGlobalBounds().height > winHeigt) { //bottom
        player.setPosition(player.getPosition().x, winHeigt - player.getGlobalBounds().height);
        playerVel.y = 0.f;
    }
}

void playerCollision(sf::RectangleShape& p1, sf::RectangleShape& p2, sf::Vector2f& playerVel/*, sf::FloatRect& nextPos*/) {
    // p1 är blå ---  p2 är röd
    sf::FloatRect p1bounds = p1.getGlobalBounds();
    sf::FloatRect p2bounds = p2.getGlobalBounds();

    sf::FloatRect nextPos = p1bounds;
    nextPos.left += playerVel.x;
    nextPos.top += playerVel.y;

    if (p2bounds.intersects(nextPos)) {
        //bottom collision from the perspective of the player
        if (p1bounds.top < p2bounds.top
            && p1bounds.top + p1bounds.height < p2bounds.top + p2bounds.height
            && p1bounds.left < p2bounds.left + p2bounds.width
            && p1bounds.left + p1bounds.width > p2bounds.left) {
            playerVel.y = 0.f;
            p1.setPosition(p1bounds.left, p2bounds.top - p1bounds.height);
        }
        //top collision
        if (p1bounds.top > p2bounds.top
            && p1bounds.top + p1bounds.height > p2bounds.top + p2bounds.height
            && p1bounds.left < p2bounds.left + p2bounds.width
            && p1bounds.left + p1bounds.width > p2bounds.left) {
            playerVel.y = 0.f;
            p1.setPosition(p1bounds.left, p2bounds.top + p2bounds.height);
        }
        //right collision
        if (p1bounds.left < p2bounds.left
            && p1bounds.left + p1bounds.width < p2bounds.left + p2bounds.width
            && p1bounds.top < p2bounds.top + p2bounds.height
            && p1bounds.top + p1bounds.height > p2bounds.top) {
            playerVel.x = 0.f;
            p1.setPosition(p2bounds.left - p1bounds.width, p1bounds.top);
        }
        //left collision
        if (p1bounds.left > p2bounds.left
            && p1bounds.left + p1bounds.width > p2bounds.left + p2bounds.width
            && p1bounds.top < p2bounds.top + p2bounds.height
            && p1bounds.top + p1bounds.height > p2bounds.top) {
            playerVel.x = 0.f;
            p1.setPosition(p2bounds.left + p2bounds.width, p1bounds.top);
            //nextPos
        }
    }
}



int main()
{

    const float window_Width = 1280.f; // x 
    const float window_Height = 720.f; // y
    sf::RenderWindow tempwin(sf::VideoMode(window_Width, window_Height), "skitgrejer");
    tempwin.setFramerateLimit(120);    //           x  ,  y
    
    float dt;
    sf::Clock dt_Clock;

    const float moveSpeed = 1.f;

    sf::RectangleShape p1(sf::Vector2f(40.f, 40.f)); //skapar spelare 1
    p1.setPosition(0.f, window_Height/2);
    p1.setFillColor(sf::Color::Blue);

    sf::RectangleShape p2(sf::Vector2f(40.f, 40.f)); //skapare spelare 2 
    p2.setPosition(window_Width/2 - p2.getGlobalBounds().width, window_Height/2);
    p2.setFillColor(sf::Color::Red);

    sf::CircleShape ball(25.f);
    ball.setPosition(window_Width/2 - ball.getGlobalBounds().width, window_Height / 2);
    ball.setFillColor(sf::Color::White);


    //om jag har den här i while så försvinner speeden 
    sf::Vector2f playerVel1(0.f, 0.f);
    sf::Vector2f playerVel2(0.f, 0.f);
    sf::Vector2f ballVel(0.f, 0.f);


    std::vector<sf::RectangleShape> walls; //träning med collision och mer direkt från guiden 
    sf::RectangleShape wall;
    wall.setFillColor(sf::Color::Magenta);
    wall.setSize(sf::Vector2f(40.f, 40.f));
    wall.setPosition(sf::Vector2f(window_Width / 2 - p1.getGlobalBounds().width, window_Height / 2));
    walls.push_back(wall);

    //collision
    sf::FloatRect nextPos;
 
    while (tempwin.isOpen()) {

        sf::Event event;
        dt = dt_Clock.restart().asSeconds();
        while (tempwin.pollEvent(event)) {
            if (event.type == sf::Event::Closed) { tempwin.close(); }
            if (event.type == sf::Event::KeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { tempwin.close(); }
            }
        }
        
        //adds movespeed to velocity-vectors so the MOVE func actually does something
        playerMovement(playerVel1, playerVel2, moveSpeed, dt); 

        //collision             
        playerCollision(p1, p2, playerVel1/*, nextPos*/);//run the collision detection for both players 
        playerCollision(p2, p1, playerVel2/*, nextPos*/);

        //for (auto& i : walls) { playerCollision(p1, i, playerVel1, nextPos); playerCollision(p2, i, playerVel2, nextPos); } //för vägggrejen jag kommentera längre upp

        p1.move(playerVel1); //moves the player accordingly to the velocity vectors
        p2.move(playerVel2);


        winCollision(p1, playerVel1, window_Width, window_Height);
        winCollision(p2, playerVel2, window_Width, window_Height);
        

        //normalize(sf::Vector2f(10.f, 15.f));

        //render
        tempwin.clear();
        tempwin.draw(p1);
        tempwin.draw(p2);
        
        //for (auto& i : walls) { tempwin.draw(i); }
        

        
        tempwin.draw(p2);
        //tempwin.draw(ball);
        tempwin.display();
    }



    //nedanför är min klass osv

    srand(static_cast<unsigned>(time(0)));

    Game game;

    while (game.windowRunning()) {
        game.update();
        game.render();
    }
    return 0;
}




