/*
 * ExpireDelegateSample.cpp
 *
 *  Created on: Sep 7, 2017
 *      Author: peter
 */

#include "EventDemo/ExpireDelegateSample.h"

#include "EventDemo/SampleEventInfo.h"
#include "EventDemo/SampleEventSource.h"
#include "EventDemo/SampleEventTarget.h"

#include "Poco/Delegate.h"
#include "Poco/Expire.h"
#include "Poco/Thread.h"

namespace EventDemo
{
	using Poco::Expire;
	using Poco::Thread;

	void ExpireDelegateSample::run(std::ostream &os, std::istream &is)
	{
		SampleEventSource mySource;
		SampleEventTarget myTarget("target",os);
		SampleEvtInfo evtData("My Event");

		mySource.event += Expire<SampleEvtInfo>(Poco::delegate(&myTarget,&SampleEventTarget::onSampleEvent),1000);
		std::cout<<"Firing Event:"<<std::endl;
		mySource.fireSampleEvent(evtData);
		std::cout<<"Waiting before firing again..."<<std::endl;
		Thread::sleep(2000);
		mySource.fireSampleEvent(evtData);
		os<<"Fired again after 2000ms sleep!"<<std::endl;
	}
}
