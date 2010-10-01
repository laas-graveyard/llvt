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
