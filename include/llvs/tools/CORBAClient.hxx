/*
 * Copyright 2010, CNRS/AIST, Clément Petit
 *
 * This file is part of llvt.
 * llvt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * llvt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * You should have received a copy of the GNU Lesser General Public License
 * along with llvt.  If not, see <http://www.gnu.org/licenses/>.
 */

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
