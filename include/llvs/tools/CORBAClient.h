/*! ----------------------------------------------------
 *  Copyright 2010, CNRS-AIST JRL
 * 
 *  \brief  LLVT - Connection to LLVS as a CORBA Client
 *  \author Clement Petit
 * ---------------------------------------------------- */

#ifndef _CORBA_FOR_LLVS_CLIENT_H 
#define _CORBA_FOR_LLVS_CLIENT_H

#include <llvs/tools/CORBAReference.h>

namespace LLVClient
{
	class CORBAClient
	{
		/* Default connection parameters */
		static const std::string DEFAULT_LLVS_SERVICE_NAME;
		static const std::string DEFAULT_LLVS_SERVICE_KIND;

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
			LLVClient::CORBAReference* getCORBAReference() const;
	    
	    /*! \brief Set the CORBA reference. */
	    void setCORBAReference(CORBAReference * aCorbaRef);
	    
	    /*! \brief Connection to the server. 
	     */
			template<class DataType, class DataType_var>
	    DataType_var GetServicePort(const std::string& ServiceName = DEFAULT_LLVS_SERVICE_NAME,
					                const std::string& ServiceKind = DEFAULT_LLVS_SERVICE_KIND) throw(const char*);
  
		protected:
  	  /*! \brief Store the service name (set by default to LLVS one). */
  	  std::string m_ServiceName;
  	    
  	  /*! \brief Store the service kind (set by default to LLVS one). */
  	  std::string m_ServiceKind;
  	  
  	  /*! Pointer to the CORBA reference object. */
			LLVClient::CORBAReference* m_CORBAReference;
	};
}

#include <llvs/tools/CORBAClient.hxx>

#endif //!_CORBA_FOR_LLVS_CLIENT_H
