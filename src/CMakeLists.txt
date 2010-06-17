#
# Low Level Vision Tools
# ----------------------
# Library target
#

# Library name
set(${PROJECT_NAME}_LIBRARY_NAME llvt-0)

# Add workspace include dirs
include_directories(${${PROJECT_NAME}_INCLUDE_DIRS})

# Build library
add_library(
  llvt-0
  CORBAReference.cpp
)	

# Add custom flags
set_target_properties(
	${${PROJECT_NAME}_LIBRARY_NAME}
	PROPERTIES
 		COMPILE_FLAGS
			"-DOMNIORB4 -g	-Wall	-Wfatal-errors"
)

# Install it
install (TARGETS llvt-0 DESTINATION lib)
