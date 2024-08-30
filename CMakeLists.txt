cmake_minimum_required(VERSION 3.16.3)
project(Vocabulary_Backend_with_Drogon)

set(CMAKE_CXX_STANDARD 20)

#set(CMAKE_CXX_COMPILER "/usr/bin/g++-14")
#set(CMAKE_CXX_COMPILER "/usr/bin/clang++-18")
#set(CMAKE_CXX_COMPILER "/opt/intel/oneapi/2024.2/bin/icpx")

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# cmake -DCMAKE_BUILD_TYPE = DEBUG | RELEASE | RELWITHDEBINFO | MINSIZEREL ...
set(CMAKE_BUILD_TYPE RELEASE)
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

# Search OpenSSL
find_package(PkgConfig REQUIRED)
pkg_search_module(OPENSSL REQUIRED openssl)

if( OPENSSL_FOUND )
    include_directories(${OPENSSL_INCLUDE_DIRS})
    message(STATUS "OpenSSL version: ${OPENSSL_VERSION}")
else()
    message("Error; openssl not found!")
endif()

include(FetchContent)

include_directories(/Vocabulary/include)
include_directories(/Vocabulary/src)

find_package(Threads REQUIRED)

find_package(Boost REQUIRED COMPONENTS system)

find_package(PcapPlusPlus REQUIRED)

find_package(Drogon REQUIRED)

find_package(ZLIB REQUIRED)

set(CommonLibs ssl crypt sqlite3 spdlog::spdlog Threads::Threads Drogon::Drogon ZLIB::ZLIB)

file(GLOB VOCABULARY_SOURCES Vocabulary/src/Core/*.cpp
                             Vocabulary/src/json_singletons/*.cpp
                             Vocabulary/src/sqlite_database/*.cpp)

file(GLOB LOG_MONITOR_SOURCES LogMonitor/LogMonitor.cpp)

add_executable(Vocabulary_Backend_with_Drogon ${VOCABULARY_SOURCES})
add_executable(Log_Monitor ${LOG_MONITOR_SOURCES})

target_link_libraries(Vocabulary_Backend_with_Drogon
                      PRIVATE  ${Boost_LIBRARIES}  ${CommonLibs})
target_link_libraries(Log_Monitor PUBLIC PcapPlusPlus::Pcap++)

target_compile_options(Vocabulary_Backend_with_Drogon PRIVATE -flto=auto)
