#
# Low Level Vision Tools
# ----------------------
# This module gathers all reusable tools
# for both server and client of the Low
# Level Vision solution.
#

# Project declaration
cmake_minimum_required (VERSION 2.6)
project (LLVT)

# Project specific module files
list (
	APPEND 
	CMAKE_MODULE_PATH 
	${CMAKE_SOURCE_DIR}/share/llvt
	$ENV{ROBOTPKG_BASE}/share/cmake/common
)

# Dependent packages
find_package(OmniORB4)

# Source files exploration
add_subdirectory (include)
add_subdirectory (share)
add_subdirectory (src)

