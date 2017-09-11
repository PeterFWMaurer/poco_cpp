/*
 * BufferSample.cpp
 *
 * Author: Peter Maurer
 *
 * Beispiel für die Verwendung von Poco::Buffer
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
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
		// Buffer der Länge 100 erzeugen und füllen
		Buffer<char> buf(100);
		std::fill(buf.begin(),buf.end(),'a');
		buf[10]='z';

		// Buffer prüft Bereichsüberschreitungen
		try
		{
			buf[120]='y';
		}
		catch (const Exception &exp)
		{
			os<<exp.displayText()<<std::endl;
		}

		// Buffer können in C++ Algorithmen verwendet werden
		std::copy(buf.begin(),buf.end(),std::ostreambuf_iterator<char>(os));
		os<<std::endl;



	}
}
