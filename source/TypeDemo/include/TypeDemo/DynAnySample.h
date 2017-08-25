/*
 * DynAnySample.h
 *
 *  Created on: Aug 25, 2017
 *      Author: peter
 */

#ifndef TYPEDEMO_INCLUDE_TYPEDEMO_DYNANYSAMPLE_H_
#define TYPEDEMO_INCLUDE_TYPEDEMO_DYNANYSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace TypeDemo
{
	using SampleSubsystem::Sample;

	class DynAnySample : public Sample
	{
	public:
		DynAnySample():
			Sample("DynAnySample")
		{}

		void run(std::ostream& os, std::istream& is);
	};
}



#endif /* TYPEDEMO_INCLUDE_TYPEDEMO_DYNANYSAMPLE_H_ */
