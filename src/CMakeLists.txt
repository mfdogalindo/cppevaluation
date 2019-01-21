cmake_minimum_required(VERSION 3.0.0)
project(ProducerConsumer VERSION 0.1.0)


file(GLOB SOURCES
    *.hpp
    *.cpp
)

add_executable(ProducerConsumer ${SOURCES})

set(CMAKE_CXX_FLAGS "-pthread -DNDEBUG")
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
