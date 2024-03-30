cmake_minimum_required(VERSION 3.14)

set(PROJECT_NAME "SpaceInvaders")
project(${PROJECT_NAME})
set(CMAKE_BUILD_TYPE Debug)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(include)
add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(assets)

include(FetchContent)

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.0
)
FetchContent_MakeAvailable(raylib)

