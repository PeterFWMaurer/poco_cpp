/*
 * AssertionSample.cpp
 *
 * Author: Peter Maurer
 *
 * Dieses Beispiel zeigt den Umgang mit den Poco-eigenen Assertions.
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#include "ErrorDemo/AssertionSample.h"

#include "Poco/Exception.h"

namespace ErrorDemo
{
	using Poco::Exception;

	void AssertionSample::run(std::ostream& os, std::istream& is)
	{
		// Poco verwendet intern das Symbol _DEBUG, um eine Debug-Version zu identifizieren
		//
#		ifdef _DEBUG
		os<<"Running debug version"<<std::endl;
#		else
		os<<"Runnung release version"<<std::endl;
#		endif
		try
		{
			// Die Funktion poco_assert_dbg wirkt nur in der Debug-Version
			poco_assert_dbg(false);
			os<<"This line is reached only in release build"<<std::endl;
			// Die Funktion poco_assert wirkt immer
			poco_assert(false);
		}
		// Poco assertions werfen eine Poco::AssertionViaolationException und können deshalb in try-catch
		// Anweisungen abgefangen werden.
		catch (const Exception &exp)
		{
			os<<exp.displayText()<<std::endl;
		}

		try
		{
			void *p1=&p1;
			void *p2=0;
			// Die Funktion poco_check_ptr ist eine Funktion mit deren Hilfe überprüft werden kann, ob ein
			// gültiger Pointer vorliegt.
			poco_check_ptr(p1);
			os<<"p1 is a valid pointer"<<std::endl;
			poco_check_ptr(p2);
		}
		catch (const Exception &exp)
		{
			os<<exp.displayText()<<std::endl;
		}

		try
		{
			// Die Funktion poco_bugcheck() erzeugt wenn möglich im Debugger einen Breakpoint und unterbricht die
			// Ausführung. Sie kann optional eine Message haben.
			poco_bugcheck();
		//	poco_bugcheck_msg("My bugcheck message");
		}
		catch (const Exception &exp)
		{
			os<<exp.displayText()<<std::endl;
		}


	}

} /* namespace ErrorDemo */
