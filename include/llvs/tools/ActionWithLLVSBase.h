/*! ----------------------------------------------------
 *  Copyright 2010, CNRS-AIST JRL
 * 
 *  \brief  LLVT - Simple client interface
 *  \author Clement Petit
 * ---------------------------------------------------- */

#ifndef _DHFSM_ACTION_WITH_LLVS_BASE_H_ 
#define _DHFSM_ACTION_WITH_LLVS_BASE_H_ 

#include "CORBAReference.h"

namespace LLVClient
{
	class ActionWithLLVSBase : public CORBAClient
	{
		public:

			/*! \name Static variables defining the set of actions performed by this class.
			  @{
			  */
			/*! Action is by default undefined */ 
			static const int ACTION_UNDEFINED = -1;
			/*! @} */

			/*! Default constructor */
			ActionWithLLVSBase();

			/*! Default destructor. */
			~ActionWithLLVSBase();

			/*! \name Methods specific to the realization of the actions on LLVS.
				@{
				*/
			/*! \brief Initialize the connection to the component. */
			virtual bool Initialize() = 0;

			/*! \brief Send the action request to the server */
			virtual bool ExecuteAction() = 0;

			/*! \brief Cleanup: close the connection to the component. */
			virtual void CleanUp() = 0;
		
			/*! \brief Set the action that will be performed at the next ExecuteAction() */
			void SetAction(int anAction);
			/*! @} */

		protected:
			/*! \brief Action to be perform by the instance of this class. 
				Set to -1 by default (does nothing ).
				*/
			int m_InstanceAction;
	};
}

#endif //!_DHFSM_ACTION_WITH_LLVS_BASE_H_
