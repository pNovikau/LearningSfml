cmake_minimum_required (VERSION 3.8)

add_library(game_engine STATIC
			"Objects/CollidingObject.h"
			"Objects/CollidingObject.cpp"
			"CollisionContext.h"
			"GameContext.h"
			"GameManager.cpp"
			"GameManager.h"
			"Objects/GameObject.h"
			"Objects/GameObject.cpp"
			"GameObjectManager.h"
			"GameObjectManager.cpp"
			"Objects/GameObjectType.h"
			"Utils/FPS.h"
			"Utils/Helper.cpp"
			"Utils/Helper.h"
			"Utils/VectorMath.h"
			"GameTime.h" Objects/DrawableObject.h Objects/TransformableObject.h)

target_include_directories(game_engine PUBLIC 
    "${CMAKE_SOURCE_DIR}/src/GameEngine"
	"${CMAKE_SOURCE_DIR}/src/GameEngine/Objects"
    "${CMAKE_SOURCE_DIR}/src/GameEngine/Utils")

target_link_libraries(game_engine sfml-main sfml-window sfml-graphics sfml-network)