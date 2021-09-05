cmake_minimum_required (VERSION 3.8)

add_library(game_engine STATIC
			"CollidingGameObject.h"
			"CollidingGameObject.cpp"
			"CollisionContext.h"
			"GameContext.h"
			"GameManager.cpp"
			"GameManager.h"
			"GameObject.h"
			"GameObject.cpp"
			"GameObjectManager.h"
			"GameObjectManager.cpp"
			"GameObjectType.h"
			"Utils/FPS.h"
			"Utils/Helper.cpp"
			"Utils/Helper.h"
			)

target_include_directories(game_engine PUBLIC 
    "${CMAKE_SOURCE_DIR}/src/GameEngine"
    "${CMAKE_SOURCE_DIR}/src/GameEngine/Utils")

target_link_libraries(game_engine sfml-main sfml-window sfml-graphics sfml-network)