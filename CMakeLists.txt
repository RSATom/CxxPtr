cmake_minimum_required(VERSION 3.10)

project(CxxPtr)

file(GLOB SOURCES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}
    *.h
)

add_library(${PROJECT_NAME} INTERFACE ${SOURCES})
target_include_directories(${PROJECT_NAME} INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/..")
