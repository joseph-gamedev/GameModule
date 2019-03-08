cmake_minimum_required(VERSION 3.5)
project(GameApp)

# use FindSDL2.cmake
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

# enable C++11
set(CMAKE_CXX_FLAGS "-Wall -std=c++0x -ggdb ${CMAKE_CXX_FLAGS}")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(SDL2_mixer REQUIRED)

include_directories(${SDL2_INCLUDE_DIR}
                    ${SDL2_IMAGE_INCLUDE_DIR}
                    ${SDL2_TTF_INCLUDE_DIR}
					${SDL2_MIXER_INCLUDE_DIR}
					include)
					
file(GLOB SOURCES "src/*.cpp")
					
add_executable(GameApp ${SOURCES})
					
target_link_libraries(GameApp ${SDL2_LIBRARY}
                              ${SDL2_IMAGE_LIBRARIES}
                              ${SDL2_TTF_LIBRARIES}
							  ${SDL2_MIXER_LIBRARIES})
							  
