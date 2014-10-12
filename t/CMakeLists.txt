file(COPY ${CMAKE_SOURCE_DIR}/t/data
  DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

include_directories(
  ${gtest_SOURCE_DIR}/include
  ${gtest_SOURCE_DIR}
)

set(tests_SRC
  program.cpp
)

foreach(TEST_FILE ${tests_SRC})
  get_filename_component(TEST_NAME ${TEST_FILE} NAME_WE)
  set(TEST_EXE "${TEST_NAME}_test")
  add_executable(${TEST_EXE} ${TEST_FILE})
  target_link_libraries(${TEST_EXE} libeyeter gtest gtest_main)
  add_test(${TEST_NAME} ${TEST_EXE})
endforeach()
