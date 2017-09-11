/*
 * ExceptionSample.h
 *
 * Author: Peter Maurer
 *
 * Dieses Beispiel zeigt den Umgang mit Poco::Exception und der entsprechenden
 * Vererbungshierarchie
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef ERRORDEMO_SOURCE_EXCEPTIONSAMPLE_H_
#define ERRORDEMO_SOURCE_EXCEPTIONSAMPLE_H_

#include "SampleSubsystem/Sample.h"

namespace ErrorDemo
{
	using SampleSubsystem::Sample;

	class ExceptionSample: public Sample
	{
	public:
		ExceptionSample():
			Sample("Exception Sample")
		{}

		virtual ~ExceptionSample()
		{}

		void run(std::ostream &os, std::istream &is);
	};

} /* namespace ErrorDemo */

#endif /* ERRORDEMO_SOURCE_EXCEPTIONSAMPLE_H_ */
