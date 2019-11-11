#include "Player.cpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <ctime>
#include <iostream>
#include <list>
#include <string>
#include <unistd.h>

int main(void) {

    Player *player = new Player("신현석", "2015906051");

    list<string> temp = player->getAttackWord();
    list<string>::iterator iter;
    list<sf::Text> templist;
    list<sf::Text>::iterator sfiter;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works");
    sf::Text text;
    sf::Font font;
    font.loadFromFile("NANUMGOTHICLIGHT.TTF");
    text.setFont(font);
    int i = 0;

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::White);

    text.setString((char)65);

    templist.push_back(text);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        /*
                int totalSeconds = time(0);
                int currentSecond = totalSeconds%60
        */

        for (sfiter = templist.begin(); sfiter != templist.end();
             ++sfiter, i += 30) {
            window.draw(*sfiter);
            text.setPosition(10, 10 + i);
        }
        window.display();
    }

    return 0;
}
