/*
 * TypeDemoSub.cpp
 *
 *  Created on: Aug 24, 2017
 *      Author: peter
 */

#include "TypeDemo/TypeDemoSub.h"
#include "TypeDemo/IntTypes.h"
#include "TypeDemo/AnySample.h"
#include "TypeDemo/DynAnySample.h"
#include "TypeDemo/StringSample.h"

namespace TypeDemo
{
	TypeDemoSub::TypeDemoSub():
		SampleSub("PocoTypes")
	{
		addSample(new IntTypes());
		addSample(new AnySample());
		addSample(new DynAnySample());
		addSample(new StringSample());
	}
}
