/*
 * IntTypes.h
 *
 *  Created on: Aug 24, 2017
 *      Author: peter
 */

#ifndef TYPEDEMO_INCLUDE_TYPEDEMO_INTTYPES_H_
#define TYPEDEMO_INCLUDE_TYPEDEMO_INTTYPES_H_


#include "SampleSubsystem/Sample.h"

namespace TypeDemo
{
	using SampleSubsystem::Sample;

	class IntTypes : public Sample
	{
	public:
		IntTypes():
			Sample("IntTypes")
		{}

		void run(std::ostream& os, std::istream& is);
	};

}


#endif /* TYPEDEMO_INCLUDE_TYPEDEMO_INTTYPES_H_ */
