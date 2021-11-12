cmake_minimum_required(VERSION 3.1...3.10)

project(jawb VERSION 0.0
        DESCRIPTION "Just Another Shell - PlusPlus")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic \
                         -Wno-unused-variable")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(psd ${PROJECT_SOURCE_DIR})
set(cd ${psd})


# Generate helper library
#set(cd ${psd}/src/helpers)
#set(helpers ${cd}/colors.cpp)
#add_library(helpers "${helpers}")

# Generate executable with linkage to libraries
set(libs )

add_executable(prog.out src/main.cpp)
target_link_libraries(prog.out PUBLIC ${libs})
