#ifndef _Formant_h_
#define _Formant_h_
/* Formant.h
 *
 * Copyright (C) 1992-2005,2007-2009,2011,2012,2014-2019 Paul Boersma
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

#include "Matrix.h"
#include "Table.h"
Thing_declare (Interpreter);

#include "praatlib.h"

#include "Formant_enums.h"
#include "Formant_def.h"

PRAAT_LIB_EXPORT autoFormant Formant_create (double tmin, double tmax, integer nt, double dt, double t1, integer maximumNumberOfFormants);
/*
	Function:
		return a new instance of Formant.
	Preconditions:
		nt >= 1;
		dt > 0.0;
		maxnFormants >= 1;
	Postconditions:
		my xmin == tmin;
		my xmax == tmax;
		my nx == nt;
		my dx == dt;
		my x1 == t1;
		my maximumNumberOfPairs == maxnFormants;
		my frames [1..nt]. intensity == 0.0;
		my frames [1..nt]. numberOfPairs == 0;
		my frames [1..nt]. formants [1..maxnFormants] = 0.0;
		my frames [1..nt]. bandwidths [1..maxnFormants] = 0.0;
*/
PRAAT_LIB_EXPORT integer Formant_getMinNumFormants (Formant me);
PRAAT_LIB_EXPORT integer Formant_getMaxNumFormants (Formant me);

PRAAT_LIB_EXPORT double Formant_getValueAtTime (Formant me, integer formantNumber, double time, kFormant_unit unit);
PRAAT_LIB_EXPORT double Formant_getBandwidthAtTime (Formant me, integer formantNumber, double time, kFormant_unit unit);

PRAAT_LIB_EXPORT void Formant_getExtrema (Formant me, integer formantNumber, double tmin, double tmax, double *fmin, double *fmax);
PRAAT_LIB_EXPORT void Formant_getMinimumAndTime (Formant me, integer formantNumber, double tmin, double tmax, kFormant_unit unit, int interpolate,
	double *return_minimum, double *return_timeOfMinimum);
PRAAT_LIB_EXPORT void Formant_getMaximumAndTime (Formant me, integer formantNumber, double tmin, double tmax, kFormant_unit unit, int interpolate,
	double *return_maximum, double *return_timeOfMaximum);
PRAAT_LIB_EXPORT double Formant_getMinimum (Formant me, integer formantNumber, double tmin, double tmax, kFormant_unit unit, int interpolate);
PRAAT_LIB_EXPORT double Formant_getMaximum (Formant me, integer formantNumber, double tmin, double tmax, kFormant_unit unit, int interpolate);
PRAAT_LIB_EXPORT double Formant_getTimeOfMaximum (Formant me, integer formantNumber, double tmin, double tmax, kFormant_unit unit, int interpolate);
PRAAT_LIB_EXPORT double Formant_getTimeOfMinimum (Formant me, integer formantNumber, double tmin, double tmax, kFormant_unit unit, int interpolate);

PRAAT_LIB_EXPORT double Formant_getQuantile (Formant me, integer formantNumber, double quantile, double tmin, double tmax, kFormant_unit unit);
PRAAT_LIB_EXPORT double Formant_getQuantileOfBandwidth (Formant me, integer formantNumber, double quantile, double tmin, double tmax, kFormant_unit unit);
PRAAT_LIB_EXPORT double Formant_getMean (Formant me, integer formantNumber, double tmin, double tmax, kFormant_unit unit);
PRAAT_LIB_EXPORT double Formant_getStandardDeviation (Formant me, integer formantNumber, double tmin, double tmax, kFormant_unit unit);

PRAAT_LIB_EXPORT void Formant_sort (Formant me);

void Formant_drawTracks (Formant me, Graphics graphics, double tmin, double tmax, double fmax, bool garnish);
void Formant_drawSpeckles_inside (Formant me, Graphics graphics, double tmin, double tmax, double fmin, double fmax,
	double suppress_dB);
void Formant_drawSpeckles (Formant me, Graphics graphics, double tmin, double tmax, double fmax,
	double suppress_dB, bool garnish);
void Formant_scatterPlot (Formant me, Graphics graphics, double tmin, double tmax,
	integer iformant1, double fmin1, double fmax1, integer iformant2, double fmin2, double fmax2,
	double size_mm, conststring32 mark, bool garnish);

PRAAT_LIB_EXPORT autoMatrix Formant_to_Matrix (Formant me, integer iformant);
PRAAT_LIB_EXPORT autoMatrix Formant_to_Matrix_bandwidths (Formant me, integer iformant);
PRAAT_LIB_EXPORT void Formant_formula_frequencies (Formant me, conststring32 formula, Interpreter interpreter);
PRAAT_LIB_EXPORT void Formant_formula_bandwidths (Formant me, conststring32 formula, Interpreter interpreter);

PRAAT_LIB_EXPORT autoFormant Formant_tracker (Formant me, integer numberOfTracks,
	double refF1, double refF2, double refF3, double refF4, double refF5,
	double dfCost,   // per kHz
	double bfCost, double octaveJumpCost);

PRAAT_LIB_EXPORT autoTable Formant_downto_Table (Formant me, bool includeFrameNumbers,
	bool includeTimes, integer timeDecimals,
	bool includeIntensity, integer intensityDecimals,
	bool includeNumberOfFormants, integer frequencyDecimals,
	bool includeBandwidths);
void Formant_list (Formant me, bool includeFrameNumbers,
	bool includeTimes, integer timeDecimals,
	bool includeIntensity, integer intensityDecimals,
	bool includeNumberOfFormants, integer frequencyDecimals,
	bool includeBandwidths);

#ifdef PRAAT_LIB
PRAAT_LIB_EXPORT double Formant_getValueAtSample(Formant me, integer isample, long which, int units);
PRAAT_LIB_EXPORT double Formant_getIntensityAtSample(Formant me, integer iframe);
#endif

/* End of file Formant.h */
#endif
