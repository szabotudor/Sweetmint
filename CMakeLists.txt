cmake_minimum_required(VERSION 3.0.0)
project(sweetmint VERSION 0.1.0)
include(cmake/CmakeConfig.cmake)
include(cmake/GlfwConfig.cmake)
include(cmake/SourcesConfig.cmake)

add_library(sweetmint ${SOURCES})
set_target_properties(sweetmint PROPERTIES
    PUBLIC_HEADER "include/Sweetmint.h"
)

include(cmake/LinkerConfig.cmake)
include(cmake/IncludeConfig.cmake)

message(STATUS "Building in ${CMAKE_BUILD_TYPE} mode")
message(STATUS)

if (${CMAKE_BUILD_TYPE} STREQUAL "Release")
    if (LINUX)
        add_compile_options(-O3)
    elseif(WIN32)
        add_compile_options(/O2)
    endif()
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
