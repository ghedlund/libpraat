#ifndef _Simple_h_
#define _Simple_h_
/* Simple.h
 *
 * Copyright (C) 1992-2012,2015 Paul Boersma
 *
 * This code is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This code is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this work. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Data.h"

#include "praatlib.h"

#include "Simple_def.h"

PRAAT_LIB_EXPORT autoSimpleInt SimpleInt_create (int number);
PRAAT_LIB_EXPORT autoSimpleLong SimpleLong_create (long number);
PRAAT_LIB_EXPORT autoSimpleDouble SimpleDouble_create (double number);
PRAAT_LIB_EXPORT autoSimpleString SimpleString_create (const char32 *string);

PRAAT_LIB_EXPORT int SimpleString_compare (SimpleString me, SimpleString thee) noexcept;

/* End of file Simple.h */
#endif
