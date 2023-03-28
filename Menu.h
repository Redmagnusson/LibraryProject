#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Menu : public sf::Drawable
{
private:
	sf::Text text[5];
	sf::Font font;
	sf::Event* event;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;

public:
	Menu(sf::Event *event);

	void updateString(char c);

};