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
			"Utils/Helper.h"
			"Utils/VectorMath.h"
			"GameTime.h" 
			"Components/TransformComponent.h" 
			"Managers/SystemManager.h" 
			"Managers/EntityManager.h"
			"Entity.h"
			"Components/Component.h"
			"Components/ComponentType.h" 
			"Components/DrawComponent.h"
			"Systems/DrawSystem.h"
			"Systems/System.h"
			"Systems/TransformSystem.h"
			"Components/IntputComponent.h"
			"Components/CollidingComponent.h"
			"Events/Event.h" "Events/IEventHander.h" "Events/EventQueue.h" "Managers/EventManager.h" Systems/CollidingSystem.h)

target_include_directories(game_engine PUBLIC 
    "${CMAKE_SOURCE_DIR}/src/GameEngine"
	"${CMAKE_SOURCE_DIR}/src/GameEngine/Managers"
	"${CMAKE_SOURCE_DIR}/src/GameEngine/Systems"
	"${CMAKE_SOURCE_DIR}/src/GameEngine/Components"
	"${CMAKE_SOURCE_DIR}/src/GameEngine/Events"
    "${CMAKE_SOURCE_DIR}/src/GameEngine/Utils")

target_link_libraries(game_engine sfml-main sfml-window sfml-graphics sfml-network)