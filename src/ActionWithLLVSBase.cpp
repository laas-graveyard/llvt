/*! ----------------------------------------------------
 *  Copyright 2010, CNRS-AIST JRL
 * 
 *  \brief  LLVT - Simple client interface
 *  \author Clement Petit
 * ---------------------------------------------------- */

#include <llvs/tools/ActionWithLLVSBase.h>


/* ---------------------------------------------------
 * Initialization/Destruction
 * --------------------------------------------------- */

LLVClient::ActionWithLLVSBase::ActionWithLLVSBase()
	:m_InstanceAction(ACTION_UNDEFINED)
{
}

LLVClient::ActionWithLLVSBase::~ActionWithLLVSBase()
{
}

/* ---------------------------------------------------
 * Action interface
 * --------------------------------------------------- */

void
LLVClient::ActionWithLLVSBase::SetAction(int anAction)
{
  m_InstanceAction = anAction;
}
