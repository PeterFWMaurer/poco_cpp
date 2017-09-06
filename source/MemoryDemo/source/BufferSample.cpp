/*
 * BufferSample.cpp
 *
 *  Created on: Sep 6, 2017
 *      Author: peter
 */

#include "MemoryDemo/BufferSample.h"

#include "Poco/Buffer.h"
#include "Poco/Exception.h"

#include <algorithm>

namespace MemoryDemo
{
	using Poco::Buffer;
	using Poco::Exception;

	void BufferSample::run(std::ostream& os, std::istream& is)
	{
		Buffer<char> buf(100);

		std::fill(buf.begin(),buf.end(),'a');
		buf[10]='z';

		try
		{
			buf[120]='y';
		}
		catch (const Exception &exp)
		{
			os<<exp.displayText()<<std::endl;
		}

		std::copy(buf.begin(),buf.end(),std::ostreambuf_iterator<char>(os));
		os<<std::endl;



	}
}
