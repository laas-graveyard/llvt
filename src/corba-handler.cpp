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
