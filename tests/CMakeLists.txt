project(tests)

add_executable(fft_test fft_test.cpp)
target_link_libraries(fft_test fft gtest_main)

add_test(NAME fft_test COMMAND fft_test)