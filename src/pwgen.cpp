#include <list>
#include <string>

size_t GetRandNum();

std::list<std::string> GeneratePasswords(std::string charset, size_t pwlength, int pwcount);
std::string GeneratePassword(std::string charset, size_t pwlength);

std::list<std::string> GeneratePasswords(std::string charset, size_t pwlength, int pwcount)
{
    std::list<std::string> pwlist;
    for (; pwcount > 0; pwcount--) {
        pwlist.emplace_back(GeneratePassword(charset, pwlength));
    }
    return pwlist;
}

std::string GeneratePassword(std::string charset, size_t pwlength)
{
    std::string password;
    for (; pwlength > 0; pwlength--) {
        password += charset[GetRandNum() % charset.length()];
    }
    return password;
}
