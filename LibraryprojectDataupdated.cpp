class User {
public:
    std::string username;
    std::vector<std::shared_ptr<Media>> borrowedMedia;

    User(const std::string& username) : username(username) {}
};

class Data {
public:
    // Const
    Data(const std::string& userDataFilename, const std::string& libraryDataFilename)
        : userDataFile(userDataFilename), libraryDataFile(libraryDataFilename) {}

    

    void SaveUserData() {
        std::ofstream outFile(userDataFile);

        for (const auto& user : users) {
            outFile << user.username << std::endl;
            for (const auto& media : user.borrowedMedia) {
                outFile << media->type << "   " << media->title << "   " << media->getCreator() << std::endl;
            }
            outFile << "###" << std::endl;
        }

        outFile.close();
    }

    void LoadUserData() {
        std::ifstream inFile(userDataFile);
        std::string line;

        User* currentUser = nullptr;

        while (std::getline(inFile, line)) {
            if (line == "###") {
                currentUser = nullptr;
            } else if (currentUser == nullptr) {
                users.push_back(User(line));
                currentUser = &users.back();
            } else {
                std::vector<std::string> tokens;
                std::string token;
                size_t pos = 0;

                while ((pos = line.find("   ")) != std::string::npos) {
                    token = line.substr(0, pos);
                    tokens.push_back(token);
                    line.erase(0, pos + 3);
                }
                tokens.push_back(line);

                if (tokens.size() == 3) {
                    if (tokens[0] == "Book") {
                        currentUser->borrowedMedia.push_back(std::make_shared<Book>(tokens[1], tokens[2]));
                    } else if (tokens[0] == "CD") {
                        currentUser->borrowedMedia.push_back(std::make_shared<CD>(tokens[1], tokens[2]));
                    } else if (tokens[0] == "Film") {
                        currentUser->borrowedMedia.push_back(std::make_shared<Film>(tokens[1], tokens[2]));
                    }
                }
            }
        }

        inFile.close();
    }

private:
    std::string userDataFile;
    std::string libraryDataFile;
    std::vector<std::shared_ptr<Media>> library;
    std::vector<User> users;
};
