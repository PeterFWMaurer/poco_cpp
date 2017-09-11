/*
 * SampleEventInfo.h
 *
 * Author: Peter Maurer
 *
 * Beispiel für den Dateninhalt, der mit einem Event verschickt wird
 *
 * Copyright (C) 2013-2017 Maurer & Treutner GmbH & Co. KG, Leopoldhafen
 */

#ifndef EVENTDEMO_SOURCE_SAMPLEEVENTINFO_H_
#define EVENTDEMO_SOURCE_SAMPLEEVENTINFO_H_

namespace EventDemo {

	// Die Klasse SampleEvtInfo dient als Beispiel für den Dateninhalt eines Events
	//
	class SampleEvtInfo
	{
	public:

		// Unser Event erhält bei seiner Erzeugung einen Namen, der Zähler wird auf 0 gesetzt
		SampleEvtInfo(const std::string &name):
			_count(0),
			_name(name)
		{}

		virtual ~SampleEvtInfo()
		{}

		// Getter auf den Zähler
		int count()
		{
			return _count;
		}

		// Getter auf den Namen
		const std::string& name()
		{
			return _name;
		}

		// Preincrementoperator, wirkt auf den Zähler
		int operator ++()
		{
			return ++_count;
		}

	private:
		int _count;
		std::string _name;
	};

} /* namespace EventDemo */

#endif /* EVENTDEMO_SOURCE_SAMPLEEVENTINFO_H_ */
