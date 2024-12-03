
#include "userInput.h"

std::string toLowercase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return str;
}

// Function to validate yes or no inputt
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

        std::cout << "❌ Invalid age! Please enter a number between 0 and 120: ";
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
    ╔══════════════════════════════════════╗
    ║         🌟     Film Finders      🌟  ║
    ╚══════════════════════════════════════╝
)" << std::endl;
}

int userInput() {
    // Display welcome art
    displayWelcomeArt();
    std::cout << "Welcome to Film Finders! We are dedicated to helping you find your best fit movie reccomendation. First lets get to know you!" << std::endl;

    // Variables to store user responses
    std::string name;
    std::string likesCoding;
    std::string preferredLanguage;
    int age;
    int option;

    // Introduction Question
    std::cout << "➤ What's your name? ";
    std::getline(std::cin, name);

    //name not empty
    while (name.empty() || name.find_first_not_of(" \t") == std::string::npos) {
        std::cout << "❌ Please enter a valid name: ";
        std::getline(std::cin, name);
    }

    std::cout << "\n➤ Hi, " << name << "! How old are you? ";
    age = getAgeInput();

    // First Yes/No Question
    std::cout << "\n➤️ Hi, " << name << "! What generes do you like? (Y/N): ";
    likesCoding = getYesNoInput();

    // Second Yes/No Question
    std::cout << "\n➤ Another Question (Y/N): ";
    std::string interestedInProgramming = getYesNoInput();

    // Option Selection Question
    std::cout << "\n➤ Choose your preferred option:" << std::endl;
    std::cout << "   1. Algo 1" << std::endl;
    std::cout << "   2. Algo 2" << std::endl;
    std::cout << "Enter your choice (1 or 2): ";

    while (!(std::cin >> option) || (option != 1 && option != 2)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "❌ Invalid input! Please enter 1 or 2: ";
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Display Results
    std::cout << "\n📊 Survey Results:" << std::endl;
    std::cout << "╔══════════════════════════════════════╗" << std::endl;
    std::cout << "  Name: " << name << std::endl;
    std::cout << "  Reccomended Movie: "
              << (option == 1 ? "Web Development" : "Super Cool Movie Name") << std::endl;
    std::cout << "╚══════════════════════════════════════╝" << std::endl;

    return 0;
}

