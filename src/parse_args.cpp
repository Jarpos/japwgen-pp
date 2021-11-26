#include "consts.hpp"

#include <string>

void ParseArgs(options& opts, int argc, const char* argv[])
{
    for (int i = 1; i < argc; i++) {
        if (argv[i] == std::string("--alphabet")) {
            opts.alphabet = argv[++i];

        } else if (argv[i] == std::string("--count")) {
            opts.pwcnt = std::stoi(argv[++i]);

        } else if (argv[i] == std::string("--length")) {
            opts.pwlen = std::stoi(argv[++i]);

        } else if (argv[i] == std::string("--help")) {
            opts.help = true;
        }
    }
}
