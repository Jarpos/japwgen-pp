#include <string>

inline constexpr char NUMBERS[] = "0123456789";
inline constexpr char UPPER_ALPH[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
inline constexpr char LOWER_ALPH[] = "abcdefghijklmnopqrstuvwxyz";

std::string parse_alphabet(const std::string& inarg)
{
    bool open = false;
    bool escaped = false;

    std::string outalph;
    for (const auto& c : inarg) {
        if /****/ (c == '[' && !escaped) {
            open = true;
            continue;
        } else if (c == '\\' && !escaped) {
            escaped = true;
            continue;
        } else if (c == '[' && escaped) {
            outalph += '[';
        } else if (c == 'A' && open) {
            outalph += UPPER_ALPH;
        } else if (c == 'a' && open) {
            outalph += LOWER_ALPH;
        } else {
            outalph += c;
        }
        open = false;
        escaped = false;
    }

    return outalph;
}
