#ifndef _Strings_h_
#define _Strings_h_
/* Strings.h
 *
 * Copyright (C) 1992-2011,2015 Paul Boersma
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

#include "Strings_def.h"

#ifdef PRAAT_LIB
#include "praatlib.h"
#endif

PRAAT_LIB_EXPORT autoStrings Strings_createAsFileList (const char32 *path /* cattable */);
PRAAT_LIB_EXPORT autoStrings Strings_createAsDirectoryList (const char32 *path /* cattable */);
PRAAT_LIB_EXPORT autoStrings Strings_readFromRawTextFile (MelderFile file);
PRAAT_LIB_EXPORT void Strings_writeToRawTextFile (Strings me, MelderFile file);

PRAAT_LIB_EXPORT void Strings_randomize (Strings me);
PRAAT_LIB_EXPORT void Strings_genericize (Strings me);
PRAAT_LIB_EXPORT void Strings_nativize (Strings me);
PRAAT_LIB_EXPORT void Strings_sort (Strings me);

PRAAT_LIB_EXPORT void Strings_remove (Strings me, long position);
PRAAT_LIB_EXPORT void Strings_replace (Strings me, long position, const char32 *text);
PRAAT_LIB_EXPORT void Strings_insert (Strings me, long position, const char32 *text);

/* End of file Strings.h */
#endif
