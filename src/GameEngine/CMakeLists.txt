cmake_minimum_required (VERSION 3.8)

add_library(game_engine STATIC 
			"GameManager.cpp" 
			"GameManager.h" 
			"Events/Event.h"  
			"GameObjectManager.h" 
			"GameObjectManager.cpp" 
			"Events/SystemErrorEvent.h"  
			"IEventHandler.h" 
			"Events/WindowClosedEvent.h" 
			"Events.h" 
			"GameObject.h" 
			"GameObject.cpp" 
			"Utils/Helper.cpp" 
			"Utils/Helper.h" 
			"GameContext.h")

target_include_directories(game_engine PUBLIC 
	"${CMAKE_SOURCE_DIR}/src/GameEngine"
    "${CMAKE_SOURCE_DIR}/src/GameEngine/Events"
    "${CMAKE_SOURCE_DIR}/src/GameEngine/Utils")

target_link_libraries(game_engine sfml-main sfml-window sfml-graphics sfml-network)