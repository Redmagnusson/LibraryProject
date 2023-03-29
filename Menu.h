#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Menu : public sf::Drawable
{
private:
	enum MenuState {
		MainMenu, Login, Logout, UserMenu, MyBooks, Search
	};
	bool enterPass = false;
	MenuState menuState = MainMenu;
	std::string userName;
	std::string password;
	std::string searchTerm;
	sf::Text text[5];
	sf::Font font;
	sf::Event* event;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void clearText();
public:
	Menu(sf::Event *event);
	void updateString(char c);

};