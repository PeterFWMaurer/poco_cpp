/*
 * ErrorDemoSub.h
 *
 * Author: Peter Maurer
 *
 * Klasse zum Aufruf von Beispielen zum Thema Error und Exception
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef ERRORDEMO_SOURCE_ERRORDEMOSUB_H_
#define ERRORDEMO_SOURCE_ERRORDEMOSUB_H_

#include "SampleSubsystem/SampleSub.h"

namespace ErrorDemo {

	using SampleSubsystem::SampleSub;

	class ErrorDemoSub: public SampleSub
	{
	public:
		ErrorDemoSub();

		virtual ~ErrorDemoSub()
		{}
	};

} /* namespace ErrorDemo */

#endif /* ERRORDEMO_SOURCE_ERRORDEMOSUB_H_ */
