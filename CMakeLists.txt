cmake_minimum_required(VERSION 3.0)

include("cmake/HunterGate.cmake")
HunterGate(
    URL "https://github.com/ruslo/hunter/archive/v0.15.35.tar.gz"
    SHA1 "3b4f3b697daab31fe9614e25aaec466df0354ab5"
)

project(test-crashup)

hunter_add_package(crashup)
find_package(crashup CONFIG REQUIRED)

hunter_add_package(Qt)
find_package(Qt5 CONFIG COMPONENTS Core REQUIRED)

add_executable(foo main.cpp)
target_link_libraries(foo crashup::crashup Qt5::Core)

find_package(crashpad CONFIG REQUIRED)

add_custom_command(
    TARGET foo
    PRE_BUILD
    COMMAND
    "${CMAKE_COMMAND}" -E make_directory "$<TARGET_FILE_DIR:foo>"
    COMMAND
    "${CMAKE_COMMAND}" -E copy
    "$<TARGET_FILE:crashpad::crashpad_handler>"
    "$<TARGET_FILE_DIR:foo>"
)

