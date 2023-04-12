#include "Menu.h"
#include "Media.h"
#include "CD.h"
void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < 5; i++) {
		target.draw(text[i], states);
	}
	target.draw(text[5], states);
	if (menuState != Logout && menuState != Search) {
		target.draw(text[6], states);

	}


	for (int i = 0; i < 5; i++) {
		if (menuState == LibraryContent) {
			target.draw(rect[i], states);
		}
	}
	if (menuState == MyBooks || menuState == SearchContent) {
		for (int i = 0; i < 5;i++) {
			if (i < searchMedia->size()) {
				target.draw(rect[i], states);
			}
		}
	}
}

void Menu::clearText()
{
	for (int i = 0; i < 6; i++) {
		text[i].setString("");
		this->text[i].setPosition(50, 50 + (i * 30));
	}
}

Menu::Menu(sf::Event* event, Library* lib)
{
	this->event = event;
	if (!font.loadFromFile("arial.ttf")) {
		std::cout << "Could not load font" << std::endl;
	}
	for (int i = 0; i < 7; i++) {
		this->text[i].setFont(font);
		//this->text[i].setString("Welcome to the library!");
		this->text[i].setCharacterSize(20);
		this->text[i].setFillColor(sf::Color::White);
		this->text[i].setPosition(50, 50 + (i * 30));
	}
	this->text[6].setPosition(800, 550);
	this->text[6].setString("0. Exit");
	this->text[0].setString("Welcome to the library!");
	this->text[1].setString("1. Login");
	//this->text[2].setString("2. Exit");

	this->lib = lib;

	//this->texture.loadFromFile("sempiternal.jpg");
	//this->rect.setTexture(&texture);
	
	for (int i = 0; i < 5; i++) {
		this->texture[i].loadFromFile("sempiternal.jpg");
		this->rect[i].setSize(sf::Vector2f(60, 60));
		this->rect[i].setPosition(100, 175 + (i * 65));
		this->rect[i].setTexture(&texture[i]);

	}
	//this->rect.setPosition(0, 0);

	this->allMedia = lib->getVector();
	this->searchMedia = new std::vector<Media*>;
}

void Menu::forceLogout()
{
	menuState = ForcedLogout;
	clearText();
	searchMedia->clear();
	this->text[0].setString("You were logged out due to inactivity");
	this->text[1].setString("1. Back to Main Menu");
	//this->text[2].setString("2. Exit");
}

