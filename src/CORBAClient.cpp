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

#include <llvs/tools/CORBAClient.h>
#include <llvs/tools/Debug.h>

/* Default connection parameters */
const std::string LLVClient::CORBAClient::DEFAULT_LLVS_SERVICE_NAME("LowLevelVisionSystem");
const std::string LLVClient::CORBAClient::DEFAULT_LLVS_SERVICE_KIND("VisionServer");

LLVClient::CORBAClient::CORBAClient()
  : m_ServiceName(""),
    m_ServiceKind(""),
    m_CORBAReference(NULL)
{
}

LLVClient::CORBAClient::~CORBAClient()
{
  if(m_CORBAReference)
    {
      delete m_CORBAReference;
    }
}

const std::string&
LLVClient::CORBAClient::GetServiceName()
  const
{
  return m_ServiceName;
}

const std::string& 
LLVClient::CORBAClient::GetServiceKind()
  const
{
  return m_ServiceKind;
}

LLVClient::CORBAReference*
LLVClient::CORBAClient::getCORBAReference()
  const
{
  return m_CORBAReference;
}

void
LLVClient::CORBAClient::setCORBAReference(CORBAReference* aCorbaRef)
{
  m_CORBAReference = aCorbaRef;
}

