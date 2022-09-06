file(GLOB_RECURSE SOURCES "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB_RECURSE SOURCES_C "${CMAKE_SOURCE_DIR}/src/*.c")
list(APPEND SOURCES ${SOURCES_C})
list(APPEND SOURCES $<TARGET_OBJECTS:glfw>)
list(APPEND SOURCES "include/Sweetmint.hpp")

message(STATUS "Found following sources:")
foreach(S IN LISTS SOURCES)
	message(STATUS ${S})
endforeach()
message(STATUS)
