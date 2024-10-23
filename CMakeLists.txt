cmake_minimum_required(VERSION 3.25)
project(tic-tac-toe-AI)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

include_directories(
        include
        src
        src/game
        src/ai
        src/human
)

file(GLOB_RECURSE SOURCES
        "src/*.cpp"
        "src/game/*.cpp"
        "src/ai/*.cpp"
        "src/human/*.cpp"
)

add_executable(tic-tac-toe-AI
        ${SOURCES}
)

target_include_directories(tic-tac-toe-AI PRIVATE
        include
        src
        src/game
        src/ai
        src/human
)