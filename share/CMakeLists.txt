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
INCLUDE_CONFIG(LLVT-idl)


# Convert them for the generic macro 
ADD_COMPONENT_FILES(
	PREFIXES
		llvs
	FILES 
		 ${LLVT_DEFAULT_IDLS}
		# Add there non-default idls
	INSTALL share/idl
)

# Generate LLVT-idlConfig from the internal set variable.
MACRO(LIST2STRING _VAR_ARG _LIST_ARG)
  SET(${_VAR_ARG})
  SET(_FIRST_STEP 1)
  FOREACH(_ITEM ${ARGV})
     IF(_FIRST_STEP)
	SET(_FIRST_STEP 0)
     ELSE(_FIRST_STEP)
           SET (${_VAR_ARG} "${${_VAR_ARG}} ${_ITEM}")
     ENDIF(_FIRST_STEP)
  ENDFOREACH(_ITEM)
ENDMACRO(LIST2STRING)

LIST2STRING(LLVT_DEFAULT_IDLS_STR ${LLVT_DEFAULT_IDLS})

configure_file(
		${CMAKE_SOURCE_DIR}/share/LLVT-idlConfig.cmake.in
		${CMAKE_BINARY_DIR}/LLVT-idlConfig.cmake)

# Make it simple.
install(
  FILES ${CMAKE_BINARY_DIR}/LLVT-idlConfig.cmake
  DESTINATION share/cmake/image
  PERMISSIONS OWNER_READ GROUP_READ WORLD_READ OWNER_WRITE
)
