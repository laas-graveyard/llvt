##----------------------------------------------------
## Copyright 2010, CNRS-AIST JRL
## Author Clement Petit
##
## Low Level Vision Tools
## Headers
##----------------------------------------------------

# Add header files
include (include-toolbox)

ADD_HEADERS(
	PREFIXES
	  llvs/tools
	FILES
	  Debug.h
		corba-handler.h
		CORBAReference.h
		CORBAClient.h
		ActionWithLLVSBase.h
		CORBAClient.hxx
	INSTALL
)
