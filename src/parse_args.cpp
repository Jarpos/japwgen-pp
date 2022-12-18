#include "consts.hpp"

#include <string>
#include <system_error>

std::string parse_alphabet(const std::string& in);

void SetOption(int& option, const char* argv[], int argc, int i);
void SetOption(std::string& option, const char* argv[], int argc, int i);

void ParseArgs(options& opts, int argc, const char* argv[])
{
    std::string arg;
    for (int i = 1; i < argc; i++) {
        SetOption(arg, argv, argc, i);

        /****/ if (arg == "-a" || arg == "--alphabet") {
            SetOption(opts.alphabet, argv, argc, ++i);
            opts.alphabet = parse_alphabet(opts.alphabet);
        } else if (arg == "-c" || arg == "--count") {
            SetOption(opts.pwcnt, argv, argc, ++i);
        } else if (arg == "-l" || arg == "--length") {
            SetOption(opts.pwlen, argv, argc, ++i);
        } else if (arg == "-h" || arg == "--help") {
            opts.help = true;
        }
    }
}

void SetOption(int& option, const char* argv[], int argc, int i)
{
    // Use standard value if index is out of bounds
    if (i < argc) {
        try {
            option = std::stoi(argv[i]);
        } catch (...) {
            // Ignore Exception, and just use the standard value
        }
    }
}

void SetOption(std::string& option, const char* argv[], int argc, int i)
{
    // Use standard value if index is out of bounds
    if (i < argc) {
        option = argv[i];
    }
}
