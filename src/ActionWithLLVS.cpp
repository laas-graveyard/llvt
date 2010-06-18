/*! ----------------------------------------------------
 *  Copyright 2010, CNRS-AIST JRL
 * 
 *  \brief  LLVT - Simple client interface
 *  \author Clement Petit
 * ---------------------------------------------------- */

#include "ActionWithLLVSBase.h"


ActionWithLLVSBase::ActionWithLLVSBase()
	:m_InstanceAction(ACTION_UNDEFINED)
{
}

ActionWithLLVSBase::~ActionWithLLVSBase()
{
}

void ActionWithLLVSBase::SetAction(int anAction)
{
  m_InstanceAction = anAction;
}
