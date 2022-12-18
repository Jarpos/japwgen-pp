#include <string>

inline constexpr char NUMBERS[] = "0123456789";
inline constexpr char UPPER_ALPH[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline constexpr char LOWER_ALPH[] = "abcdefghijklmnopqrstuvwxyz";

std::string parse_alphabet(const std::string& in)
{
    std::string out;
    for (int i = 0; i < in.length(); i++) {
        switch (in[i]) {
        case '[': {
            if /**/ (in[i + 1] == 'a' && in[i + 2] == ']')
                out += LOWER_ALPH;
            else if (in[i + 1] == 'A' && in[i + 2] == ']')
                out += UPPER_ALPH;
            else
                out += in[i + 1];

            i += 2;
            break;
        }

        case '\\': {
            out += in[i + 1];
            i++;
            break;
        }

        default: out += in[i]; break;
        }
    }

    return out;
}
