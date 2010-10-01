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

#ifndef _DEBUG_HEADER_LLVS_H_

#include <iostream>

#define ODEBUG2(x)
#define ODEBUG3(x) std::cerr << __FILE__ << ": l" << __LINE__ << ": " << x << std::endl
#define ODEBUG3_CONT(x) cerr << x

#ifdef _DEBUG_MODE_ON_
 #define ODEBUG(x) std::cerr << __FILE__ << ": l" << __LINE__ << ": " << x << std::endl
 #define ODEBUG_CONT(x) std::cerr << __FILE__ << ": l" << __LINE__ << ": " << x << std::endl
#else
 #define ODEBUG(x)
 #define ODEBUG_CONT(x)
#endif

#endif /* _DEBUG_HEADER_LLVS_H_ */
