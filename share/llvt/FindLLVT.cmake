##-----------------------------------------------------------------
## CMake PACKAGE - LLVT
## This package check if LLVT is well installed into robot package
##-----------------------------------------------------------------

set(PACKAGE_FULLNAME "Low Level Vision Tools")

##-----------------------------------------------------------------
# This package tries to respect CMake guidelines to be easily
# reusable.
# This module handles the following variables. Please note XXX is
# the name specified in the PACKAGE_NAME variable. This variable
# is automatically generated according to package file name through
# PACKAGE_HEADER macro. Please refer to it for more details about
# typography.
#
# XXX_INCLUDE_DIRS     The final set of include directories listed in
#                      one variable for use by client code.
#
# XXX_LIBRARY_DIRS     Optionally, the final set of library
#                      directories listed in one variable for use
#                      by client code.
#
# XXX_LIBRARIES        The libraries to link against to use XXX. These
#                      should include full paths.
#
# XXX_SHARED_LIBRARIES The list of all shared libraries found in the
#                      package. This can be usefull if you're looking
#                      for .dll or .so to export during the install.
#
# XXX_YY_FOUND         FALSE/Undefined if YY part of XXX package has
#                      not been found.
#
# XXX_FOUND            FALSE/Undefined if the whole package has not
#                      been found.
#                      Set it manually to FALSE don't want to use XXX.
#
# XXX_ROOT_DIR         Paths you want to add in the path list in order
#                      to help cmake find your package on your computer.
#
# QUIET option         You can ask the package not to complain if there
#                      is library/path not found. This means no output.
#                      If you specify both QUIET and REQUIRED option,
#                      the QUIET option has a lower priority and
#                      critical messages are displayed.
#
# REQUIRED option      You can ask the package to throw a FATAL_ERROR
#                      if the whole package has not been found.
#
# Here is the XXX_YY list:
# <empty>
##-----------------------------------------------------------------

#-------------------------------------------------------------------
#                         Required modules
#-------------------------------------------------------------------

include(package-toolbox)
include(search-toolbox)

#-------------------------------------------------------------------
#                        Start of package
#-------------------------------------------------------------------
# Aim is to find the OpenRTM directory

# Retrieve PACKAGE_NAME and PACKAGE_FILENAME
PACKAGE_HEADER(${CMAKE_CURRENT_LIST_FILE})

# Check environment variables
CHECK_ENVIRONMENT_VARS(
	ROBOTPKG_BASE
)

# Look up for LLVT library
PACKAGE_SEARCH(
	LIBRARY LLVT_LIB llvt-0
	FULLNAME "Low Level Vision Tools"
	PATHS 
		$ENV{ROBOTPKG_BASE}/lib
		${PACKAGE_NAME}_ROOT_DIR
)

# Look up for LLVT include dirs
PACKAGE_SEARCH(
	PATH LLVT_INC tools
	FULLNAME "Low Level Vision Tools"
	PATHS
		$ENV{ROBOTPKG_BASE}/include/llvs
		${PACKAGE_NAME}_ROOT_DIR
)

set (${PACKAGE_NAME}_FOUND TRUE)

PACKAGE_FOOT(LLVT_INC LLVT_LIB)

#-------------------------------------------------------------------
#                           End of package
#-------------------------------------------------------------------
