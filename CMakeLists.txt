##----------------------------------------------------
## Copyright 2010, CNRS-AIST JRL
## Author Clement Petit
##
## Low Level Vision Tools
## This module gathers all reusable tools
## for both server and client of the Low
## Level Vision solution.
##----------------------------------------------------

# Project declaration
cmake_minimum_required (VERSION 2.6.4)
project (LLVT)

# Project specific module files
list (
	INSERT
	CMAKE_MODULE_PATH 0
	${CMAKE_SOURCE_DIR}/share
)

# Dependent packages
find_package(
	Modules
	COMPONENTS
	image
	middleware
)

# Use its own environement to install
set(MODULE_LLVT_TOOLBOX_CHECK QUIET)
set(LLVT_IDL_INCLUDE_DIRS ${${PROJECT_NAME}_SOURCE_DIR}/share)
include(LLVT-toolbox)
ADD_LLV_PACKAGES(OmniORB4)

# Source files exploration
add_subdirectory (include)
add_subdirectory (share)
add_subdirectory (src)

CONFIGURE_FILE(${${PROJECT_NAME}_SOURCE_DIR}/${PROJECT_NAME}.pc.cmake
		 ${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}.pc )

# Install the file in the appropriate place.
SET(install_libdir_pkgconfig lib/pkgconfig)

INSTALL(FILES ${${PROJECT_NAME}_BINARY_DIR}/${PROJECT_NAME}.pc
	DESTINATION ${install_libdir_pkgconfig}
        PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
)

# Add uninstall target
ADD_UNINSTALL_TARGET()
