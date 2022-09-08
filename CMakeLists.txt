cmake_minimum_required(VERSION 3.0.0)
project(sweetmint VERSION 0.1.0)
include(cmake/CmakeConfig.cmake)
include(cmake/GlfwConfig.cmake)
include(cmake/SourcesConfig.cmake)

add_library(sweetmint ${SOURCES})
set_target_properties(sweetmint PROPERTIES
    PUBLIC_HEADER "include/Sweetmint.hpp"
)

include(cmake/LinkerConfig.cmake)
include(cmake/IncludeConfig.cmake)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
