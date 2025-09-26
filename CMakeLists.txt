cmake_minimum_required(VERSION 3.16)
project(cpp_week5_ec_json_demo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Fetch header-only nlohmann/json at configure time
FetchContent_Declare(
  nlohmann_json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(nlohmann_json)

# Executable 1: parse JSON from file and query fields
add_executable(main_parse src/main_parse.cpp)
target_link_libraries(main_parse PRIVATE nlohmann_json::nlohmann_json)

# Executable 2: serialize C++ structs to JSON (and back)
add_executable(main_serialize src/main_serialize.cpp)
target_link_libraries(main_serialize PRIVATE nlohmann_json::nlohmann_json)
