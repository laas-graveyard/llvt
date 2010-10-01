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

#include <cassert>
#include <iostream>

#include <omniORB4/CORBA.h>
#include <omniORB4/omniORB.h>

#include "llvs/tools/corba-handler.h"

namespace LLVClient
{
  namespace
  {
    CORBA::Boolean transientExceptionHandler_(void* corbaHandler, CORBA::ULong n_retries, const CORBA::TRANSIENT& ex)
    {
      assert (corbaHandler);
      CorbaHandler* corbaHandler_ = reinterpret_cast<CorbaHandler*> (corbaHandler);
      return corbaHandler_->transientExceptionHandler(n_retries, ex);
    }

    CORBA::Boolean commFailureExceptionHandler_(void* corbaHandler, CORBA::ULong n_retries, const CORBA::COMM_FAILURE& ex)
    {
      assert (corbaHandler);
      CorbaHandler* corbaHandler_ = reinterpret_cast<CorbaHandler*> (corbaHandler);
      corbaHandler_->communicationFailureHandler(n_retries, ex);
      return false;
    }

    CORBA::Boolean systemExceptionHandler_(void* corbaHandler, CORBA::ULong n_retries, const CORBA::SystemException& ex)
    {
      assert (corbaHandler);
      CorbaHandler* corbaHandler_ = reinterpret_cast<CorbaHandler*> (corbaHandler);
      return corbaHandler_->systemExceptionHandler(n_retries, ex);
    }
  } // end of anonymous namespace.

  CorbaHandler::CorbaHandler()
  {
    using namespace omniORB;
    void* cookie = reinterpret_cast<void*>(this);
    installTransientExceptionHandler(cookie, &transientExceptionHandler_);
    installCommFailureExceptionHandler(cookie, &commFailureExceptionHandler_);
    installSystemExceptionHandler(cookie, &systemExceptionHandler_);
  }

  CorbaHandler::~CorbaHandler()
  {
    using namespace omniORB;
    installSystemExceptionHandler(0, 0);
    installCommFailureExceptionHandler(0, 0);
    installTransientExceptionHandler(0, 0);
  }

  DefaultCorbaHandler::DefaultCorbaHandler()
    : CorbaHandler()
  {}

  DefaultCorbaHandler::~DefaultCorbaHandler()
  {}

  CORBA::Boolean
  DefaultCorbaHandler::transientExceptionHandler(CORBA::ULong retries,
						 const CORBA::TRANSIENT& ex)
  {
    return false;
  }

  CORBA::Boolean
  DefaultCorbaHandler::communicationFailureHandler(CORBA::ULong n_retries,
						   const CORBA::COMM_FAILURE& ex)
  {
    return false;
  }

  CORBA::Boolean
  DefaultCorbaHandler::systemExceptionHandler(CORBA::ULong n_retries,
					      const CORBA::SystemException& ex)
  {
    return false;
  }
} // end of namespace LLVClient.
