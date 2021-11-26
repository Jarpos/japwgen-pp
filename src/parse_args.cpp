#include "consts.hpp"

#include <string>

void ParseArgs(options& opts, int argc, const char* argv[])
{
    for (int i = 1; i < argc; i++) {
        std::string arg = argv[i];

        if (arg == "--alphabet") {
            opts.alphabet = argv[++i];
        } else if (arg == "--count") {
            opts.pwcnt = std::stoi(argv[++i]);
        } else if (arg == "--length") {
            opts.pwlen = std::stoi(argv[++i]);
        } else if (arg == "--help") {
            opts.help = true;
        }
    }
}
