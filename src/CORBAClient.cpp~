/*! ----------------------------------------------------
 *  Copyright 2010, CNRS-AIST JRL
 * 
 *  \brief  LLVT - Connection to LLVS as a CORBA Client
 *  \author Clement Petit
 * ---------------------------------------------------- */

#include <llvs/tools/CORBAClient.h>
#include <llvs/tools/Debug.h>

/* Default connection parameters */
const std::string LLVClient::CORBAClient::DEFAULT_LLVS_SERVICE_NAME("LowLevelVisionSystem");
const std::string LLVClient::CORBAClient::DEFAULT_LLVS_SERVICE_KIND("VisionServer");

LLVClient::CORBAClient::CORBAClient()
  : m_ServiceName(""),
    m_ServiceKind(""),
    m_CORBAReference(NULL)
{
}

LLVClient::CORBAClient::~CORBAClient()
{
	if(m_CORBAReference)
	{
		delete m_CORBAReference;
	}
}

const std::string&
LLVClient::CORBAClient::GetServiceName()
const
{
  return m_ServiceName;
}

const std::string& 
LLVClient::CORBAClient::GetServiceKind()
const
{
  return m_ServiceKind;
}

LLVClient::CORBAReference*
LLVClient::CORBAClient::getCORBAReference()
const
{
  return m_CORBAReference;
}

void
LLVClient::CORBAClient::setCORBAReference(CORBAReference* aCorbaRef)
{
  m_CORBAReference = aCorbaRef;
}

