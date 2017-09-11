/*
 * NdcSample.cpp
 *
 * Author: Peter Maurer
 *
 * Dieses Beispiel demonstrier den Gebrauch eines Nested Diagnostic Context (NDC)
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "ErrorDemo/NdcSample.h"

#include "Poco/NestedDiagnosticContext.h"
#include "Poco/Debugger.h"
namespace ErrorDemo {

	// Die klasse NDCDemo benutzt in ihrem Konstruktor und in ihrem Destrcutor den NDC.
	class NDCDemo
	{
	public:
		NDCDemo(std::ostream& os)
			:_os(os)
		{
			// Mit dem Macro poco_ndc wird der destruktor in den NDC eingefügt
			poco_ndc(NDCDemo::NDCDemo);
			_os<<"Dumping NDC from constructor:"<<std::endl;
			Poco::NDC::current().dump(_os);
		}

		virtual ~NDCDemo()
		{
			poco_ndc(NDCDemo::~NDCDemo);
			_os<<"Dumping NDC from destructor:"<<std::endl;
			Poco::NDC::current().dump(_os);
		}

	private:
		std::ostream& _os;
	};

	void NdcSample::run(std::ostream& os, std::istream& is)
	{
		poco_ndc(NDCSample::run);
		NDCDemo myDemo(os);
		os<<std::endl;
	}

} /* namespace ErrorDemo */
