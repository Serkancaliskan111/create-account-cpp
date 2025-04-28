#include "CreateAccountValidator.h"
#include <regex>
#include <ctime>
#include <cctype>

bool CreateAccountValidator::isValidFirstName(const std::string& s) {
  if (s.empty() || s.size() > 50) return false;
  for (char c : s)
    if (!(std::isalpha((unsigned char)c) || c==' ')) return false;
  return true;
}
bool CreateAccountValidator::isValidLastName(const std::string& s) {
  return isValidFirstName(s);
}
bool CreateAccountValidator::isValidEmail(const std::string& s) {
  static const std::regex re(R"(^[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,}$)");
  return std::regex_match(s, re);
}
bool CreateAccountValidator::isValidPassword(const std::string& s) {
  if (s.size() < 8) return false;
  bool u=false,l=false,d=false,sp=false;
  for (char c : s) {
    if (std::isupper((unsigned char)c)) u=true;
    else if (std::islower((unsigned char)c)) l=true;
    else if (std::isdigit((unsigned char)c)) d=true;
    else sp=true;
  }
  return u&&l&&d&&sp;
}
bool CreateAccountValidator::isMatchingPasswords(const std::string& pw, const std::string& c) {
  return pw==c;
}
bool CreateAccountValidator::isValidDateOfBirth(const std::string& dob) {
  int day,mon,year;
  if (std::sscanf(dob.c_str(), "%2d/%2d/%4d", &day, &mon, &year) != 3) return false;
  if (year<1900||mon<1||mon>12||day<1) return false;
  static int mdays[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
  bool leap=(year%400==0)||(year%4==0&&year%100!=0);
  int maxd = (mon==2&&leap?29:mdays[mon]);
  if (day>maxd) return false;
  std::time_t t=time(nullptr);
  std::tm* now=std::localtime(&t);
  int cy=now->tm_year+1900, cm=now->tm_mon+1, cd=now->tm_mday;
  if (year>cy||(year==cy&&(mon>cm||(mon==cm&&day>cd)))) return false;
  return true;
}
