/** @doc Default header for debug mode
    
    Copyright (c) 2010, 
    @author Stephane Embarki
   
    JRL-Japan, CNRS/AIST
    
    See license file for information on license.
*/

#ifndef _DEBUG_HEADER_LLVS_H_

#include <iostream>

#define ODEBUG2(x)
#define ODEBUG3(x) std::cerr << __FILE__ << ": l" << __LINE__ << ": " << x << std::endl
#define ODEBUG3_CONT(x) cerr << x 

#ifdef _DEBUG_MODE_ON_
 #define ODEBUG(x) std::cerr << __FILE__ << ": l" << __LINE__ << ": " << x << std::endl
 #define ODEBUG_CONT(x) std::cerr << __FILE__ << ": l" << __LINE__ << ": " << x << std::endl
#else
 #define ODEBUG(x) 
 #define ODEBUG_CONT(x) 
#endif

#endif /* _DEBUG_HEADER_LLVS_H_ */
