project(tests)


add_executable(fft_test fft_test.cpp)
target_link_libraries(fft_test fft gtest_main)

add_executable(bmp_test bmp_test.cpp)
target_link_libraries(bmp_test 3rd_party gtest_main)

add_executable(filter_test filter_test.cpp)
target_link_libraries(filter_test filter gtest_main)

add_executable(source_test source_test.cpp)
target_link_libraries(source_test source gtest_main)


add_test(NAME fft_test COMMAND fft_test)

add_test(NAME bmp_test COMMAND bmp_test)

add_test(NAME filter_test COMMAND filter_test)

add_test(NAME source_test COMMAND source_test)
