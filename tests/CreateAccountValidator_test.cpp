#include <gtest/gtest.h>
#include "CreateAccountValidator.h"

// First name
TEST(FirstName, Empty)    { EXPECT_FALSE(CreateAccountValidator::isValidFirstName("")); }
TEST(FirstName, Simple)   { EXPECT_TRUE(CreateAccountValidator::isValidFirstName("Serkan")); }
TEST(FirstName, Numeric)  { EXPECT_FALSE(CreateAccountValidator::isValidFirstName("Ali123")); }

// Email
TEST(Email, Valid)   { EXPECT_TRUE(CreateAccountValidator::isValidEmail("ali@example.com")); }
TEST(Email, NoAt)    { EXPECT_FALSE(CreateAccountValidator::isValidEmail("plainaddress")); }

// Password
TEST(Password, Valid)       { EXPECT_TRUE(CreateAccountValidator::isValidPassword("Abcd1234!")); }
TEST(Password, Short)       { EXPECT_FALSE(CreateAccountValidator::isValidPassword("A1!a1!")); }

// Date of Birth
TEST(DOB, Valid)    { EXPECT_TRUE(CreateAccountValidator::isValidDateOfBirth("15/04/1995")); }
TEST(DOB, Invalid)  { EXPECT_FALSE(CreateAccountValidator::isValidDateOfBirth("32/13/2020")); }
