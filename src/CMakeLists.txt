##----------------------------------------------------
## Copyright 2010, CNRS-AIST JRL
## Author Clement Petit
##
## Low Level Vision Tools
## Library target
##----------------------------------------------------

include(LLVT-toolbox)

# Library name
set(${PROJECT_NAME}_LIBRARY_NAME llvt-0)

# Add workspace include dirs
include_directories(${${PROJECT_NAME}_INCLUDE_DIRS})

ADD_LLV_CLIENT(
	LIBRARY
	${${PROJECT_NAME}_LIBRARY_NAME}
	SOURCES
		CORBAReference.cpp
		CORBAClient.cpp
		ActionWithLLVSBase.cpp
	FORCE_IDL_COMPILATION
)

# Install it
install (
	TARGETS ${${PROJECT_NAME}_LIBRARY_NAME} 
	DESTINATION lib
)
