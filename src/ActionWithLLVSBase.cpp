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
