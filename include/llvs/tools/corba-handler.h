// -*- c++-mode -*-
#ifndef LLVT_CORBA_HANDLER_H
# define LLVT_CORBA_HANDLER_H
# include <omniORB4/CORBA.h>

namespace LLVClient
{
  /// \brief CORBA error management class.
  ///
  /// This class provides a generic way to handle CORBA exceptions.
  ///
  /// If this class is instantiated, its handlers methods will be
  /// instantiated in case of errors. When the instance is destructed,
  /// the hooks are removed automatically.
  ///
  /// The handlers can then return true if omniORB should retry the
  /// failed action or return false if it should abandon and really
  /// throw an exception.
  ///
  /// More information are available in the omniORB documentation
  /// in section ``4.7  System Exception Handlers''.
  /// See online documentation at: http://omniorb.sourceforge.net
  ///
  /// Hint: this mechanism can be used to log CORBA errors, but
  /// the use of omniORB client side options should be prefered
  /// (like traceLevel or traceExceptions).
  ///
  /// \warning Only one hook per error type can be registered in
  /// omniORB. It means that if this class is instantiated several
  /// times, the hooks will be overwriten. Please, instantiate this
  /// class only once.
  class CorbaHandler
  {
  public:
    /// \brief Install handlers.
    explicit CorbaHandler();

    /// \brief Remove handlers.
    ~CorbaHandler();

    /// \brief Handler for transient exceptions.
    virtual CORBA::Boolean transientExceptionHandler
    (CORBA::ULong retries, const CORBA::TRANSIENT& ex) = 0;

    /// \brief Handler for communication failures.
    virtual CORBA::Boolean communicationFailureHandler
    (CORBA::ULong n_retries, const CORBA::COMM_FAILURE& ex) = 0;

    /// \brief Handler for other exceptions.
    virtual CORBA::Boolean systemExceptionHandler
    (CORBA::ULong n_retries, const CORBA::SystemException& ex) = 0;
  };

  /// \brief The default handler which implements omniORB default
  /// behavior.
  class DefaultCorbaHandler : public CorbaHandler
  {
  public:
    explicit DefaultCorbaHandler();
    ~DefaultCorbaHandler();

    virtual CORBA::Boolean transientExceptionHandler
    (CORBA::ULong retries, const CORBA::TRANSIENT& ex);

    virtual CORBA::Boolean communicationFailureHandler
    (CORBA::ULong n_retries, const CORBA::COMM_FAILURE& ex);
    virtual CORBA::Boolean systemExceptionHandler
    (CORBA::ULong n_retries, const CORBA::SystemException& ex);
  };

} // end of namespace LLVClient.

#endif // !LLVT_CORBA_HANDLER_H
