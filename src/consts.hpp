#ifndef __CONSTS_42_HPP__
#define __CONSTS_42_HPP__

#include <string>

inline constexpr char ALPHABET[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

inline constexpr int BREAK_AFTER = 5;
inline constexpr int STD_PWCOUNT = 5 * 5;
inline constexpr int STD_PWLENGTH = 10;

struct options {
    std::string alphabet = ALPHABET;
    int pwlen = STD_PWLENGTH;
    int pwcnt = STD_PWCOUNT;
    bool help = false;
};

#endif // __CONSTS_42_HPP__
