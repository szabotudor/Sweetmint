if(UNIX AND NOT APPLE)
	target_include_directories(sweetmint
		PUBLIC 
			"${CMAKE_SOURCE_DIR}/include"
		PRIVATE
			"${CMAKE_SOURCE_DIR}/src"
			"/usr/include/X11/"
	)
elseif(WIN32)
	target_include_directories(sweetmint
		PUBLIC 
			"${CMAKE_SOURCE_DIR}/include"
		PRIVATE
			"${CMAKE_SOURCE_DIR}/src"
	)
endif()