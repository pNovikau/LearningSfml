cmake_minimum_required (VERSION 3.8)

add_executable(Dungeon "Dungeon.cpp" Entities/BigDemon.h "Components/AnimationStateComponent.h" Constants.h Entities/BigDemon.cpp Utils/ComponentFactory.h Entities/Floor.cpp Entities/Floor.h Utils/LevelGenerator.h Entities/BidZombie.cpp Entities/BidZombie.h Systems/EnemyControlSystem.cpp Systems/EnemyControlSystem.h Components/EnemyStateComponent.h Components/MoveComponent.h Utils/Helper.h Systems/EnemyMoveSystem.cpp Systems/EnemyMoveSystem.h Systems/AnimationStateSystem.cpp Systems/AnimationStateSystem.h Events/EnemyStateChanged.h EnemyState.h Components/HealthComponent.h Components/AttackComponent.h Entities/Coin.cpp Entities/Coin.h)

target_include_directories(Dungeon PUBLIC
        "${CMAKE_SOURCE_DIR}/src/Dungeon"
        "${CMAKE_SOURCE_DIR}/src/Dungeon/Events"
        "${CMAKE_SOURCE_DIR}/src/Dungeon/Utils"
        "${CMAKE_SOURCE_DIR}/src/Dungeon/Systems"
        "${CMAKE_SOURCE_DIR}/src/Dungeon/Entities"
        "${CMAKE_SOURCE_DIR}/src/Dungeon/Components")

target_link_libraries(Dungeon PUBLIC game_engine)