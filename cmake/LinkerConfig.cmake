if(UNIX AND NOT APPLE)
	find_package(X11 REQUIRED)
	set(LIB_ENUM 0)
	foreach(S IN LISTS X11_LIBRARIES)
		message(STATUS "Adding X11 object: ${S} (${LIB_ENUM})")
		set(CURRENT_X11_LIB "sweetmint-${LIB_ENUM}")
		add_library(${CURRENT_X11_LIB} SHARED IMPORTED)
		set_target_properties(${CURRENT_X11_LIB} PROPERTIES
			IMPORTED_LOCATION ${S}
			IMPORTED_NO_SONAME TRUE
		)
		target_link_libraries(sweetmint PUBLIC ${CURRENT_X11_LIB})
		math(EXPR LIB_ENUM "${LIB_ENUM} + 1")
	endforeach()
	message(STATUS)
	add_compile_definitions(USE_X11)
elseif(WIN32)
	# For windows, additional linking is not needed
endif()

if(SWEETMINT_SHARED)
	message(STATUS "Building shared libs")
	set(BUILD_SHARED_LIBS TRUE)
else()
	message(STATUS "Building static libs")
	set(BUILD_SHARED_LIBS FALSE)
endif()