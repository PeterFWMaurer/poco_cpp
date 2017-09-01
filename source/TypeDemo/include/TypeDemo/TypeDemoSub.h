/*
 * TypeDemoSub.h
 *
 *  Created on: Aug 24, 2017
 *      Author: peter
 */

#ifndef TYPEDEMO_INCLUDE_TYPEDEMO_TYPEDEMOSUB_H_
#define TYPEDEMO_INCLUDE_TYPEDEMO_TYPEDEMOSUB_H_

#include "SampleSubsystem/SampleSub.h"


namespace TypeDemo
{
	using SampleSubsystem::SampleSub;

	class TypeDemoSub : public SampleSub
	{
	public:
		TypeDemoSub();

		virtual ~TypeDemoSub(){}
	};

}



#endif /* TYPEDEMO_INCLUDE_TYPEDEMO_TYPEDEMOSUB_H_ */
