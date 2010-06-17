/*! \brief 
 * \author Olivier Stasse
 * Copyright:  JRL, CNRS-AIST.
 * Date: 12/08/2008
 */
#ifndef _DHFSM_CORBA_REFERENCE_H_ 
#define _DHFSM_CORBA_REFERENCE_H_

#include <string>

#ifdef OMNIORB4
#include <omniORB4/CORBA.h>
#endif /* OMNIORB4 */


namespace LLVClient
{
  class CORBAReference
    {
    public:
      
       /*! \brief Default constructor */
      CORBAReference();
      
      /*! \brief Default destructor */
      ~CORBAReference();

      /*! \brief Initialize the ORB. */
      bool InitORB();

      /*! \brief Returns the reference to a CORBA object. */
      CORBA::Object_ptr getObjectReference(std::string ServerID, 
					   std::string ServerKind);

      /*! \brief setting the hostname name service. */
      bool SetNameServiceHostname(std::string &TheHostName);

      /*! \brief getting the name service hostname. */
      const std::string & GetNameServiceHostname() const;

      /*! \brief setting the port number. */
      bool SetPortNumber(unsigned short &PortNumber);
      
      /*! \brief getting the port number. */
      const unsigned short & GetPortNumber() const;

    private:

      /*! \brief Identifier to the Object Request Broker. */
      CORBA::ORB_var m_orb;

      /*! \brief Store the port number. */
      unsigned short m_PortNumber;
      
      /*! \brief Store the hostname. */
      std::string m_HostName;

    };
};

#endif /* _DHFSM_CORBA_REFERENCE_H_ */
