#include "consts.hpp"

#include <iostream>
#include <list>
#include <string>

std::list<std::string> GeneratePasswords(std::string charset, size_t len, int count);
std::string GeneratePassword(std::string charset, size_t pwlength);
void ParseArgs(options& opts, int argc, const char* argv[]);

void PrintHelp();

int main(int argc, char const* argv[])
{
    options opts;
    if (argc > 1) {
        ParseArgs(opts, argc, argv);
        if (opts.help) {
            PrintHelp();
            return EXIT_SUCCESS;
        }
    }

    std::list<std::string> pws = GeneratePasswords(opts.alphabet, opts.pwlen, opts.pwcnt);

    int i = 1;
    for (const auto& pw : pws) {
        std::cout << pw << " ";
        if (i++ % BREAK_AFTER == 0) {
            std::cout << "\n";
        }
    }

    return EXIT_SUCCESS;
}

void PrintHelp()
{
    std::printf("Usage: japwgen-pp [ OPTIONS ]\n");
    std::printf("\n");
    std::printf("Options:\n");
    std::printf("\t--help\n");
    std::printf("\t    Displays this message\n");
    std::printf("\t--alphabet [ ALPHABET ]\n");
    std::printf("\t    Specify alternative alphabet to use for pw generation\n");
    std::printf("\t--count [ NUMBER ]\n");
    std::printf("\t    Specify amount of generated passwords\n");
    std::printf("\t--length [ NUMBER ]\n");
    std::printf("\t    Specify length of each generated password\n");
}
