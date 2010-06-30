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
	APPEND 
	CMAKE_MODULE_PATH 
	$ENV{ROBOTPKG_BASE}/share/cmake
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
find_package(LLVT QUIET)
include(LLVT-toolbox)
ADD_LLV_PACKAGES(OmniORB4)

# Source files exploration
add_subdirectory (include)
add_subdirectory (share)
add_subdirectory (src)

# Add uninstall target
ADD_UNINSTALL_TARGET()
