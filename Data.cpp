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

    // Other functions ...

    void loadMedia(std::vector<std::shared_ptr<Media>>& media) {
        std::ifstream inFile(libraryDataFile);
        std::string line;

        while (std::getline(inFile, line)) {
            std::stringstream ss(line);
            std::string type, title, creator, loanedID;
            int releaseYear;

            ss >> type >> title >> releaseYear >> loanedID >> creator;

            if (type == "Book") {
                media.push_back(std::make_shared<Book>(title, releaseYear, loanedID, creator));
            } else if (type == "CD") {
                media.push_back(std::make_shared<CD>(title, releaseYear, loanedID, creator));
            } else if (type == "Film") {
                media.push_back(std::make_shared<Film>(title, releaseYear, loanedID, creator));
            }
        }

        inFile.close();
    }

    void loadLoanedMedia(const std::string& username, std::vector<std::shared_ptr<Media>>& media) {
        std::vector<std::shared_ptr<Media>> allMedia;
        loadMedia(allMedia);

        for (const auto& item : allMedia) {
            if (item->getLoanedID() == username) {
                media.push_back(item);
            }
        }
    }

private:
    std::string userDataFile;
    std::string libraryDataFile;
};
