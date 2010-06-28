##----------------------------------------------------
## Copyright 2010, CNRS-AIST JRL
## Author Clement Petit
##
## Low Level Vision Tools
## Idls centralization
##----------------------------------------------------

find_package (Modules)
include (include-toolbox)

# Retrieve default included IDL list
include (LLVT-idl-config)

# Convert them for the generic macro 
ADD_COMPONENT_FILES( 
	FILES 
		${LLVT_DEFAULT_IDLS}
		# Add there non-default idls
	INSTALL share/idl/llvs
)

# Add default config file
ADD_COMPONENT_FILES(
	FILES
		LLVT-idl-config.cmake
	INSTALL share/cmake/image
)
