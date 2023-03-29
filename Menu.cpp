#include "Menu.h"

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 5; i++) {
		target.draw(text[i], states);
	}
}

void Menu::clearText()
{
	for (int i = 0; i < 5; i++) {
		text[i].setString("");
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
		//this->text[i].setString("Welcome to the library!");
		this->text[i].setCharacterSize(20);
		this->text[i].setFillColor(sf::Color::Yellow);
		this->text[i].setPosition(300, 300 + (i * 30));
	}
	this->text[0].setString("Welcome to the library!");
	this->text[1].setString("1. Login");
	this->text[2].setString("2. Exit");



}

void Menu::updateString(char c)
{
	//if ((int)c > 5 || (int)c < 1) {
	//	return;
	//}
	if (menuState == MainMenu) {
		std::cout << atoi(&c) << std::endl;
		if ((MenuState)(atoi(&c)) == Login) {
			menuState = Login;
			this->text[0].setString("Input Username");
			for (int i = 1; i < 5; i++) {
				this->text[i].setString("");
			}
		}

	}
	else if (menuState == Login) {
		if ((int)c == 13) {
			//std::cout << "Enter" << std::endl;
			if (!enterPass) {
				enterPass = true;
				this->text[0].setString("Enter Password");
				this->text[1].setString("");
				return;
			}
			else {
				menuState = UserMenu;
				enterPass = false;
				this->text[0].setString("Welcome " + userName);
				this->text[1].setString("1. My Books");
				this->text[2].setString("2. Search Library");
				this->text[3].setString("3. Log Out");
				return;
			}
		}
		else if ((int)c == 8) {
			//std::cout << "Backspace\n";
			if (!enterPass) {
				std::string temp;
				if (userName.length() > 0) {
					for (int i = 0; i < userName.length() - 1; i++) {
						temp += userName[i];
					}
					this->text[1].setString(temp);
					userName = temp;
					return;
				}
			}
			else {
				std::string temp;
				if (password.length() > 0) {
					this->text[1].setString("");
					for (int i = 0; i < password.length() - 1; i++) {
						temp += password[i];
						this->text[1].setString(this->text[1].getString() + '*');
					}
					//this->text[1].setString(temp);
					password = temp;
					return;
				}
			}
			return;
		}
		if (!enterPass) {
			this->text[1].setString(this->text[1].getString() + c);
			this->userName += c;
		}
		else {
			this->text[1].setString(this->text[1].getString() + '*');
			this->password += c;
		}
		//std::cout << text[1].getString().toAnsiString() << std::endl;

	}
	else if (menuState == UserMenu) {
		if (atoi(&c) == 1) {
			menuState = MyBooks;
			clearText();
			this->text[0].setString("My Books");
			//Load loaned books here
		}
		else if(atoi(&c) == 2){
			menuState = Search;
			clearText();
			this->text[0].setString("Search the library");

		}
		else if (atoi(&c) == 3) {
			menuState = Logout;
			clearText();
			text[0].setString("Are you sure that you want to log out?");
			text[1].setString("1. Yes");
			text[2].setString("2. No");
		}
	}
	else if (menuState == Logout) {
		if (atoi(&c) == 1) {
			menuState = MainMenu;
			clearText();

			this->text[0].setString("Welcome to the library!");
			this->text[1].setString("1. Login");
			this->text[2].setString("2. Exit");
		}
		else if (atoi(&c) == 2) {
			menuState = UserMenu;
			enterPass = false;
			this->text[0].setString("Welcome " + userName);
			this->text[1].setString("1. My Books");
			this->text[2].setString("2. Search Library");
			this->text[3].setString("3. Log Out");

		}

	}
	else if (menuState == Search) {
		if ((int)c == 13) {
			//Search
			return;
		}
		else if((int)c == 8){
			std::string temp;
			if (searchTerm.length() > 0) {
				for (int i = 0; i < searchTerm.length() - 1; i++) {
					temp += searchTerm[i];
				}
				this->text[1].setString(temp);
				searchTerm = temp;
				return;
			}
		}
		this->text[1].setString(this->text[1].getString() + c);
		this->searchTerm += c;

	}

	//this->text.setString(this->text.getString() + c);
}
