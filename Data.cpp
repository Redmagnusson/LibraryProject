//class User {
//public:
//    std::string username;
//    std::vector<std::shared_ptr<Media>> borrowedMedia;
//
//    User(const std::string& username) : username(username) {}
//};
#include <string>
#include <fstream>
#include <sstream>
#include "user.h"
#include "Book.h"
#include "CD.h"
#include "Film.h"

class Data {
public:
    // Const
    Data(const std::string& userDataFilename, const std::string& libraryDataFilename)
        : userDataFile(userDataFilename), libraryDataFile(libraryDataFilename) {}

    

    void SaveUserData(/* std::string username, size_t password*/) {

        //Make this function take username as string and a password as size_t and save them to a new line
        //We want to call this function when we create a new account
        std::ofstream outFile(userDataFile);

        for (const auto& user : users) {
            outFile << user.getUsername() << std::endl;
            for (const auto& media : user.borrowedMedia) {
                outFile << media->type << "   " << media->title << "   " << media->getCreator() << std::endl;
            }
            outFile << "###" << std::endl;
        }

        outFile.close();
    }

    void LoadUserData(/*std::string username*/) {
        //Make this function search the userdata file and return the size_t password for a user
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
                        currentUser->getLoanedBooks().push_back(Book(tokens[1], tokens[2]));
                    } else if (tokens[0] == "CD") {
                        currentUser->getLoanedBooks().push_back(CD(tokens[1], tokens[2]));
                    } else if (tokens[0] == "Film") {
                        currentUser->getLoanedBooks().push_back(Film(tokens[1], tokens[2]));
                    }
                }
            }
        }

        inFile.close();
    }

    //Make a function to load all the media from the media text file into the vector ive called
    void loadMedia(std::vector<Media>& media) {

        //Template on how to add media
        // LoanedID is the username of the person that has loaned a book
        // If the book has NOT been loaned, make it "" or something
        // NEVER make a new Media object, only Film/CD/Book objects
        //media.push_back(Book(title, releaseYear, loanedID, author));
    }

    //Make a function that loads all books loaned by a user and inserts it into the vector called
    void loadLoanedMedia(std::vector<Media>& media) {

    }

private:
    std::string userDataFile;
    std::string libraryDataFile;
    //I dont think these 2 are needed for the new structure
    //std::vector<std::shared_ptr<Media>> library;
    //std::vector<User> users;
};
