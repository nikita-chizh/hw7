cmake_minimum_required(VERSION 3.9)
MESSAGE(STATUS $ENV{TRAVIS_BUILD_NUMBER})
project(Bulk VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

set(CMAKE_CXX_STANDARD 14)

add_executable(bulk main.cpp)
add_library(commands Packet.cpp Packet.h Executor.cpp Executor.h Simple_Executor.cpp Simple_Executor.h)

target_link_libraries(bulk commands
        )
set(CMAKE_CXX_STANDARD 14)

set_target_properties(bulk PROPERTIES
        CXX_STANDART 14
        CXX_STANDART_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )
install(TARGETS bulk RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT nikita1993chizh@gmail.com)
include(CPack)
enable_testing()