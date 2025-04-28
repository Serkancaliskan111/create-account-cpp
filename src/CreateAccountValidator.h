#pragma once
#include <string>

class CreateAccountValidator {
public:
  static bool isValidFirstName(const std::string&);
  static bool isValidLastName(const std::string&);
  static bool isValidEmail(const std::string&);
  static bool isValidPassword(const std::string&);
  static bool isMatchingPasswords(const std::string& pw, const std::string& confirm);
  static bool isValidDateOfBirth(const std::string& dob); // dd/mm/yyyy
};
