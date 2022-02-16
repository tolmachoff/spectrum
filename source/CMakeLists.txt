project(source)

set(SOURCES noise.cpp)

add_library(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} common)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
