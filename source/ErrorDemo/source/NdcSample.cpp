/*
 * NdcSample.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: peter
 */

#include "ErrorDemo/NdcSample.h"

#include "Poco/NestedDiagnosticContext.h"
#include "Poco/Debugger.h"
namespace ErrorDemo {

	class NDCDemo
	{
	public:
		NDCDemo(std::ostream& os)
			:_os(os)
		{
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
