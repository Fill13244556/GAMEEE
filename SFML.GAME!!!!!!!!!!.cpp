#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;
#include "Settings.h"
int main()
{
    setlocale(LC_ALL, "Russian"); 
    // Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGTH), WINDOW_TITLE);
    window.setFramerateLimit(FPS);
    //Ñîçäàíè èãðîâûõ îáúåêòîâ
      // Ðàêåòêè 
    RectangleShape leftbat, rightbat;
    leftbat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGTH));
    leftbat.setPosition(BAT_OFFSET, (WINDOW_HEIGTH - BAT_HEIGTH) / 2);
    leftbat.setFillColor(LEFT_BAT_COLOR);
    rightbat.setSize(Vector2f(BAT_WIDTH, BAT_HEIGTH));
    rightbat.setPosition(WINDOW_WIDTH - BAT_WIDTH - BAT_OFFSET, (WINDOW_HEIGTH - BAT_HEIGTH) / 2);
    rightbat.setFillColor(RIGHT_BAT_COLOR);
    // Ìÿ÷ 
    CircleShape ball(BALL_RADIUS);
    ball.setPosition((WINDOW_WIDTH - 2 * BALL_RADIUS) / 2, (WINDOW_HEIGTH - 2 * BALL_RADIUS) / 2);
    ball.setFillColor(BALL_COLOR);
    float ball_speedx = 2.f;
    float ball_speedy = 3.f;

    // Ãëàâíûé öèêë ïðèëîæåíèÿ. Âûïîëíÿåòñÿ, ïîêà îòêðûòî îêíî
    while (window.isOpen())
    {


        // Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå
        Event event;
        while (window.pollEvent(event))
        {
            // Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
            if (event.type == Event::Closed)
                // òîãäà çàêðûâàåì åãî
                window.close();
        }
        
        //Левая ракетка 
        if (Keyboard::isKeyPressed(Keyboard::W)) 
        {
            leftbat.move( 0,-batDy); 
       }
        else if (Keyboard::isKeyPressed(Keyboard::S)) {
            leftbat.move(0, batDy); 
        }
        if (leftbat.getPosition().y < 0) {
            leftbat.setPosition(leftbat.getPosition().x, 0);
        }
        if (leftbat.getPosition().y + leftbat.getGlobalBounds().height > WINDOW_HEIGTH) {
            leftbat.setPosition(leftbat.getPosition().x, WINDOW_HEIGTH - leftbat.getGlobalBounds().height);
        }
       //Правая ракетка 
       // if (Keyboard::isKeyPressed(Keyboard::Up)) {
        //    rightbat.move(0,-batDy); 
       // }
      //  else if (Keyboard::isKeyPressed(Keyboard::Down)) {
        //    rightbat.move(0, batDy); 
       // }
       // if (rightbat.getPosition().y < 0) {
         //  rightbat.setPosition(rightbat.getPosition().x, 0);
      //  } 
        // МЯЧ
        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            ball.move(0, -batDy); 
        }
        if (Keyboard::isKeyPressed(Keyboard::Down)) {
            ball.move(0, batDy);
        } 
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            ball.move(batDx, 0);
        }
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            ball.move(-batDy, 0);
        }
        if (ball.getPosition().y < 0) {
            ball.setPosition(ball.getPosition().x, 0);
        } 
        if (ball.getPosition().x < 0) {
            ball.setPosition(0 ,ball.getPosition().y);
        }
        if (ball.getPosition().x + ball.getGlobalBounds().width > WINDOW_WIDTH) {
            ball.setPosition(WINDOW_WIDTH - ball.getGlobalBounds().width, ball.getPosition().y);
        } 
        if (ball.getPosition().y + ball.getGlobalBounds().height > WINDOW_HEIGTH) {
            ball.setPosition(ball.getPosition().x, WINDOW_HEIGTH - ball.getGlobalBounds().height);
        } 
        
     
        // îáíîâëåíèå îáúåêòîâ èãðû.
       /*ball.move(ball_speedx, ball_speedy);
        if (ball.getPosition().x <= 0 || (ball.getPosition().x + 2 * BALL_RADIUS) >= WINDOW_WIDTH)
        {
            ball_speedx = -ball_speedx;
        }

        if (ball.getPosition().y <= 0 || ball.getPosition().y + 2 * BALL_RADIUS >= WINDOW_HEIGTH)
        {
            ball_speedy = -ball_speedy;
        }*/
        // îòðèñîâêà îáúåêòîâ è îêíà.
        window.clear();
        window.draw(leftbat);
        window.draw(rightbat);
        window.draw(ball);




        // Îòðèñîâêà îêíà 
        window.display();
    }

    return 0;
}
