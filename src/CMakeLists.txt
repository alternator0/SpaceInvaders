project(${PROJECT_NAME})

add_library(Game Game.cpp)
target_include_directories(Game PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
target_link_libraries(
    Game PUBLIC raylib PUBLIC Spaceship PUBLIC Laser PUBLIC Invader PUBLIC Shield PUBLIC Block PUBLIC Cover PUBLIC Fleet)

add_library(test test.cpp)
target_include_directories(test PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)

add_library(Spaceship Spaceship.cpp)
target_include_directories(Spaceship PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
target_link_libraries(Spaceship PUBLIC raylib PUBLIC Laser)

add_library(Laser Laser.cpp)
target_include_directories(Laser PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
target_link_libraries(Laser PUBLIC raylib)

add_library(Invader Invader.cpp)
target_include_directories(Invader PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
target_link_libraries(Invader PUBLIC raylib PUBLIC Laser)

add_library(Shield Shield.cpp)
target_include_directories(Shield PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
target_link_libraries(Shield PUBLIC raylib PUBLIC Laser PUBLIC Block)

add_library(Block Block.cpp)
target_include_directories(Block PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
target_link_libraries(Block PUBLIC raylib PUBLIC Spaceship)

add_library(Cover Cover.cpp)
target_include_directories(Cover PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
target_link_libraries(Cover PUBLIC raylib PUBLIC Shield PUBLIC Laser)

add_library(Fleet Fleet.cpp)
target_include_directories(Fleet PUBLIC ${CMAKE_CURRENT_LIST_DIR}/../include)
target_link_libraries(Fleet PUBLIC raylib PUBLIC Invader PUBLIC Laser)