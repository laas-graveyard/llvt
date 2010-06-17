##-----------------------------------------------------------------
## CMake PACKAGE - omniORB4
## This package check if omniORB4 is available through robotpkg
##-----------------------------------------------------------------

set(PACKAGE_FULLNAME "omniORB4")

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
# XXX_IDLC             The location of the IDL compiler
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
include(serial-toolbox)

#-------------------------------------------------------------------
#                        Start of package
#-------------------------------------------------------------------
# Aim is to find the OpenRTM directory

# Retrieve PACKAGE_NAME and PACKAGE_FILENAME
PACKAGE_HEADER(${CMAKE_CURRENT_LIST_FILE})

# We simply look for pkg-config binary
PACKAGE_SEARCH(
	PROGRAM
		PKGCONFIG_EXECUTABLE
		pkg-config
	INSTALL "GNU pkg-config tool"
	PATHS
		/usr/local/bin
		${PACKAGE_NAME}_ROOT_DIR
)

# And then retrieve omniORB4 information
SERIAL_EXEC_PROGRAM(
	${PKGCONFIG_EXECUTABLE}
	ARGS
		"omniORB4 --variable=omniidl"
		"omniORB4 --variable=prefix"
		"omniORB4 --cflags-only-I"
		"omniORB4 --libs-only-L"
		"omniORB4 --libs-only-l"
	OUTPUT_VARIABLE
		${PACKAGE_NAME}_IDLC
		${PACKAGE_NAME}_ROOT_DIR
		${PACKAGE_NAME}_INCLUDE_DIRS
		${PACKAGE_NAME}_LIBRARY_DIRS
		${PACKAGE_NAME}_LIBRARIES
	QUIET
)

set (${PACKAGE_NAME}_FOUND TRUE)

PACKAGE_FOOT()

#-------------------------------------------------------------------
#                           End of package
#-------------------------------------------------------------------
