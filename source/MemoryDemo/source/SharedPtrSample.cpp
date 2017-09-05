/*
 * SharedPtrSample.cpp
 *
 *  Created on: Sep 5, 2017
 *      Author: parallels
 */

#include "MemoryDemo/SharedPtrSample.h"

#include "Poco/SharedPtr.h"

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

		SharedPtr<BaseSmp,ReferenceCounter,ReleaseArrayPolicy<BaseSmp>> pBaseArray(new BaseSmp[10]);
		pBaseArray[1]=pBaseArray[2];

	}

} /* namespace MemoryDemo */
