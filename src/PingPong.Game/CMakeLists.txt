# CMakeList.txt : CMake project for PingPong.Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (PingPong.Game 
	"PingPong.Game.cpp"
	"Constants.h"
	"Entities/Player.h"
	"Entities/Ball.h"
	"Entities/Wall.h"
	"Entities/Trigger.h"
	"Systems/InputSystem.h" 
	"Systems/PlayerSystem.h"
	"Systems/TriggerSystem.h"
	"Systems/BallBounceSystem.h"
	"Systems/GameResetSystem.h"
	"Components/TriggerComponent.h"
	"Events/TriggerEvent.h")

	target_include_directories(PingPong.Game PUBLIC 
	"${CMAKE_SOURCE_DIR}/src/PingPong.Game"
    "${CMAKE_SOURCE_DIR}/src/PingPong.Game/Entities"
	"${CMAKE_SOURCE_DIR}/src/PingPong.Game/Triggers")

target_link_libraries(PingPong.Game PUBLIC game_engine)
# TODO: Add tests and install targets if needed.
