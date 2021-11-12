#include "consts.hpp"

#include <iostream>
#include <list>
#include <string>

std::list<std::string> GeneratePasswords(std::string charset, size_t len, int count);
std::string GeneratePassword(std::string charset, size_t pwlength);

void PrintHelp();

int main(int argc, char const* argv[])
{
    int i = 1;
    std::list<std::string> pws = GeneratePasswords(ALPHABET, 10, 10 * 10);
    for (auto& pw : pws) {
        std::cout << pw << " ";
        if (i++ % 5 == 0) {
            std::cout << "\n";
        }
    }
    return 0;
}

void PrintHelp()
{
    std::printf("Usage: japwgen-pp [ OPTIONS ]");
}
