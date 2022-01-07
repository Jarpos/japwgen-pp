#include "consts.hpp"

#include <string>
#include <system_error>

void SetOption(int& option, const char* argv[], int argc, int i);
void SetOption(std::string& option, const char* argv[], int argc, int i);

void ParseArgs(options& opts, int argc, const char* argv[])
{
    std::string arg;
    for (int i = 1; i < argc; i++) {
        SetOption(arg, argv, argc, i);

        if (arg == "--alphabet" || arg == "-a") {
            SetOption(opts.alphabet, argv, argc, ++i);
        } else if (arg == "--count" || arg == "-c") {
            SetOption(opts.pwcnt, argv, argc, ++i);
        } else if (arg == "--length" || arg == "-l") {
            SetOption(opts.pwlen, argv, argc, ++i);
        } else if (arg == "--help" || arg == "-h") {
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
