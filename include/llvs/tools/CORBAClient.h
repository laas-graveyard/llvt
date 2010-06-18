/*! ----------------------------------------------------
 *  Copyright 2010, CNRS-AIST JRL
 * 
 *  \brief  LLVT - Connection to LLVS as a CORBA Client
 *  \author Clement Petit
 * ---------------------------------------------------- */

#ifndef _DHFSM_CORBA_CLIENT_H_ 
#define _DHFSM_CORBA_CLIENT_H_

#include "CORBAReference.h"

/* Default connection parameters */
#define DEFAULT_LLVS_SERVICE_NAME "LowLevelVisionSystem"
#define DEFAULT_LLVS_SERVICE_KIND "VisionServer"

namespace LLVClient
{
	class CORBAClient
	{
		public:
	    /*! \brief Constructor. */
			CORBAClient();

	    /*! \brief Destructor. */
			~CORBAClient();

	    /*! \brief Get the name service. */
	    const std::string & GetServiceName() const;
	    
	    /*! \brief Get the service's kind. */
	    const std::string & GetServiceKind() const;
	    
	    
	    /*! \brief Get the CORBA reference. */
	    CORBAReference * getCORBAReference() const;
	    
	    /*! \brief Set the CORBA reference. */
	    void setCORBAReference(CORBAReference * aCorbaRef);
	    
	    /*! \brief Connection to the server. 
	     */
			template<class DataType>
	    DataType GetService(std::string& ServiceName = DEFAULT_LLVS_SERVICE_NAME,
					                std::string& ServiceKind = DEFAULT_LLVS_SERVICE_KIND) throw(const char*);
  
		protected:
  	  /*! \brief Store the service name (set by default to LLVS one). */
  	  std::string m_ServiceName;
  	    
  	  /*! \brief Store the service kind (set by default to LLVS one). */
  	  std::string m_ServiceKind;
  	  
  	  /*! Pointer to the CORBA reference object. */
  	  CORBAReference* m_CORBAReference;
	};
}

#endif //!_DHFSM_CORBA_CLIENT_H_
