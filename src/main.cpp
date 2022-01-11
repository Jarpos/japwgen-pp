#include "consts.hpp"

#include <filesystem>
#include <iostream>
#include <list>
#include <string>

std::list<std::string> GeneratePasswords(const std::string& charset, size_t len, int count);
void ParseArgs(options& opts, int argc, const char* argv[]);

void PrintHelp(const char* progname);

int main(int argc, char const* argv[])
{
    options opts;
    if (argc > 1) {
        ParseArgs(opts, argc, argv);
        if (opts.help) {
            auto p = std::filesystem::path(argv[0]);
            PrintHelp(p.stem().c_str());
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

void PrintHelp(const char* progname)
{
    const options o; // Use default values for example
    std::printf("Usage: %s [ OPTIONS ]\n", progname);
    std::printf("Example: %s ", progname);
    std::printf("-c %d -l %d ", o.pwcnt, o.pwlen);
    std::printf("--alphabet %s\n", o.alphabet.c_str());
    std::printf("\n");

    std::printf("Options:\n");
    std::printf("    -h|--help\n");
    std::printf("      Displays this message\n");
    std::printf("    -a|--alphabet [ ALPHABET ]\n");
    std::printf("      Specify alternative alphabet to use for pw generation\n");
    std::printf("    -c|--count [ NUMBER ]\n");
    std::printf("      Specify amount of generated passwords\n");
    std::printf("    -l|--length [ NUMBER ]\n");
    std::printf("      Specify length of each generated password\n");
}
