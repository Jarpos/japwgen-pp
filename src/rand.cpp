#include <fstream>

// this is pretty slow, however, for the time being, I don't really care
// about that to be honest. I'll try to think of/find a better way to do
// this eventually, when the foundation for this project is good enough.
size_t GetRandNum()
{
    size_t r;

#if defined(__unix) || defined(__unix__) || defined(linux)
    std::ifstream ifs("/dev/random", std::ios::in);
    if (!ifs.is_open()) {
        throw new std::runtime_error("Couldn't open /dev/random");
    }

    ifs.read(reinterpret_cast<char*>(&r), sizeof(r));
    if (ifs.fail()) {
        throw new std::runtime_error("Couldn't read from /dev/random");
    }

#elif defined(_WIN32) || defined(_WIN64)
    #error "Currently there exists no support for Windows"

#else
    #error \
        "Currently there exists no support for your OS, see rand.cpp if you think this is an error"
#endif

    return r;
}
