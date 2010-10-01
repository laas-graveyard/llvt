##----------------------------------------------------
## Copyright 2010, CNRS-AIST JRL
## Author Clement Petit
##
## Low Level Vision Tools
## Library target
##----------------------------------------------------

include(LLVT-toolbox)
include(install-toolbox)

# Library name
ADD_LLV_CLIENT(
	LIBRARY
	${${PROJECT_NAME}_LIBRARY_NAME}
	SOURCES
		corba-handler.cpp
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

# Set shared library version.
SET_TARGET_PROPERTIES(LLVT PROPERTIES SOVERSION ${PROJECT_VERSION})
