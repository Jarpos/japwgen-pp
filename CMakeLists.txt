cmake_minimum_required(VERSION 3.1...3.10)

project(japwgen VERSION 0.0
        DESCRIPTION "Just Another PWGen - PlusPlus")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_C_FLAGS "-Wall -Wextra -pedantic \
                       -fsanitize=address -g -D_FORTIFY_SOURCE=2 \
                       -D_GLIBCXX_ASSERTIONS -fexceptions -fstack-protector \
                       -fstack-protector-all -g3 -pipe -D_REENTRANT")
     set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wno-unused-parameter -Wno-variadic-macros \
                                         -Wno-unused-variable")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(psd ${PROJECT_SOURCE_DIR})
set(cd ${psd})


# Generate helper library
set(cd ${psd}/src)
set(rand ${cd}/rand.cpp
		 ${cd}/pwgen.cpp
		 ${cd}/parse_alphabet.cpp
         ${cd}/parse_args.cpp)
add_library(rand "${rand}")

# Generate executable with linkage to libraries
set(libs rand)

add_executable(japwgen src/main.cpp)
target_link_libraries(japwgen PUBLIC ${libs})
