# CMakeList.txt : CMake project for PingPong.Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (PingPong.Game "PingPong.Game.cpp" "PingPong.Game.h")

target_link_libraries(PingPong.Game "GameEngine")
target_link_libraries(PingPong.Game sfml-main sfml-window sfml-graphics sfml-network)

# TODO: Add tests and install targets if needed.
