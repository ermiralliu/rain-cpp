cmake_minimum_required(VERSION 3.10)

project(RainSimulator)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})

# file(GLOB RainSimulator_SRC
#      "src/*.hpp"
#      "src/*.cpp"
# )

SET(TARGET_HPP
    src/Game.hpp
    src/GameObject.hpp
    src/Rain.hpp
    src/Render.hpp
    src/Texture.hpp
    src/windowManagement.hpp    
   )
SET(TARGET_SRC
    src/main.cpp
    src/Game.cpp
    src/Rain.cpp
    src/Texture.cpp
    src/windowManagement.cpp 
   )

# add_executable(RainSimulator ${RainSimulator_SRC})
add_executable(RainSimulator ${TARGET_HPP} ${TARGET_SRC} )

# target_link_libraries(RainSimulator ${SDL2_LIBRARIES})

target_link_libraries(RainSimulator
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    )

target_link_libraries(RainSimulator PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
