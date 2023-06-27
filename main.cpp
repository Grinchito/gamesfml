#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "GOTY");
    window.setFramerateLimit(60);

   
    sf::Sprite personaje;
    sf::Texture personaje_text;
    float velocity = 8;

    personaje_text.loadFromFile("Mario.png");
    personaje.setTexture(personaje_text);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
      //CMD-Joy
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            personaje.move(0, -velocity);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)||sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            personaje.move(-velocity,0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)||sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            personaje.move(0,velocity);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)||sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            personaje.move(velocity,0);
        }
        if (personaje.getPosition().x<0){
            personaje.setPosition(0,personaje.getPosition().y);
        }
        if (personaje.getPosition().y<0){
            personaje.setPosition(personaje.getPosition().x,0);
        }
        if (personaje.getPosition().x+personaje.getGlobalBounds().width>800){
            personaje.setPosition(800-personaje.getGlobalBounds().width, personaje.getPosition().y);
        }
        if (personaje.getPosition().y+personaje.getGlobalBounds().height>800){
            personaje.setPosition( personaje.getPosition().x,800-personaje.getGlobalBounds().height);
        }
        // Update - Actualiza los estados del juego


        window.clear();

        //dibujar
        window.draw(personaje);
        window.display();
    }



    return 0;
}