# CMakeList.txt : CMake project for PingPong.Game, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (PingPong.Game 
	"PingPong.Game.cpp" 
	"Entities/Player.h" 
	"Entities/Player.cpp" 
	"Entities/Ball.h" 
	"Entities/Ball.cpp" 
	"Constants.h" 
	"Entities/Wall.h" 
	"Entities/Wall.cpp" 
	"Triggers/PlayerTrigger.cpp" 
	"Triggers/PlayerTrigger.h" 
	"Triggers/EnemyTrigger.h" 
	"Triggers/EnemyTrigger.cpp" 
	"Entities/Score.h" 
	"Entities/Score.cpp" 
	"ScoreManager.h" 
	"ScoreManager.cpp" Systems/InputSystem.h Systems/CollidingSystem.h)

	target_include_directories(PingPong.Game PUBLIC 
	"${CMAKE_SOURCE_DIR}/src/PingPong.Game"
    "${CMAKE_SOURCE_DIR}/src/PingPong.Game/Entities"
	"${CMAKE_SOURCE_DIR}/src/PingPong.Game/Triggers")

target_link_libraries(PingPong.Game PUBLIC game_engine)
# TODO: Add tests and install targets if needed.
