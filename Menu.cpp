#include "Menu.h"

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 5; i++) {
		target.draw(text[i], states);
	}
}

Menu::Menu(sf::Event* event)
{
	this->event = event;
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Could not load font" << std::endl;
	}
	for (int i = 0; i < 5; i++) {
		this->text[i].setFont(font);
		this->text[i].setString("Welcome to the library!");
		this->text[i].setCharacterSize(20);
		this->text[i].setFillColor(sf::Color::Yellow);
		this->text[i].setPosition(300, 300 + (i * 30));
	}
}

void Menu::updateString(char c)
{
	//this->text.setString(this->text.getString() + c);
}
