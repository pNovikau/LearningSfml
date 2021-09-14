cmake_minimum_required (VERSION 3.8)

add_library(game_engine STATIC
			"GameContext.h"
			"GameManager.cpp"
			"GameManager.h"
			"GameTime.h" 
			"Entity.h"
			"Utils/FPS.h"
			"Utils/Debug.h"
			"Utils/Helper.h"
			"Utils/VectorMath.h"
			"Managers/EventManager.h"
			"Managers/SystemManager.h" 
			"Managers/EntityManager.h"
			"Components/Component.h"
			"Components/ComponentType.h" 
			"Components/DrawComponent.h"
			"Components/IntputComponent.h"
			"Components/CollidingComponent.h"
			"Components/TransformComponent.h" 
			"Systems/System.h"
			"Systems/DrawSystem.h"
			"Systems/TransformSystem.h"
			"Systems/CollidingSystem.h"
			"Events/Event.h" 
			"Events/EventQueue.h"
			"Events/IEventHander.h")

target_include_directories(game_engine PUBLIC 
    "${CMAKE_SOURCE_DIR}/src/GameEngine"
	"${CMAKE_SOURCE_DIR}/src/GameEngine/Managers"
	"${CMAKE_SOURCE_DIR}/src/GameEngine/Systems"
	"${CMAKE_SOURCE_DIR}/src/GameEngine/Components"
	"${CMAKE_SOURCE_DIR}/src/GameEngine/Events"
    "${CMAKE_SOURCE_DIR}/src/GameEngine/Utils")

target_link_libraries(game_engine sfml-main sfml-window sfml-graphics sfml-network)