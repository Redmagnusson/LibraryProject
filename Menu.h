#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Lib.h"
#include "Media.h"
#include "CD.h"
#include <unordered_map>
class Menu : public sf::Drawable
{
private:
	enum MenuState {
		MainMenu, Login, Logout, UserMenu, MyBooks, LibraryContent, Search, SearchContent, ForcedLogout
	};
	bool enterPass = false;
	int vectorTop = 0;
	MenuState menuState = MainMenu;
	std::string userName;
	std::string password;
	std::string searchTerm;
	Library* lib;
	std::hash<std::string> hash;
	std::map<std::string, size_t>* map;

	std::vector<Media*>* searchMedia;
	std::vector<Media*>* allMedia;

	//SFML Variables
	sf::Text text[7];
	sf::Font font;
	sf::Event* event;
	sf::Texture texture[5];
	sf::RectangleShape rect[5];


	virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	void clearText();
public:
	Menu(sf::Event *event, Library* lib);
	void forceLogout();
	int updateString(char c);
	void setMap(std::map<std::string, size_t> *map) { this->map = map; }

};