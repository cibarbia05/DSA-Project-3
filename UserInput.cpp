#include "UserInput.h"
#include "vector"
#include "set"

const std::vector<std::string> GENRE_NAMES = {
        "Unknown", "Action", "Adventure", "Animation", "Children's", "Comedy",
        "Crime", "Documentary", "Drama", "Fantasy", "Film-Noir", "Horror",
        "Musical", "Mystery", "Romance", "Sci-Fi", "Thriller", "War", "Western"
};
std::vector<std::string> askUserForGenres() {
    std::vector<std::string> likedGenres;
    std::set<int> selectedIndices; // Keep track of selected indices to prevent duplicates
    std::string input;
    bool keepAsking = true;

    std::cout << "Available genres:\n";
    for (size_t i = 1; i < GENRE_NAMES.size(); ++i) {
        std::cout << i << ": " << GENRE_NAMES[i] << "\n";
    }
    std::cout << "Enter the number corresponding to the genres you do not like. Enter 0 if you don't dislike any more genres.\n";

    while (keepAsking) {
        std::cout << "Your choice: ";
        std::cin >> input;

        try {
            int genreIndex = std::stoi(input);
            if (genreIndex == 0) {
                if(likedGenres.empty()){
                    std::cout << "You must not like at least one genere!" << std::endl;
                }
                else {
                    keepAsking = false;
                }
            } else if (genreIndex > 0 && static_cast<size_t>(genreIndex) < GENRE_NAMES.size()) {
                if (selectedIndices.find(genreIndex) != selectedIndices.end()) {
                    std::cout << "You have already added \"" << GENRE_NAMES[genreIndex] << "\" to your list. Choose another genre.\n";
                } else {
                    likedGenres.push_back(GENRE_NAMES[genreIndex]);
                    selectedIndices.insert(genreIndex);
                    std::cout << "Added \"" << GENRE_NAMES[genreIndex] << "\" to your dislike list.\n";
                }
            } else {
                std::cout << "Invalid choice. Please choose a number between 1 and " << GENRE_NAMES.size() - 1 << ", or 0 to stop.\n";
            }
        } catch (const std::invalid_argument&) {
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    }
    return likedGenres;
}

std::string toLowercase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}

// Function to validate yes or no input
bool validateYesNo(const std::string& input) {
    std::string lowercaseInput = toLowercase(input);
    return lowercaseInput == "y" || lowercaseInput == "yes" ||
           lowercaseInput == "n" || lowercaseInput == "no";
}

bool validateAge(int age) {
    return age >= 0 && age <= 120;
}

int getAgeInput() {
    int age;
    while (true) {
        //Check if input is a valid int
        if (std::cin >> age) {
            // Clear the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Validate age range
            if (validateAge(age)) {
                return age;
            }
        } else {
            // Clear error flags and input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << " Invalid age! Please enter a number between 0 and 120: ";
    }
}

bool validateNum(int num) {
    return num >= 1 && num <= 1644;
}

int getNumInput() {
    int num;
    while (true) {
        //Check if input is a valid int
        if (std::cin >> num) {
            // Clear the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            // Validate age range
            if (validateNum(num)) {
                return num;
            }
        } else {
            // Clear error flags and input buffer
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << " Invalid number! Please enter a number between 1 and 1644: ";
    }
}

// Function to get a validated yes/no input
std::string getYesNoInput() {
    std::string input;
    while (true) {
        std::getline(std::cin, input);

        // Remove leading and trailing whitespace
        input.erase(0, input.find_first_not_of(" \t"));
        input.erase(input.find_last_not_of(" \t") + 1);

        if (validateYesNo(input)) {
            return toLowercase(input);
        }

        std::cout << "❌ Invalid input! Please enter (Y)es or (N)o: ";
    }
}

// Function to display welcome ASCII art
void displayWelcomeArt() {
    std::cout << R"(
    ________________________________________
    |              Film Finders            |
    ________________________________________
)" << std::endl;
}

int userInput() {
    // Display welcome art
    displayWelcomeArt();
    std::cout << "Welcome to Film Finders! \nWe are dedicated to helping you find your best fit movie reccomendation.\nFirst lets get to know you!" << std::endl;

    // Variables to store user responses
    std::string name;
    std::string likesCoding;
    std::string preferredLanguage;
    int age;
    int option;

    // Introduction Question
    std::cout << "> What's your name? ";
    std::getline(std::cin, name);

    //name not empty
    while (name.empty() || name.find_first_not_of(" \t") == std::string::npos) {
        std::cout << " Please enter a valid name: ";
        std::getline(std::cin, name);
    }

    std::cout << "\n> Hi, " << name << "! How old are you?";
    age = getAgeInput();

    std::vector<std::string> userGenres = askUserForGenres();
    std::cout << "> Great picks " << name << "! Well take this into consideration." << std::endl;
    std::cout << "___________________________________________________________________________________________" << std::endl;

    // Second Yes/No Question
    std::cout << "\n> Now, Pick a number that represents how adventurous you're feeling today.\nThe lower the number, the more predictable your recommendation might be. ";
    int kth_choice = getNumInput();

    // Option Selection Question
    std::cout << "\n> Please choose your preferred option:" << std::endl;
    std::cout << "   1. Algo 1" << std::endl;
    std::cout << "   2. Algo 2" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    while (!(std::cin >> option) || (option != 1 && option != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << " Invalid input! Please enter 1 or 2: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::pair<int,int> choices;
    choices.first = kth_choice;
    choices.second = option;

    std::cout << "\n📊 Survey Results:" << std::endl;
    std::cout << "________________________________________" << std::endl;
    std::cout << "  Name: " << "name" << std::endl;
    std::cout << "  Reccomended Movie: " << std::endl;
    std::cout << "________________________________________" << std::endl;

    return 0;
}