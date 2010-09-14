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
set(${PROJECT_NAME}_LIBRARY_NAME llvt-0)

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

# Specify default IDLs.
set(
	LLVT_DEFAULT_IDLS
	BRep.idl
	common.idl
	GetGyroAndAccelerometer.idl
	LowLevelVisionSystem.idl
	ModelTrackerInterface.idl
	PointTrackerInterface.idl
	Scene.idl
	server-command-corba.idl
	ServerCommand.idl
	StereoVision.idl
	visionsensor.idl
	BtlSlamInterface.idl

	OpenHRPCommon.idl
	ViewSimulator.idl
)

# Use its own environement to install
set(MODULE_LLVT_TOOLBOX_CHECK QUIET)
set(LLVT_IDL_INCLUDE_DIRS ${${PROJECT_NAME}_SOURCE_DIR}/share)
include(LLVT-toolbox)
ADD_PACKAGES(OmniORB4)

# Source files exploration
add_subdirectory (include)
add_subdirectory (share)
add_subdirectory (src)

# Add uninstall target
ADD_UNINSTALL_TARGET()
ADD_PKGCONFIG_FILE()
