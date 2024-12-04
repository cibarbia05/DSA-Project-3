#include "User.h"

User::User(int id, int userAge, const std::string& userGender,
           const std::string& userOccupation, const std::string& userZipCode)
        : userId(id), age(userAge), gender(userGender),
          occupation(userOccupation), zipCode(userZipCode) {}

int User::getUserId() const { return userId; }

int User::getAge() const { return age; }

int User::getGender() const {
    if (gender == "M")
        return 1;
    return 0;
}

std::string User::getOccupation() const { return occupation; }
std::string User::getZipCode() const { return zipCode; }

void User::printUser() const {
    std::cout << "User ID: " << userId
              << ", Age: " << age
              << ", Gender: " << gender
              << ", Occupation: " << occupation
              << ", Zip Code: " << zipCode << std::endl;
}