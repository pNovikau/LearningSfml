cmake_minimum_required (VERSION 3.8)

add_library(game_engine STATIC 
			"GameManager.cpp" 
			"GameManager.h" 
			"GameObjectManager.h" 
			"GameObjectManager.cpp" 
			"GameObject.h" 
			"GameObject.cpp" 
			"Utils/Helper.cpp" 
			"Utils/Helper.h" 
			"GameContext.h" 
			"CollisionContext.h" "CollidingGameObject.h" "CollidingGameObject.cpp" "GameObjectType.h")

target_include_directories(game_engine PUBLIC 
	"${CMAKE_SOURCE_DIR}/src/GameEngine"
    "${CMAKE_SOURCE_DIR}/src/GameEngine/Utils")

target_link_libraries(game_engine sfml-main sfml-window sfml-graphics sfml-network)