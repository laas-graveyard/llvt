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
