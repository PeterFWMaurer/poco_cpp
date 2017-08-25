/*
 * StringSample.h
 *
 *  Created on: Aug 25, 2017
 *      Author: peter
 */

#include "SampleSubsystem/Sample.h"

namespace TypeDemo
{
	using SampleSubsystem::Sample;

	class StringSample : public Sample
	{
	public:
		StringSample():
			Sample("StringSample")
		{}

		void run(std::ostream &os, std::istream &is);
	};
}


