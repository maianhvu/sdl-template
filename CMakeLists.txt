cmake_minimum_required(VERSION 2.6)
project(SDL2Template)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${SDL2Template_SOURCE_DIR}/cmake")
set(BIN_DIR ${SDL2Template_SOURCE_DIR}/bin)

if (${CMAKE_CXX_COMPILER_ID} STREQUAL "GNU" OR ${CMAKE_CXX_COMPILER_ID} STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -std=c++11")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS} -g")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS} -O2")
elseif (${CMAKE_CXX_COMPILER_ID} STREQUAL "MSVC")
    if (CMAKE_CXX_FLAGS MATCHES "/W[0-4")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})
# Uncomment the following lines for IMG support
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR})

# include header files
include_directories(include)

add_executable(SDL2Template src/main.cpp)
# normal target
# target_link_libraries(SDL2Template ${SDL2_LIBRARY})
# with IMG support
target_link_libraries(SDL2Template ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
install(TARGETS SDL2Template RUNTIME DESTINATION ${BIN_DIR})
