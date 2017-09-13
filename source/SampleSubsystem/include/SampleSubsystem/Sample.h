/*
 * Sample.h
 *
 * Author: Peter Maurer
 *
 * Base class for a poco samplee
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef SAMPLESUBSYSTEM_INCLUDE_SAMPLESUBSYSTEM_SAMPLE_H_
#define SAMPLESUBSYSTEM_INCLUDE_SAMPLESUBSYSTEM_SAMPLE_H_

#include <iostream>

#include "Poco/RefCountedObject.h"

namespace SampleSubsystem
{
	using Poco::RefCountedObject;

	class Sample : public RefCountedObject
	{
	public:
		Sample(const std::string &name):
			_name(name)
		{};

		virtual ~Sample(){}

		const std::string &name()
		{
			return _name;
		}

		virtual void run(std::ostream &os, std::istream &is)=0;

	private:
		std::string _name;

	};

}



#endif /* SAMPLESUBSYSTEM_INCLUDE_SAMPLESUBSYSTEM_SAMPLE_H_ */
