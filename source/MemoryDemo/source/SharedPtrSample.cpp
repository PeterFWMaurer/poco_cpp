/*
 * SharedPtrSample.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: parallels
 */

#include "MemoryDemo/SharedPtrSample.h"

#include "Poco/SharedPtr.h"

#include <algorithm>
#include <iterator>

namespace MemoryDemo
{
	using Poco::SharedPtr;
	using Poco::ReleaseArrayPolicy;
	using Poco::ReferenceCounter;

	class BaseSmp
	{
	public:
		typedef SharedPtr<BaseSmp> Ptr;

		BaseSmp(){}
		virtual ~BaseSmp(){}
	};

	class InhSmp : public BaseSmp
	{
	public:
		typedef SharedPtr<InhSmp> Ptr;

		InhSmp(){}

		virtual ~InhSmp(){}
	};


	void SharedPtrSample::run(std::ostream& os, std::istream &is)
	{
		BaseSmp::Ptr pBase1(new BaseSmp);
		BaseSmp::Ptr pBase2(new InhSmp);
		InhSmp::Ptr pInh;

		pInh=pBase1.cast<InhSmp>();
		if (!pInh)
		{
			std::cout<<"Cast fails as expected"<<std::endl;
			pInh=pBase2.cast<InhSmp>();
			if (pInh)
			{
				std::cout<<"Correct cast worked as expected"<<std::endl;
			}
		}

		const int INT_ARRAY_LEN=10;
		SharedPtr<int,ReferenceCounter,ReleaseArrayPolicy<int>> pIntArray(new int[INT_ARRAY_LEN]);
		for (int i=0; i<INT_ARRAY_LEN; i++)
		{
			pIntArray[i]=i;
		}
		// The following code is commented out, since it shows what happens, if two SharedPtr try to possess
		// the same raw pointer. The application will crash...
		//
		// int * rpI=new int(42);
		// SharedPtr<int>pI1(rpI);
		// SharedPtr<int>pI2(rpI);
	}

} /* namespace MemoryDemo */
