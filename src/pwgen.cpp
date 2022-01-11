#include <list>
#include <string>

size_t GetRandNum();

std::list<std::string> GeneratePasswords(const std::string& charset, size_t len, int count);
std::string GeneratePassword(const std::string& charset, size_t pwlength);

std::list<std::string> GeneratePasswords(const std::string& charset, size_t len, int count)
{
    std::list<std::string> passwords;
    for (; count > 0; count--) {
        passwords.emplace_back(GeneratePassword(charset, len));
    }
    return passwords;
}

std::string GeneratePassword(const std::string& charset, size_t pwlength)
{
    std::string password;
    for (; pwlength > 0; pwlength--) {
        password += charset[GetRandNum() % charset.length()];
    }
    return password;
}
