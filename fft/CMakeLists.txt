project(fft)

set(SOURCES fft.cpp)

add_library(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} fftw3)
