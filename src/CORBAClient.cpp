/*! ----------------------------------------------------
 *  Copyright 2010, CNRS-AIST JRL
 * 
 *  \brief  LLVT - Connection to LLVS as a CORBA Client
 *  \author Clement Petit
 * ---------------------------------------------------- */

CORBAClient::CORBAClient()
  : m_CORBAReference(NULL),
    m_ServiceName(""),
    m_ServiceKind("")
{
}

CORBAClient::~CORBAClient()
{
	if(m_CORBAReference)
	{
		delete m_CORBAReference;
	}
}

const std::string & ActionWithLLVS::GetServiceName() const
{
  return m_ServiceName;
}

const std::string & ActionWithLLVS::GetServiceKind() const
{
  return m_ServiceKind;
}

CORBAReference * ActionWithLLVS::getCORBAReference() const
{
  return m_CORBAReference;
}

void ActionWithLLVS::setCORBAReference(CORBAReference * aCorbaRef)
{
  m_CORBAReference = aCorbaRef;
}

template<class DataType>
DataType& 
Connection(std::string& ServiceName = DEFAULT_LLVS_SERVICE_NAME
           std::string& ServiceKind = DEFAULT_LLVS_SERVICE_KIND)
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

	CORBA::Object_ptr obj(m_CORBAReference->getObjectReference(m_ServiceName,m_ServiceKind));
	ODEBUG( "Able to get the reference for :" << m_ServiceName << " " 
			<< m_ServiceKind << "CORBAReference : "<< m_CORBAReference );

	if (CORBA::is_nil(obj))
	{
		throw("Unable to find object: " << m_ServiceName << " " << m_ServiceKind);
	}

	try
	{
		m_ServiceKind = ServiceKind;
		m_ServiceName = ServiceName;
		return DataType::_narrow(obj);
	}
	catch(...)
	{
		throw("Unable to narrow :" << m_ServiceName << " " << m_ServiceKind << "CORBAReference : "<< m_CORBAReference);
	}

}
