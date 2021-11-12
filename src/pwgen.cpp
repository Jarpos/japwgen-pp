#include <list>
#include <string>

size_t GetRandNum();

std::list<std::string> GeneratePasswords(std::string charset, size_t len, int count);
std::string GeneratePassword(std::string charset, size_t pwlength);

std::list<std::string> GeneratePasswords(std::string charset, size_t len, int count)
{
    std::list<std::string> pwlist;
    for (; count > 0; count--) {
        pwlist.emplace_back(GeneratePassword(charset, len));
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
