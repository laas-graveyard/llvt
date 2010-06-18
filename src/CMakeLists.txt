##----------------------------------------------------
## Copyright 2010, CNRS-AIST JRL
## Author Clement Petit
##
## Low Level Vision Tools
## Library target
##----------------------------------------------------

# Library name
set(${PROJECT_NAME}_LIBRARY_NAME llvt-0)

# Add workspace include dirs
include_directories(${${PROJECT_NAME}_INCLUDE_DIRS})

# Build library
add_library(
	llvt-0 SHARED
	CORBAReference.cpp
	CORBAClient.cpp
	ActionWithLLVSBase.cpp
)	

# Add custom flags
set_target_properties(
	${${PROJECT_NAME}_LIBRARY_NAME}
	PROPERTIES
 		COMPILE_FLAGS
			"-DOMNIORB4 -g -Wall -Wfatal-errors"
)

# Add link to omniORB4
target_link_libraries(
	${${PROJECT_NAME}_LIBRARY_NAME}
	omniORB4
)

# Install it
install (TARGETS llvt-0 DESTINATION lib)
