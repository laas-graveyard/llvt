/*! ----------------------------------------------------
 *  Copyright 2010, CNRS-AIST JRL
 * 
 *  \brief  LLVT - Simple client interface
 *  \author Clement Petit
 * ---------------------------------------------------- */

#ifndef _ACTION_WITH_LLVS_BASE_HXX
#define _ACTION_WITH_LLVS_BASE_HXX

#include <llvs/tools/CORBAClient.h>
#include <llvs/tools/Debug.h>

template<class DataType, class DataType_var>
DataType_var
LLVClient::CORBAClient::GetServicePort(const std::string& ServiceName, 
                                       const std::string& ServiceKind)
throw(const char*)
{
	if (m_CORBAReference == NULL)
	{
		try
		{
			m_CORBAReference = new CORBAReference();
		}
		catch(...)
		{
			throw("Unable to create a CORBA Reference object");
		}
		if (!m_CORBAReference->InitORB())
		{	
			throw("Unable to initialize the ORB. ");
		}
	}

	CORBA::Object_ptr obj(m_CORBAReference->getObjectReference(ServiceName, ServiceKind));
	ODEBUG( "Able to get the reference for :" << ServiceName << " " 
			<< m_ServiceKind << "CORBAReference : "<< CORBAReference );

	if (CORBA::is_nil(obj))
	{
		std::string msg("Unable to find object: " + ServiceName + " " + ServiceKind);
		throw(msg.c_str());
	}

	try
	{
		m_ServiceKind = ServiceKind;
		m_ServiceName = ServiceName;
		return DataType::_narrow(obj);
	}
	catch(...)
	{
		std::string msg("Unable to narrow :" + m_ServiceName + " " 
				+ m_ServiceKind);
		throw(msg.c_str());
	}

}

#endif //!_ACTION_WITH_LLVS_BASE_H_
