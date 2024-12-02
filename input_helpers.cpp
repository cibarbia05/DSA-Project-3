//
// Created by Jason Snytte on 12/2/24.
//
#include "input_helpers.h"
#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int promptGenre() {
    cout << "Select your preferred genre by entering the corresponding number:\n";
    vector<string> genres = {
        "Action", "Adventure", "Animation", "Children's", "Comedy", "Crime",
        "Documentary", "Drama", "Fantasy", "Film-Noir", "Horror", "Musical",
        "Mystery", "Romance", "Sci-Fi", "Thriller", "War", "Western"
    };

    for (size_t i = 0; i < genres.size(); ++i) {
        cout << i + 1 << ". " << genres[i] << "\n";
    }

    int choice;
    while (true) {
        cout << "Enter the number of your choice: ";
        cin >> choice;

        if (cin.fail() || choice < 1 || choice > static_cast<int>(genres.size())) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number between 1 and " << genres.size() << ".\n";
        } else {
            cout << "You selected: " << genres[choice - 1] << "\n";
            return choice;
        }
    }
}

int promptDecade() {
    int decade;
    while (true) {
        cout << "Enter your preferred decade (1960, 1970, 1980, or 1990): ";
        cin >> decade;

        if (cin.fail() || (decade != 1960 && decade != 1970 && decade != 1980 && decade != 1990)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter one of the following decades: 1960, 1970, 1980, or 1990.\n";
        } else {
            cout << "You selected the " << decade << "s.\n";
            return decade;
        }
    }
}

int promptAge() {
    int age;
    while (true) {
        cout << "Enter your age: ";
        cin >> age;

        if (cin.fail() || age <= 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive integer for your age.\n";
        } else {
            cout << "You entered age: " << age << "\n";
            return age;
        }
    }
}