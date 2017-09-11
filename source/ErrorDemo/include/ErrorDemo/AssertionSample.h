/*
 * AssertionSample.h
 *
 * Author: Peter Maurer
 *
 * Dieses Beispiel zeigt den Umgang mit den Poco-eigenen assertions.
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef ERRORDEMO_SOURCE_ASSERTIONSAMPLE_H_
#define ERRORDEMO_SOURCE_ASSERTIONSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ErrorDemo {

	class AssertionSample: public SampleSubsystem::Sample
	{
	public:
		AssertionSample():
			Sample("AssertionSample")
		{}

		virtual ~AssertionSample()
		{}

		void run(std::ostream& os, std::istream& is);
	};

} /* namespace ErrorDemo */

#endif /* ERRORDEMO_SOURCE_ASSERTIONSAMPLE_H_ */
