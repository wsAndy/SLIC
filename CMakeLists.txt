cmake_minimum_required(VERSION 3.7)
project(SLIC)

find_package(OpenCV  REQUIRED)
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/run)
set(SOURCE_FILES  main.cpp slic.cpp)
add_executable(run ${SOURCE_FILES})
target_link_libraries(run ${OpenCV_LIBS})

