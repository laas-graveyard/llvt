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

#ifndef _ACTION_WITH_LLVS_BASE_H
#define _ACTION_WITH_LLVS_BASE_H

#include <llvs/tools/CORBAClient.h>

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

#endif //!_ACTION_WITH_LLVS_BASE_H
