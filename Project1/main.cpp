#include<SFML/Graphics.hpp>
#include<iostream>

int main()
{
	//declaring
	sf::RenderWindow window;
	sf::Texture backTex;
	sf::Sprite Background;
	sf::Texture lighttex;
	sf::Sprite light;
	sf::IntRect currentframe;
	sf::Clock animationTimer;

	//initializing
	backTex.loadFromFile("background.png");
	Background.setTexture(backTex);
    lighttex.loadFromFile("Test Sprite 3.png");
	light.setTexture(lighttex);
	currentframe = sf::IntRect(0, 0, 400, 400);
	light.setTextureRect(currentframe);
	animationTimer.restart();

	window.create(sf::VideoMode(1280, 720), "Test Animation");
	sf::Event event;

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				currentframe.top += 200.f;
			}
		}
		if (animationTimer.getElapsedTime().asSeconds() >= 0.03f)
		{
			currentframe.left += 400.f;
			if (currentframe.left >= 4000.f)
			{
				currentframe.left = 0.f;
			}
			animationTimer.restart();
			light.setTextureRect(currentframe);
		}
		window.clear();
		window.draw(Background);
		window.draw(light);
		window.display();
	}
}