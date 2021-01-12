cmake_minimum_required(VERSION 3.10)
project(discord-webhook-sender)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig REQUIRED)
pkg_check_modules(CURL REQUIRED IMPORTED_TARGET libcurl)

add_executable(discord-webhook-sender
    "src/main.cc"
    "src/discord_webhook.cc"
)

target_include_directories(discord-webhook-sender PRIVATE "./src/")
target_link_libraries(discord-webhook-sender PUBLIC
    PkgConfig::CURL
)
