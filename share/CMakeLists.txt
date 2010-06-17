#
# Low Level Vision Tools
# ----------------------
# CMake modules and packages
#

# Add CMake modules
include (include-toolbox)

ADD_CMAKE_MODULES(
	PREFIXES
		llvt
	FILES
		FindLLVT.cmake
	INSTALL
)
