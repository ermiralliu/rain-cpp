cmake_minimum_required(VERSION 3.10)

project(RainSimulator)

find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} ${SDL2IMAGE_INCLUDE_DIR})

file(GLOB RainSimulator_SRC
     "src/*.hpp"
     "src/*.cpp"
)

add_executable(RainSimulator ${RainSimulator_SRC})

#target_link_libraries(RainSimulator ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARY})
target_link_libraries(RainSimulator
        PRIVATE
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
    )

target_link_libraries(RainSimulator PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
