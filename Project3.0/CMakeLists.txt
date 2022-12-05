cmake_minimum_required(VERSION 3.22)
project(Project3_0)

set(CMAKE_CXX_STANDARD 17)

set(SFML_ROOT "/SFML-2.5.1")
set(SFML_INCLUDE_DIR "C:/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "C:/SFML-2.5.1/lib")

set(SFML_STATIC_LIBRARIES TRUE)

include_directories(${SFML_INCLUDE_DIR})
link_directories(${SFML_LIBRARY_DIR})

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

add_executable(Project3_0 main.cpp state.h StateMachine.cpp StateMachine.h AssetManager.cpp AssetManager.h InputManager.cpp InputManager.h Game.cpp Game.h DEFINITIONS.h SplashState.cpp SplashState.h MainMenuState.cpp MainMenuState.h GameState.cpp GameState.h PauseState.cpp PauseState.h GameOverState.cpp GameOverState.h AI.cpp AI.h ShopState.cpp ShopState.h)

target_link_libraries(Project3_0 sfml-graphics sfml-window sfml-system)
