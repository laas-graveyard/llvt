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

#include <cstdio>
#include <llvs/tools/CORBAReference.h>
#include <llvs/tools/Debug.h>

LLVClient::CORBAReference::CORBAReference()
{
  m_HostName = "";
  m_PortNumber = 5005;  
}

LLVClient::CORBAReference::~CORBAReference()
{
}

bool
LLVClient::CORBAReference::InitORB()
{
  int largc = 3;
  char largv[3][1024] = { "AFPTWP","-ORBInitRef","NameService=corbaloc:iiop:localhost:5005/NameService"};
  char *lpargv[3];

  if (m_HostName.length()>0) 
    {
      sprintf(largv[2],"NameService=corbaloc:iiop:%s:%d/NameService",
	      (char *)m_HostName.c_str(), m_PortNumber);
      
      lpargv[0] = largv[0];
      lpargv[1] = largv[1];
      lpargv[2] = largv[2];


      ODEBUG("Flag 0 " << largc << " " << lpargv[0] << " " << lpargv[1] << " " << lpargv[2]);
      m_orb = CORBA::ORB_init(largc, lpargv);
    }
  else
    {
      int largc=0;
      char *lpargv[0]= {};
      m_orb = CORBA::ORB_init(largc, lpargv);
    }

  if (CORBA::is_nil(m_orb))
    return false;

  return true;
}

CORBA::Object_ptr
LLVClient::CORBAReference::getObjectReference(std::string ServerID, std::string ServerKind)
{
  CosNaming::NamingContext_var rootContext;
  
  try 
    {
      ODEBUG("Try to find the name context." );
      // Obtain a reference to the root context of the Name service:

      CORBA::Object_var obj;
      obj = m_orb->resolve_initial_references("NameService");
      
      // Narrow the reference returned.
      rootContext = CosNaming::NamingContext::_narrow(obj);
      
      if( CORBA::is_nil(rootContext) ) 
	{
	  ODEBUG3("Failed to narrow the root naming context.");
	  return CORBA::Object::_nil();
	}
    }

  catch(CORBA::ORB::InvalidName& ex) 
    {
      // This should not happen!
      ODEBUG3("Service required is invalid [does not exist].");
      return CORBA::Object::_nil();
    }

  catch(...)
    {
      ODEBUG3("CORBAReference::getObjectReference -> Unknown Error (resolve_initial_references) or (_narrow)");
      return CORBA::Object::_nil();
    }

  try {
    // Create a name object, containing the name test/context:
    CosNaming::Name name;
    name.length(1);
    
    name[0].id   = ServerID.c_str();
    name[0].kind = ServerKind.c_str();
    
    // Note on kind: The kind field is used to indicate the type
    // of the object. This is to avoid conventions such as that used
    // by files (name.type -- e.g. test.ps = postscript etc.)
    ODEBUG("Try to resolve the name.");
	
    // Resolve the name to an object reference.
    return rootContext->resolve(name);
  }
  catch(CosNaming::NamingContext::NotFound& ex) {
    // This exception is thrown if any of the components of the
    // path [contexts or the object] aren't found:
    ODEBUG3("Context not found.");
  }
  catch(CORBA::COMM_FAILURE& ex) {
    ODEBUG3("Caught system exception COMM_FAILURE -- unable to contact the "
	 << "naming service.");
  }
  catch(CORBA::BAD_PARAM)
    {
      ODEBUG3("Bad Param Try with name component ");
    }      
  
  catch(CORBA::SystemException&) 
    {
      ODEBUG3("Caught a CORBA::SystemException while using the naming service.");
    }

  ODEBUG3("Here...failed to find the Server " << ServerID);
  return CORBA::Object::_nil();
}


bool
LLVClient::CORBAReference::SetNameServiceHostname(std::string &TheHostName)
{
  m_HostName = TheHostName;
  return true;
}

bool
LLVClient::CORBAReference::SetPortNumber(unsigned short &PortNumber)
{
  m_PortNumber = PortNumber;
  return true;
}

const std::string & 
LLVClient::CORBAReference::GetNameServiceHostname() const
{
  return m_HostName;
}

const unsigned short & 
LLVClient::CORBAReference::GetPortNumber() const
{
  return m_PortNumber;
}
