cmake_minimum_required (VERSION 3.8)

add_executable(AnimationTest
        "AnimationTest.cpp"
        "Entities/Player.h" Systems/PlayerInputSystem.h Constants.h Events/KeyPressedEvent.h Systems/PlayerAnimationSystem.h Systems/PlayerAnimationSystem.cpp Components/MoveComponent.h Systems/PlayerTransformSystem.h)

target_include_directories(AnimationTest PUBLIC
        "${CMAKE_SOURCE_DIR}/src/AnimationTest"
        "${CMAKE_SOURCE_DIR}/src/AnimationTest/Events"
        "${CMAKE_SOURCE_DIR}/src/AnimationTest/Components"
        "${CMAKE_SOURCE_DIR}/src/AnimationTest/Entities"
        "${CMAKE_SOURCE_DIR}/src/AnimationTest/Systems")

target_link_libraries(AnimationTest PUBLIC game_engine)