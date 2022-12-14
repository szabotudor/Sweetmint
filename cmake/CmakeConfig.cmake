include(CTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

option(SWEETMINT_SHARED "Build the shared version of the library")
include("BuildSettings.cmake")

if(UNIX AND NOT APPLE)
    add_compile_definitions(LINUX)
elseif(WIN32)
    add_compile_definitions(WIN32)
endif()