int Menu::updateString(char c)
{
	//if ((int)c > 5 || (int)c < 1) {
	//	return;
	//}
	if (menuState == MainMenu) {
		//std::cout << atoi(&c) << std::endl;
		if ((MenuState)(atoi(&c)) == Login) {
			userName = "";
			password = "";
			menuState = Login;
			clearText();
			this->text[0].setString("Input Username");
		}
		if ((atoi(&c)) == 0) {
			return -1;
		}
	}
	else if (menuState == Login) {
		if ((int)c == 13) {
			//std::cout << "Enter" << std::endl;
			if (!enterPass) {
				enterPass = true;
				this->text[0].setString("Enter Password");
				this->text[1].setString("");
				return 0;
			}
			else {
				//TODO do proper login
				//Get hashkey from password
				size_t hashKey = hash(password);
				std::cout << hashKey << std::endl;
				//Check if key is same as from file
				for (auto it = map->begin(); it != map->end(); it++) {
					if (it->first == userName && it->second == hashKey) {
						std::cout << "Successful Login\n";
						//If true, log in
						menuState = UserMenu;
						enterPass = false;
						this->text[0].setString("Welcome " + userName);
						this->text[1].setString("1. My Media");
						this->text[2].setString("2. See Library");
						this->text[3].setString("3. Search Library");
						//this->text[4].setString("4. Log Out");
						return 0;
					}
				}


				//If false, redo?
				std::cout << "Failed login attempt\n";
				userName = "";
				password = "";
				enterPass = false;
				menuState = Login;
				clearText();
				this->text[0].setString("Invalid login, try again");
				return 0;
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
					return 0;
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
					return 0;
				}
			}
			return 0;
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
			vectorTop = 0;
			clearText();
			this->text[0].setString("My Media");
			for (int i = 0; i < allMedia->size(); i++) {
				if (allMedia->at(i)->getLoanedID() == userName) {
					searchMedia->push_back(allMedia->at(i));
				}
			}
			for (int i = 0; i < 5; i++) {
				if (i < searchMedia->size()) {
					this->text[i + 1].setString(std::to_string(i + 1) + ". " + searchMedia->at(i)->toString());
					this->texture[i].loadFromFile(searchMedia->at(i)->getTitle() + ".jpg");
					this->rect[i].setTexture(&texture[i]);
					this->text[i + 1].setPosition(175, 190 + (i * 65));
				}

			}
		}
		else if (atoi(&c) == 2) {
			menuState = LibraryContent;
			clearText();
			this->text[0].setString("Library Contents");
			for (int i = 0; i < 5; i++) {
				this->text[i + 1].setString(std::to_string(i+1)+ ". " + allMedia->at(i)->toString());
				this->texture[i].loadFromFile(allMedia->at(i)->getTitle() + ".jpg");
				this->rect[i].setTexture(&texture[i]);
				this->text[i+1].setPosition(175, 190+ (i * 65));

			}
			//this->text[1].setString(lib->getVector()->at(0)->toString());
		}
		else if(atoi(&c) == 3){
			menuState = Search;
			clearText();
			this->text[0].setString("Search the library");

		}
		else if (atoi(&c) == 0) {
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
			//this->text[2].setString("2. Exit");
		}
		else if (atoi(&c) == 0) {
			menuState = UserMenu;
			enterPass = false;
			this->text[0].setString("Welcome " + userName);
			this->text[1].setString("1. My Media");
			this->text[2].setString("2. See Library");
			this->text[3].setString("3. Search Library");
			//this->text[4].setString("4. Log Out");

		}

	}
	else if (menuState == Search) {
		if ((int)c == 13) {
			//TODO Call search function
			this->searchMedia = lib->searchMedia(searchTerm);
			menuState = SearchContent;
			searchTerm = "";
			clearText();
			this->text[0].setString("We found " + std::to_string(searchMedia->size()) + " results");
			for (int i = 0; i < 5; i++) {
				if (i < searchMedia->size()) {
					texture[i].loadFromFile(searchMedia->at(i)->getTitle() + ".jpg");
					rect[i].setTexture(&texture[i]);
					text[i + 1].setString(std::to_string(i+1) + ". " + searchMedia->at(i)->toString());
					this->text[i + 1].setPosition(175, 190 + (i * 65));
				}
			}
			return 0;
		}
		else if((int)c == 8){
			std::string temp;
			if (searchTerm.length() > 0) {
				for (int i = 0; i < searchTerm.length() - 1; i++) {
					temp += searchTerm[i];
				}
				this->text[1].setString(temp);
				searchTerm = temp;
				return 0;
			}
		}
		this->text[1].setString(this->text[1].getString() + c);
		this->searchTerm += c;

	}
	else if (menuState == ForcedLogout) {
		if (atoi(&c) == 1) {
			menuState = MainMenu;
			clearText();

			this->text[0].setString("Welcome to the library!");
			this->text[1].setString("1. Login");
			//this->text[2].setString("2. Exit");
		}
		else if (atoi(&c) == 0) {
			return -1;
		}
	}
	else if (menuState == LibraryContent) {
		//TODO RENTING AND EXIT
		if (c == 'w' || c == 'W') {
			//std::cout << "w pressed";
			if (vectorTop != 0) {
				vectorTop--;
				for (int i = 0; i < 5; i++) {
					this->text[i + 1].setString(std::to_string(i+1) + ". " + allMedia->at(i + vectorTop)->toString());
					//TODO FIX TEXTURE
					this->texture[i].loadFromFile(allMedia->at(i + vectorTop)->getTitle() + ".jpg");
					this->rect[i].setTexture(&texture[i]);
				}
			}
		}
		else if (c == 's' || c == 'S') {
			//std::cout << "s pressed\n";
			if (vectorTop != allMedia->size() - 5) {
				vectorTop++;
				for (int i = 0; i < 5; i++) {
					this->text[i + 1].setString(std::to_string(i+1) + ". " + allMedia->at(i + vectorTop)->toString());
					//TODO FIX TEXTURE
					this->texture[i].loadFromFile(allMedia->at(i + vectorTop)->getTitle() + ".jpg");
					this->rect[i].setTexture(&texture[i]);
				}
			}
		}
		else if (atoi(&c) > 0 && atoi(&c) < 6) {
			allMedia->at(vectorTop + atoi(&c)-1)->setLoanedID(userName);
		}
		else if (atoi(&c) == 0) {
			menuState = UserMenu;
			clearText();
			enterPass = false;
			this->text[0].setString("Welcome " + userName);
			this->text[1].setString("1. My Media");
			this->text[2].setString("2. See Library");
			this->text[3].setString("3. Search Library");
			//this->text[4].setString("4. Log Out");
		}
	}
	else if (menuState == MyBooks) {
		if (c == 'w' || c == 'W') {
			//std::cout << "w pressed";
			if (vectorTop != 0) {
				vectorTop--;
				for (int i = 0; i < 5; i++) {
					if (i < searchMedia->size()) {
						this->text[i + 1].setString(std::to_string(i + 1) + ". " + searchMedia->at(i + vectorTop)->toString());
						//TODO FIX TEXTURE
						this->texture[i].loadFromFile(searchMedia->at(i + vectorTop)->getTitle() + ".jpg");
					}
				}
			}
		}
		else if (c == 's' || c == 'S') {
			//std::cout << "s pressed\n";
			int temp = searchMedia->size() - 5;
			if (vectorTop < temp) {
				vectorTop++;
				for (int i = 0; i < 5; i++) {
					if (i < searchMedia->size()) {
						this->text[i + 1].setString(std::to_string(i + 1) + ". " + searchMedia->at(i + vectorTop)->toString());
						//TODO FIX TEXTURE
						this->texture[i].loadFromFile(searchMedia->at(i + vectorTop)->getTitle() + ".jpg");
					}
				}
			}
		}
		else if (atoi(&c) > 0 && atoi(&c) < 6) {
			if (atoi(&c)-1 < searchMedia->size()) {
				searchMedia->at(vectorTop + atoi(&c) - 1)->setLoanedID("ID");
				std::cout << searchMedia->at(vectorTop + atoi(&c) - 1)->toString() << " now has loanedID:" << searchMedia->at(vectorTop + atoi(&c) - 1)->getLoanedID() << std::endl;
			}
		}
		else if (atoi(&c) == 0) {
			searchMedia->clear();
			menuState = UserMenu;
			clearText();
			enterPass = false;
			this->text[0].setString("Welcome " + userName);
			this->text[1].setString("1. My Media");
			this->text[2].setString("2. See Library");
			this->text[3].setString("3. Search Library");
			//this->text[4].setString("4. Log Out");
		}
	}
	else if (menuState == SearchContent) {
		//TODO RENTING AND EXIT
		if (c == 'w' || c == 'W') {
			//std::cout << "w pressed";
			if (vectorTop != 0) {
				vectorTop--;
				for (int i = 0; i < 5; i++) {
					this->text[i + 1].setString(std::to_string(i + 1) + ". " + searchMedia->at(i + vectorTop)->toString());
					//TODO FIX TEXTURE
					this->texture[i].loadFromFile(searchMedia->at(i + vectorTop)->getTitle() + ".jpg");
					this->rect[i].setTexture(&texture[i]);
				}
			}
		}
		else if (c == 's' || c == 'S') {
			//std::cout << "s pressed\n";
			if (vectorTop != searchMedia->size() - 5) {
				vectorTop++;
				for (int i = 0; i < 5; i++) {
					this->text[i + 1].setString(std::to_string(i + 1) + ". " + searchMedia->at(i + vectorTop)->toString());
					//TODO FIX TEXTURE
					this->texture[i].loadFromFile(searchMedia->at(i + vectorTop)->getTitle() + ".jpg");
					this->rect[i].setTexture(&texture[i]);
				}
			}
		}
		else if (atoi(&c) > 0 && atoi(&c) < 6) {
			searchMedia->at(vectorTop + atoi(&c) - 1)->setLoanedID(userName);
		}
		else if (atoi(&c) == 0) {
			searchMedia->clear();
			menuState = UserMenu;
			clearText();
			enterPass = false;
			this->text[0].setString("Welcome " + userName);
			this->text[1].setString("1. My Media");
			this->text[2].setString("2. See Library");
			this->text[3].setString("3. Search Library");
			//this->text[4].setString("4. Log Out");
		}
	}
	return 0;
	//this->text.setString(this->text.getString() + c);
}
