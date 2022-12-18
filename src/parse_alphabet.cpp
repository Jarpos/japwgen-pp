#include <string>

inline constexpr char NUMBERS[] = "0123456789";
inline constexpr char UPPER_ALPH[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline constexpr char LOWER_ALPH[] = "abcdefghijklmnopqrstuvwxyz";

std::string parse_alphabet(const std::string& in)
{
    std::string outalph;
    for (int i = 0; i < in.length(); i++) {
        switch (in[i]) {
        case '[': {
            if /**/ (in[i + 1] == 'a') outalph += LOWER_ALPH;
            else if (in[i + 1] == 'A') outalph += UPPER_ALPH;
            i++;
            continue;
        }

        case '\\': {
            outalph += in[i + 1];
            i++;
            continue;
        }

        default: outalph += in[i]; continue;
        }
    }

    return outalph;
}
